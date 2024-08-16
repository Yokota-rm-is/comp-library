#pragma once
#include "../base.cpp"

enum {
    NOTFOUND = 0xFFFFFFFFFFFFFFFFLLU
};

struct DynamicBitVector {
    using ull = unsigned long long;
    using ll = long long;

    struct Node {
        // internal nodeのときに使用
        ull size_l;       // 左の子の部分木のもつbitの数
        ull ones_l;      // 左の子の部分木のもつ1の数
        Node *left = 0, *right = 0;
        ll balance;    // 右の子の高さ - 左の子の高さ．+なら右の子の方が高い，-なら左の子の方が高い

        // leafのときに使用
        ull bits;       // bit
        ull bits_size;  // bitのサイズ(debug用)

        bool is_leaf;

        Node(ull bits, ull bits_size, bool is_leaf) : size_l(0), ones_l(0), bits(bits), bits_size(bits_size), is_leaf(is_leaf), left(nullptr), right(nullptr), balance(0) {}
    };

    using S = Node;
    using pS = unique_ptr<S>;

    pS pNIL;
    S *NIL = nullptr;
    vector<pS> A;

    Node *root;
    ull N;  // 全体のbitの数
    ull zeros, ones;    // 全体の0の数，1の数
    const ull bits_size_limit = 32;   // 各ノードが管理するbitの長さ制限．2 * bits_size_limit以上になったらノードを分割し， 1/2*bits_size_limit以下になったらノードを結合する

    DynamicBitVector() {
        init();
    }
    
    DynamicBitVector(ull n) {
        init();
        rep(i, n) push_back(0);
    }

    void init() {
        N = 0;
        ones = 0;
        zeros = 0;

        pNIL = make_unique<S>(0, 0, true);
        NIL = pNIL.get();
        NIL->left = NIL->right = NIL;
        root = NIL;
    }

    // B[pos]
    ull access(ull pos) {
        assert(pos < N);

        return access(root, pos);
    }

    // B[0, pos)にある指定されたbitの数
    ull rank(ull bit, ull pos) {
        assert(bit == 0 or bit == 1);
        assert(pos <= N);

        if (bit == 1) return rank1(root, pos, 0);
        else return pos - rank1(root, pos, 0);
    }

    // k番目(1-indexed)の指定されたbitの位置(0-indexed)
    ull select(ull bit, ull k) {
        assert(bit == 0 or bit == 1);
        assert(k > 0);

        if (bit == 0 and k > zeros) return NOTFOUND;
        if (bit == 1 and k > ones) return NOTFOUND;

        if (bit == 1) return select1(root, 0, k);
        else return select0(root, 0, k);
    }

    // pos(0-indexed)にbitを挿入する
    void insert(ull pos, ull bit) {
        assert(bit == 0 or bit == 1);
        assert(pos <= N);  // 現在もってるbitsの末尾には挿入できる

        if (N == 0) {
            pS pnx = make_unique<S>(*NIL);
            S* nx = pnx.get();
            nx->bits = bit;
            nx->bits_size = 1;
            nx->is_leaf = true;
            A.emplace_back(move(pnx));

            root = nx;
        } 
        else insert(root, nullptr, bit, pos, N);
        
        N++;
        ones += (bit == 1);
        zeros += (bit == 0);
    }

    // 末尾にbitを追加する
    void push_back(ull bit) {
        assert(bit == 0 or bit == 1);

        insert(N, bit);
    }

    // pos(0-indexed)を削除する
    void erase(ull pos) {
        assert(pos < N);

        ull bit = remove(root, nullptr, pos, N, 0, true).first;
        N--;
        ones -= (bit == 1);
        zeros -= (bit == 0);
    }

    // pos(0-indexed)にbitをセットする
    void update(ull pos, ull bit) {
        assert(bit == 0 or bit == 1);
        assert(pos < N);

        if (bit == 1) bitset(pos);
        else bitclear(pos);
    }

    // pos(0-indexed)のbitを1にする
    void bitset(ull pos) {
        assert(pos < N);

        bool flip = bitset(root, pos);
        ones += flip;
        zeros -= flip;
    }

    // pos(0-indexed)のbitを0にする
    void bitclear(ull pos) {
        assert(pos < N);

        bool flip = bitclear(root, pos);
        ones -= flip;
        zeros += flip;
    }

private:
    ull access(const Node *node, ull pos) {
        if (node->is_leaf) {
            assert(pos <= 2 * bits_size_limit);
            return (node->bits >> pos) & (ull)1;
        }

        if (pos < node->size_l) return access(node->left, pos);
        else return access(node->right, pos - node->size_l);
    }

    ull rank1(const Node *node, ull pos, ull num_ones) {
        if (node->is_leaf) {
            assert(node->bits_size >= pos);
            const ull mask = ((ull)1 << pos) - 1;
            return num_ones + bit_count(node->bits & mask);
        }

        if (pos < node->size_l) return rank1(node->left, pos, num_ones);
        else return rank1(node->right, pos - node->size_l, num_ones + node->ones_l);
    }

    ull select1(const Node *node, ull pos, ull k) {
        if (node->is_leaf) {
            return pos + select_in_block(node->bits, k);
        }

        if (k <= node->ones_l) return select1(node->left, pos, k);
        else return select1(node->right, pos + node->size_l, k - node->ones_l);
    }

    ull select0(const Node *node, ull pos, ull k) {
        if (node->is_leaf) {
            return pos + select_in_block(~node->bits, k);
        }

        if (k <= (node->size_l - node->ones_l)) return select0(node->left, pos, k);
        else return select0(node->right, pos + node->size_l, k - (node->size_l - node->ones_l));
    }

    // bits(64bit)のrank番目(0-indexed)の1の数
    ull select_in_block(ull bits, ull rank) {
        const ull x1 = bits - ((bits & 0xAAAAAAAAAAAAAAAALLU) >> (ull)1);
        const ull x2 = (x1 & 0x3333333333333333LLU) + ((x1 >> (ull)2) & 0x3333333333333333LLU);
        const ull x3 = (x2 + (x2 >> (ull)4)) & 0x0F0F0F0F0F0F0F0FLLU;

        ull pos = 0;
        for (;; pos += 8) {
            const ull rank_next = (x3 >> pos) & 0xFFLLU;
            if (rank <= rank_next) break;
            rank -= rank_next;
        }

        const ull v2 = (x2 >> pos) & 0xFLLU;
        if (rank > v2) {
            rank -= v2;
            pos += 4;
        }

        const ull v1 = (x1 >> pos) & 0x3LLU;
        if (rank > v1) {
            rank -= v1;
            pos += 2;
        }

        const ull v0  = (bits >> pos) & 0x1LLU;
        if (v0 < rank) pos += 1;

        return pos;
    }

    // nodeから辿れる葉のpos番目にbitをいれる(葉のbitの長さはlen)
    // 高さの変化を返す
    ll insert(Node *node, Node *parent, ull bit, ull pos, ull len) {
        assert(bit == 0 or bit == 1);
        if (node->is_leaf) {
            assert(pos <= 2 * bits_size_limit);

            // posより左をとりだす
            const ull up_mask = (((ull)1 << (len - pos)) - 1) << pos;
            const ull up = (node->bits & up_mask);

            // posより右をとりだす
            const ull down_mask = ((ull)1 << pos) - 1;
            const ull down = node->bits & down_mask;

            node->bits = (up << (ull)1) | (bit << pos) | down;
            node->bits_size++;
            assert(node->bits_size == len + 1);

            // bitsのサイズが大きくなったので分割する
            if (len + 1 >= 2 * bits_size_limit) {
                split_node(node, len + 1); // 引数のlenはinsert後の長さなので+1する
                return 1;
            }

            return 0;
        }

        if (pos < node->size_l) {
            const ll diff = insert(node->left, node, bit, pos, node->size_l);
            node->size_l += 1;
            node->ones_l += (bit == 1);
            return achieve_balance(parent, node, diff, 0);
        } else {
            const ll diff = insert(node->right, node, bit, pos - node->size_l, len - node->size_l);
            return achieve_balance(parent, node, 0, diff);
        }
    }

    // nodeのpos番目のbitを削除する
    // 消したbitと高さの変化のpairを返す
    pair<ull, ll> remove(Node *node, Node *parent, ull pos, ull len, ull num_ones, bool allow_under_flow) {
        if (node->is_leaf) {
            // 消すとunder flowになるので消さない
            if (node != root and len <= bits_size_limit / 2 and not allow_under_flow) {
                return make_pair(NOTFOUND, 0);
            }

            assert(pos <= 2 * bits_size_limit);
            assert(pos < len);
            const ull bit = (node->bits >> pos) & (ull)1;

            // posより左をとりだす(posを含まないようにする)
            const ull up_mask = (((ull)1 << (len - pos - 1)) - 1) << (pos + 1);
            const ull up = (node->bits & up_mask);

            // posより右をとりだす
            const ull down_mask = ((ull)1 << pos) - 1;
            const ull down = node->bits & down_mask;

            node->bits = (up >> (ull)1) | down;
            node->bits_size--;
            assert(node->bits_size == len - 1);

            return make_pair(bit, 0);
        }

        if (pos < node->size_l) {
            const auto bit_diff = remove(node->left, node, pos, node->size_l, node->ones_l, allow_under_flow);
            if (bit_diff.first == NOTFOUND) {
                return bit_diff;
            }

            node->ones_l -= (bit_diff.first == 1);
            // 左の子の葉のbitを1つ消したのでunder flowが発生している
            if (node->size_l == bits_size_limit / 2) {
                const auto b_d = remove(node->right, node, 0, len - bits_size_limit / 2, 0, false);  // 右の葉の先頭bitを削る

                // 右の葉もunder flowになって消せない場合は2つの葉を統合する
                if (b_d.first == NOTFOUND) {
                    assert(node->left->is_leaf);
                    assert(node->left->bits_size == bits_size_limit / 2 - 1);
                    // 右の子から辿れる一番左の葉の先頭にleftのbitsを追加する
                    merge_nodes(node->right, 0, len - bits_size_limit / 2, node->left->bits, bits_size_limit / 2 - 1, node->ones_l, true);
                    replace(parent, node, node->right);    // parentの子のnodeをnode->rightに置き換える
                    return make_pair(bit_diff.first, -1);
                }

                // 右の葉からとった先頭bitを左の葉の末尾にいれる
                assert(node->left->bits_size == bits_size_limit / 2 - 1);
                insert(node->left, node, b_d.first, bits_size_limit / 2 - 1, bits_size_limit / 2 - 1);
                node->ones_l += (b_d.first == 1);
            }
            else {
                node->size_l -= 1;
            }

            const ll diff = achieve_balance(parent, node, bit_diff.second, 0);
            return make_pair(bit_diff.first, diff);

        } 
        else {
            const auto bit_diff = remove(node->right, node, pos - node->size_l, len - node->size_l, num_ones - node->ones_l, allow_under_flow);
            if (bit_diff.first == NOTFOUND) {
                return bit_diff;
            }

            num_ones -= (bit_diff.first == 1);
            // 右の子の葉のbitを1つ消したのでunder flowが発生する
            if ((len - node->size_l) == bits_size_limit / 2) {
                const auto b_d = remove(node->left, node, node->size_l - 1, node->size_l, 0, false);    // 左の葉の末尾をbitを削る

                // 左の葉もunder flowになって消せない場合は2つの葉を統合する
                if (b_d.first == NOTFOUND) {
                    assert(node->right->is_leaf);
                    assert(node->right->bits_size == bits_size_limit / 2 - 1);
                    // 左の子から辿れる一番右の葉の末尾にleftのbitsを追加する
                    merge_nodes(node->left, node->size_l, node->size_l, node->right->bits, bits_size_limit / 2 - 1, num_ones - node->ones_l, false);
                    replace(parent, node, node->left);    // parentの子のnodeをnode->leftに置き換える
                    return make_pair(bit_diff.first, -1);
                }

                // 左の葉からとった最後尾bitを右の葉の先頭にいれる
                insert(node->right, node, b_d.first, 0, bits_size_limit / 2 - 1);
                node->size_l -= 1;
                node->ones_l -= (b_d.first == 1);
            }

            const ll diff = achieve_balance(parent, node, 0, bit_diff.second);
            return make_pair(bit_diff.first, diff);
        }
    }

    // pos番目のbitを1にする．0から1への反転が起きたらtrueを返す
    bool bitset(Node *node, ull pos) {
        if (node->is_leaf) {
            assert(pos <= 2 * bits_size_limit);
            const ull bit = (node->bits >> pos) & 1;
            if (bit == 1) {
                return false;
            }

            node->bits |= ((ull)1 << pos);
            return true;
        }

        if (pos < node->size_l) {
            bool flip = bitset(node->left, pos);
            node->ones_l += flip;
            return flip;
        } 
        else {
            return bitset(node->right, pos - node->size_l);
        }
    }

    // pos番目のbitを0にする．1から0への反転が起きたらtrueを返す
    bool bitclear(Node *node, ull pos) {
        if (node->is_leaf) {
            assert(pos <= 2 * bits_size_limit);

            const ull bit = (node->bits >> pos) & 1;
            if (bit == 0) {
                return false;
            }
            node->bits &= ~((ull)1 << pos);
            return true;
        }

        if (pos < node->size_l) {
            const bool flip = bitclear(node->left, pos);
            node->ones_l -= flip;
            return flip;
        } 
        else {
            return bitclear(node->right, pos - node->size_l);
        }
    }

    // nodeを2つの葉に分割する
    void split_node(Node *node, ull len) {
        assert(node->is_leaf);
        assert(node->bits_size == len);

        // 左の葉
        const ull left_size = len / 2;
        const ull left_bits = node->bits & (((ull)1 << left_size) - 1);
        {
            pS pnx = make_unique<S>(*NIL);
            S* nx = pnx.get();
            nx->bits = left_bits;
            nx->bits_size = left_size;
            nx->is_leaf = true;
            A.emplace_back(move(pnx));
            node->left = nx;
        }

        // 右の葉
        const ull right_size = len - left_size;
        const ull right_bits = node->bits >> left_size;
        {
            pS pnx = make_unique<S>(*NIL);
            S* nx = pnx.get();
            nx->bits = right_bits;
            nx->bits_size = right_size;
            nx->is_leaf = true;
            A.emplace_back(move(pnx));
            node->right = nx;
        }

        // nodeを内部ノードにする
        node->is_leaf = false;
        node->size_l = left_size;
        node->ones_l = bit_count(left_bits);
        node->bits = 0;
        node->bits_size = 0;
    }

    // nodeから辿れる葉のpos番目にbitsを格納する
    void merge_nodes(Node *node, ull pos, ull len, ull bits, ull s, ull num_ones, bool left) {
        if (node->is_leaf) {
            if (left) {
                node->bits = (node->bits << s) | bits;
            }
            else {
                assert(len == node->bits_size);
                node->bits = node->bits | (bits << len);
            }
            node->bits_size += s;
            return;
        }

        if (pos < node->size_l) {
            node->size_l += s;
            node->ones_l += num_ones;
            merge_nodes(node->left, pos, node->size_l, bits, s, num_ones, left);
        }
        else {
            merge_nodes(node->right, pos, len - node->size_l, bits, s, num_ones, left);
        }
    }

    // nodeの左の高さがleftHeightDiffだけ変わり，右の高さがrightHeightDiffだけ変わったときにnodeを中心に回転させる
    // 高さの変化を返す
    ll achieve_balance(Node *parent, Node *node, ll leftHeightDiff, ll rightHeightDiff) {
        assert(-1 <= node->balance and node->balance <= 1);
        assert(-1 <= leftHeightDiff and leftHeightDiff <= 1);
        assert(-1 <= rightHeightDiff and rightHeightDiff <= 1);

        if (leftHeightDiff == 0 and rightHeightDiff == 0) {
            return 0;
        }

        ll heightDiff = 0;
        // 左が高いときに，左が高くなる or 右が高いときに右が高くなる
        if ((node->balance <= 0 and leftHeightDiff > 0) or (node->balance >= 0 and rightHeightDiff > 0)) {
            ++heightDiff;
        }
        // 左が高いときに左が低くなる or 右が高いときに右が低くなる
        if ((node->balance < 0 and leftHeightDiff < 0) or (node->balance > 0 and rightHeightDiff < 0)) {
            --heightDiff;
        }

        node->balance += -leftHeightDiff + rightHeightDiff;
        assert(-2 <= node->balance and node->balance <= 2);

        // 左が2高い
        if (node->balance == -2) {
            assert(-1 <= node->left->balance and node->left->balance <= 1);
            if (node->left->balance != 0) {
                heightDiff--;
            }

            if (node->left->balance == 1) {
                replace(node, node->left, rotate_left(node->left));
            }
            replace(parent, node, rotate_right(node));
        }
            // 右が2高い
        else if (node->balance == 2) {
            assert(-1 <= node->right->balance and node->right->balance <= 1);
            if (node->right->balance != 0) {
                heightDiff--;
            }

            if (node->right->balance == -1) {
                replace(node, node->right, rotate_right(node->right));
            }
            replace(parent, node, rotate_left(node));
        }

        return heightDiff;
    }

    // node Bを中心に左回転する．新しい親を返す
    Node *rotate_left(Node *B) {
        Node *D = B->right;

        const ll heightC = 0;
        const ll heightE = heightC + D->balance;
        const ll heightA = max(heightC, heightE) + 1 - B->balance;

        B->right = D->left;
        D->left = B;

        B->balance = heightC - heightA;
        D->size_l += B->size_l;
        D->ones_l += B->ones_l;
        D->balance = heightE - (max(heightA, heightC) + 1);

        assert(-2 <= B->balance and B->balance <= 2);
        assert(-2 <= D->balance and D->balance <= 2);

        return D;
    }

    // node Dを中心に右回転する．新しい親を返す
    Node *rotate_right(Node *D) {
        Node *B = D->left;

        const ll heightC = 0;
        const ll heightA = heightC - B->balance;
        const ll heightE = max(heightA, heightC) + 1 + D->balance;

        D->left = B->right;
        B->right = D;

        D->size_l -= B->size_l;
        D->ones_l -= B->ones_l;
        D->balance = heightE - heightC;
        B->balance = max(heightC, heightE) + 1 - heightA;


        assert(-2 <= B->balance and B->balance <= 2);
        assert(-2 <= D->balance and D->balance <= 2);

        return B;
    }

    // parentの子のoldNodeをnewNodeに置き換える
    void replace(Node *parent, Node *oldNode, Node *newNode) {
        if (parent == nullptr) {
            root = newNode;
            return;
        }

        if (parent->left == oldNode) {
            parent->left = newNode;
        }
        else if (parent->right == oldNode) {
            parent->right = newNode;
        }
        else {
            throw "old node is not child";
        }
    }
};

template <typename T>
struct DynamicWaveletMatrix {
    using ull = unsigned long long;

    vector<DynamicBitVector> bit_vectors;
    map<T, ull> values;
    T max_val;

    ull N;  // 与えられた配列のサイズ
    ull bit_size;   // 文字を表すのに必要なbit数

    T NOTFOUND = numeric_limits<T>::max() / 2;

    DynamicWaveletMatrix (const T max_v) {
        init(max_v);
    }

    DynamicWaveletMatrix (const T max_v, const vector<T> &A) {
        init(max_v);
        rep(i, A.size()) push_back(A[i]);
    }

    DynamicWaveletMatrix (const T max_v, ull n, T a) {
        init(max_v);
        rep(i, n) push_back(a);
    }

    void init(T max_v) {
        N = 0;
        bit_size = 0;
        max_val = max_v;

        while (T(1ull << bit_size) <= max_val + 1) ++bit_size;

        bit_vectors.resize(bit_size);
    }

    // v[pos]
    // 計算量: O(log(bit_size))
    T access(ull pos) {
        assert(pos < N);

        T val = 0;
        repd(h, bit_size) {
            ull bit = bit_vectors[h].access(pos);   // もとの数値のi番目のbit
            if (bit == 1) {
                val |= (1ull << h);
                pos = bit_vectors[h].rank(1, pos) + bit_vectors[h].zeros;
            }
            else {
                pos = bit_vectors[h].rank(0, pos);
            }
        }
        return val;
    }

    // posにcを挿入する
    void insert(ull pos, T val) {
        assert(pos <= N);
        ++N;
        values[val] += 1;

        repd(h, bit_size) {
            const ull bit = (val >> h) & 1;  //　上からi番目のbit
            bit_vectors[h].insert(pos, bit);
            pos = bit_vectors[h].rank(bit, pos);
            if (bit == 1) pos += bit_vectors[h].zeros;
        }
    }

    // posを削除する
    void erase(ull pos) {
        assert(pos < N);

        T val = access(pos);
        values[val] -= 1;
        --N;

        repd(h, bit_size) {
            ull bit = bit_vectors[h].access(pos);   // もとの数値のi番目のbit

            auto next_pos = bit_vectors[h].rank(bit, pos);
            bit_vectors[h].erase(pos);

            if (bit == 1) next_pos += bit_vectors[h].zeros;

            pos = next_pos;
        }
    }

    void set(ull pos, T val) {
        assert(pos < N);

        T old_val = access(pos);
        if (old_val == val) return;

        erase(pos);
        insert(pos, val);
    }

    void add(ull pos, T val) {
        assert(pos < N);

        T old_val = access(pos);
        set(pos, old_val + val);
    }

    void push_back(T val) {
        insert(N, val);
    }

    void pop_back() {
        erase(N - 1);
    }

    void push_front(T val) {
        insert(0, val);
    }

    void pop_front() {
        erase(0);
    }

    // k番目(1-indexed)のvalの位置(0-indexed)を返す
    // 存在しない場合はNを返す
    // 計算量: O(log(bit_size))
    ull select(T val, ull k) {
        assert(k > 0);
        if (!values.contains(val)) return N;

        ull left = 0;
        repd(h, bit_size) {
            const ull bit = (val >> h) & 1;  // 上からi番目のbit
            left = bit_vectors[h].rank(bit, left);               // cのi番目のbitと同じ数値の数
            if (bit) left += bit_vectors[h].zeros;
        }

        ull index = left + k;
        rep(h, bit_size){
            ull bit = ((val >> h) & 1); // 下からi番目のbit
            if (bit == 1) {
                index -= bit_vectors[h].zeros;
            }

            index = bit_vectors[h].select(bit, index) + 1;
        }
        return index;
    }

    // v[l, r)でk番目に大きい数値とindexを返す(kは1-indexed)
    // 計算量: O(log(bit_size))
    T kth_max(ull l, ull r, ull k) {
        assert(l < r and r <= N and 0 < k and k <= r - l);
        return quantile(l, r, r - l - k);
    }

    // v[l, r)でk番目に小さい数値とindexを返す(kは1-indexed)
    // 計算量: O(log(bit_size))
    T kth_min(ull l, ull r, ull k) {
        assert(l < r and r <= N and 0 < k and k <= r - l);
        return quantile(l, r, k - 1);
    }

    // v[l, r)の中央値(切り捨て)を返す
    // 計算量: O(log(bit_size))
    T median(ull l, ull r) {
        assert(l < r and r <= N);
        return (quantile(l, r, floor(r - l + 1, 2) - 1) + quantile(l, r, ceil(r - l + 1, 2) - 1)) / 2;
    }

    // v[l, r)でk番目(0-indexed)に小さい数値とindex(0-indexed)を返す
    // 小さい順に並べてk番目の値
    // 計算量: O(log(bit_size))
    T quantile(ull l, ull r, ull k) {
        assert(l < r and r <= N and k < r - l);

        ull val = 0;
        repd(h, bit_size) {
            const ull num_zero_l = bit_vectors[h].rank(0, l);
            const ull num_zero_r = bit_vectors[h].rank(0, r);
            const ull zeros = num_zero_r - num_zero_l;    // lからendまでにある0の数
            const ull bit = (k >= zeros);   // k番目の値の上からi番目のbitが0か1か

            if (bit == 1) {
                k -= zeros;
                l = bit_vectors[h].zeros + l - num_zero_l;
                r = bit_vectors[h].zeros + r - num_zero_r;
            }
            else {
                l = num_zero_l;
                r = num_zero_l + zeros;
            }

            val = (val << 1) | bit;
        }

        return val;
    }

    // v[0, pos)のvalの数
    // 計算量: O(log(bit_size))
    ull rank(T val, ull pos) {
        assert(pos <= N);
        if (pos == 0) return 0;
        if (!values.contains(val)) return 0;

        ull left = 0, right = pos;
        repd(h, bit_size) {
            ull bit = (val >> h) & 1;  // 上からi番目のbit
            left = bit_vectors[h].rank(bit, left);             // cのi番目のbitと同じ数値の数
            right = bit_vectors[h].rank(bit, right);           // cのi番目のbitと同じ数値の数
            if (bit) {
                left += bit_vectors[h].zeros;
                right += bit_vectors[h].zeros;
            }
        }

        return right - left;
    }

    // v[l, r)のvalの数
    // 計算量: O(log(bit_size))
    ull rank(T val, ull l, ull r) {
        assert(l <= r and r <= N);
        if (l == r) return 0;
        if (!values.contains(val)) return 0;

        return rank(val, r) - rank(val, l);
    }

    // v[0, pos)のvalの数
    // 計算量: O(log(bit_size))
    ull count(ull l, ull r, T val) {
        return rank(val, l, r);
    }

    // v[0, pos)でvalより小さい値の数を返す
    // 計算量: O(log(bit_size))
    ull count_less_than(ull pos, T val) {
        assert(pos <= N);

        if (val <= values.begin()->first) return 0;
        if (val > values.rbegin()->first) return pos;

        ull ret = 0;
        ull l = 0, r = pos;
        repd(h, bit_size) {
            if (l >= r) break;
            const ull bit = (val >> h) & 1;

            const ull rank0_l = bit_vectors[h].rank(0, l);
            const ull rank0_r = bit_vectors[h].rank(0, r);
            const ull rank1_l = l - rank0_l;
            const ull rank1_r = r - rank0_r;

            if (bit == 1) {
                ret += (rank0_r - rank0_l);    // i番目のbitが0のものは除外される
                l = bit_vectors[h].zeros + rank1_l;
                r = bit_vectors[h].zeros + rank1_r;
            } 
            else {
                l = rank0_l;
                r = rank0_r;
            }
        }

        return ret;
    }

    // v[l, r)でvalより小さい値の数を返す
    // 計算量: O(log(bit_size))
    ull count_less_than(ull l, ull r, T val) {
        assert(l <= r and r <= N);
        if (l == r) return 0;

        return count_less_than(r, val) - count_less_than(l, val);
    }

    // v[0, pos)でvalより大きい値の数を返す
    // 計算量: O(log(bit_size))
    ull count_more_than(ull pos, T val) {
        assert(pos <= N);

        if (val >= values.rbegin()->first) return 0;
        if (val < values.begin()->first) return pos;

        ull ret = 0;
        ull l = 0, r = pos;
        repd(h, bit_size) {
            const ull bit = (val >> h) & 1;

            const ull rank0_l = bit_vectors[h].rank(0, l);
            const ull rank0_r = bit_vectors[h].rank(0, r);
            const ull rank1_l = l - rank0_l;
            const ull rank1_r = r - rank0_r;

            if (bit == 1) {
                l = bit_vectors[h].zeros + rank1_l;
                r = bit_vectors[h].zeros + rank1_r;
            }
            else {
                ret += (rank1_r - rank1_l);    // i番目のbitが1のものは除外される
                l = rank0_l;
                r = rank0_r;
            } 
        }

        return ret;
    }

    // v[l, r)でvalより大きい値の数を返す
    // 計算量: O(log(bit_size))
    ull count_more_than(ull l, ull r, T val) {
        assert(l <= r and r <= N);
        if (l == r) return 0;
        return count_more_than(r, val) - count_more_than(l, val);
    }

    // v[l, r)で[lower, upper)に入る値の個数を返す
    ull count_in_range(ull l, ull r, T lower, T upper) {
        assert(l <= r and r <= N and lower <= upper);
        if (l == r) return 0;
        if (lower == upper) return 0;

        return count_less_than(l, r, upper) - count_less_than(l, r, lower);
    }

    // v[l, r)で頻度が高い順にk個の(値，頻度)を返す
    // 計算量: O(min(r - l, k)log(bit_size)
    vector<pair<T, ull>> top_k(ull l, ull r, ull k) {
        // (頻度，深さ，値)の順でソート
        auto comp = [](const tuple<ull, ull, ull, ull, T> &left, const tuple<ull, ull, ull, ull, T> &right) {
            // width
            if (get<0>(left) != get<0>(right)) {
                return get<0>(left) < get<0>(right);
            }
            // height
            if (get<3>(left) != get<3>(right)) {
                return get<3>(left) > get<3>(right);
            }
            // value
            if (get<4>(left) != get<4>(right)) {
                return get<4>(left) > get<4>(right);
            }
            return true;
        };

        return top_k(l, r, k, comp);
    }

    // v[l, r)で値が大きい順にk個の(値，頻度)を返す
    // 計算量: O(min(r - l, k)log(bit_size)
    vector<pair<T, ull>> max_k(ull l, ull r, ull k) {
        // (値，頻度)の順でソート
        auto comp = [](const tuple<ull, ull, ull, ull, T> &left, const tuple<ull, ull, ull, ull, T> &right) {
            // value
            if (get<4>(left) != get<4>(right)) {
                return get<4>(left) > get<4>(right);
            }
            // width
            if (get<0>(left) != get<0>(right)) {
                return get<0>(left) < get<0>(right);
            }
            // height
            if (get<3>(left) != get<3>(right)) {
                return get<3>(left) > get<3>(right);
            }
            return true;
        };

        return top_k(l, r, k, comp);
    }

    // v[l, r)で値が小さい順にk個の(値，頻度)を返す
    // 計算量: O(min(r - l, k)log(bit_size)
    vector<pair<T, ull>> min_k(ull l, ull r, ull k) {
        // (値，頻度)の順でソート
        auto comp = [](const tuple<ull, ull, ull, ull, T> &left, const tuple<ull, ull, ull, ull, T> &right) {
            // value
            if (get<4>(left) != get<4>(right)) {
                return get<4>(left) < get<4>(right);
            }
            // width
            if (get<0>(left) != get<0>(right)) {
                return get<0>(left) < get<0>(right);
            }
            // height
            if (get<3>(left) != get<3>(right)) {
                return get<3>(left) > get<3>(right);
            }
            return true;
        };

        return top_k(l, r, k, comp);
    }

    // T[l, r)で出現回数が多い順にk個の(値，頻度)を返す
    // 頻度が同じ場合は値が小さいものが優先される
    // 計算量: O(min(r - l, k)log(bit_size)
    vector<pair<T, ull>> top_k(ull l, ull r, ull k, auto comp) {
        assert(l <= r and r <= N);
        vector<pair<T, ull>> result;

        priority_queue<tuple<ull, ull, ull, ull, T>, vector<tuple<ull, ull, ull, ull, T>>, decltype(comp)> que(comp);  // width, height, value, left, right
        que.emplace(r - l, l, r, bit_size - 1, 0);

        while (!que.empty()) {
            auto element = que.top(); que.pop();
            ull width, left, right, height;
            T value;
            tie(width, left, right, height, value) = element;

            if (height == 0) {
                result.emplace_back(value, right - left);
                if (result.size() >= k) break;
                
                continue;
            }

            // 0
            const ull left0 = bit_vectors[height].rank(0, left);
            const ull right0 = bit_vectors[height].rank(0, right);
            if (left0 < right0) {
                que.emplace(right0 - left0, left0, right0, height - 1, value);
            }

            // 1
            const ull left1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, left);
            const ull right1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, right);
            if (left1 < right1) {
                que.emplace(right1 - left1, left1, right1, height - 1, value | (1ull << height));
            }
        }

        return result;
    };

    // T[l, r)でlower <= val < upperを満たす最大のvalを返す
    // 存在しない場合はNOTFOUNDを返す
    // 計算量: O(log(bit_size))
    ull prev_value(ull l, ull r, T lower, T upper) {
        assert(l <= r and r <= N);

        if (l == r) return NOTFOUND;
        if (lower >= upper) return NOTFOUND;
        if (lower > values.rbegin()->first) return NOTFOUND;
        if (upper <= values.begin()->first) return NOTFOUND;

        --upper; // lower <= val <= upperにする

        if (upper > max_val) upper = max_val;

        stack<tuple<ull, ull, ull, T, bool>> st;   // (l, r, depth, val, tight)
        st.emplace(l, r, 0, 0, true);

        while (!st.empty()) {
            ull l, r, depth;
            T val;
            bool tight;
            tie(l, r, depth, val, tight) = st.top(); st.pop();

            if (depth == bit_size) {
                if (val >= lower) return val;
                
                continue;
            }

            ull height = bit_size - depth - 1;

            const ull bit = (upper >> height) & 1;

            const ull rank0_l = bit_vectors[height].rank(0, l);
            const ull rank0_r = bit_vectors[height].rank(0, r);
            const ull rank1_l = l - rank0_l;
            const ull rank1_r = r - rank0_r;

            // d番目のbitが0のものを使う
            const ull l0 = rank0_l;
            const ull r0 = rank0_r;
            if (l0 != r0) { // 範囲がつぶれてない
                const ull val0 = val << 1;
                st.emplace(l0, r0, depth + 1, val0, tight and bit == 0);
            }

            // d番目のbitが1のものを使う
            const ull l1 = bit_vectors[height].zeros + rank1_l;
            const ull r1 = bit_vectors[height].zeros + rank1_r;
            if (l1 != r1) {
                if (!tight or bit == 1) {
                    const auto val1 = ((val << 1) | 1);
                    st.emplace(l1, r1, depth + 1, val1, tight);
                }
            }
        }

        return NOTFOUND;
    }

    // T[l, r)でlower <= val < upperを満たす最小のvalを返す
    ull next_value(ull l, ull r, ull lower, ull upper) {
        assert(l <= r and r <= N);

        if (l == r) return NOTFOUND;
        if (lower >= upper) return NOTFOUND;
        if (lower > values.rbegin()->first) return NOTFOUND;
        if (upper <= values.begin()->first) return NOTFOUND;

        stack<tuple<ull, ull, ull, T, bool>> st;   // (l, r, depth, val, tight)
        st.emplace(l, r, 0, 0, true);

        while (!st.empty()) {
            ull l, r, depth;
            T val;
            bool tight;
            tie(l, r, depth, val, tight) = st.top(); st.pop();

            if (depth == bit_size) {
                if (val < upper) return val;

                continue;
            }

            ull height = bit_size - depth - 1;

            const ull bit = (lower >> height) & 1;

            const ull rank0_l = bit_vectors[height].rank(0, l);
            const ull rank0_r = bit_vectors[height].rank(0, r);
            const ull rank1_l = l - rank0_l;
            const ull rank1_r = r - rank0_r;

            // d番目のbitが1のものを使う
            const ull l1 = bit_vectors[height].zeros + rank1_l;
            const ull r1 = bit_vectors[height].zeros + rank1_r;
            if (l1 != r1) {
                const auto val1 = ((val << 1) | 1);
                st.emplace(l1, r1, depth + 1, val1, tight and bit == 1);
            }

            // d番目のbitが0のものを使う
            const ull l0 = rank0_l;
            const ull r0 = rank0_r;
            if (l0 != r0) {
                if (!tight or bit == 0) {
                    const ull val0 = val << 1;
                    st.emplace(l0, r0, depth + 1, val0, tight);
                }
            }
        }

        return NOTFOUND;
    }

    // T[l, r)でval < upperを満たす最大のvalを返す
    ull prev_value(ull l, ull r, T upper) {
        return prev_value(l, r, values.begin()->first, upper);
    }

    // T[l, r)でlower <= valを満たす最小のvalを返す
    ull next_value(ull l, ull r, T lower) {
        return next_value(l, r, lower, max_val + 1);
    }

    // T[l1, r1)とT[l2, r2)に共通して出現する要素を求める
    vector<tuple<ull, ull, ull>> intersect(ull l1, ull r1, ull l2, ull r2) {
        assert(l1 <= r1 and r1 <= N);
        assert(l2 <= r2 and r2 <= N);

        vector<tuple<ull, ull, ull>> intersection;

        queue<tuple<ull, ull, ull, ull, ull, ull>> que; // l1, r1, l2, r2, height, value
        que.emplace(l1, r1, l2, r2, bit_size - 1, 0);
        while (!que.empty()) {
            auto element = que.front(); que.pop();
            ull l1, r1, l2, r2, height, value;
            tie(l1, r1, l2, r2, height, value) = element;

            if (height == 0) {
                intersection.emplace_back(value, r1 - l1, r2 - l2);
                continue;
            }

            // 0
            ull l1_0 = bit_vectors[height].rank(0, l1);
            ull r1_0 = bit_vectors[height].rank(0, r1);
            ull l2_0 = bit_vectors[height].rank(0, l2);
            ull r2_0 = bit_vectors[height].rank(0, r2);

            if (l1_0 != r1_0 and l2_0 != r2_0) {
                que.emplace(l1_0, r1_0, l2_0, r2_0, height - 1, value);
            }

            // 1
            ull l1_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, l1);
            ull r1_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, r1);
            ull l2_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, l2);
            ull r2_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, r2);

            if (l1_1 != r1_1 and l2_1 != r2_1) {
                que.emplace(l1_1, r1_1, l2_1, r2_1, height - 1, value | (1ull << height));
            }
        }

        return intersection;
    }
};