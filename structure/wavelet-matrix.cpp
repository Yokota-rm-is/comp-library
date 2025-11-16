#pragma once
#include "../base.cpp"

struct BitVector {
    using ull = unsigned long long;
    using uint = uint16_t;

    ull N;    // ビットベクトルのサイズ
    ull blockBitNum = 16;
    ull LEVEL_L = 512;
    ull LEVEL_S = 16;

    vector<ull> L;   // 大ブロック
    vector<uint> S;   // 小ブロック
    vector<uint> B;   // ビットベクトル

    ull ones, zeros = 0; // 1bitの数, 0bitの数

    BitVector(ull n) : N(n) {
        const ull s = (n + blockBitNum - 1) / blockBitNum + 1;   // ceil(n, blockSize)
        B.assign(s, 0);
        L.assign(n / LEVEL_L + 1, 0);
        S.assign(n / LEVEL_S + 1, 0);
    }

    // B[pos] = bit
    void set(const ull bit, const ull pos){
        assert(bit == 0 or bit == 1);
        assert(pos < N);

        const ull blockPos = pos / blockBitNum;
        const ull offset = pos % blockBitNum;
        if (bit == 1) B[blockPos] |= (1ull << offset);
        else B[blockPos] &= (~(1ull << offset));
    }

    // B[pos]
    ull access(const ull pos) {
        assert(pos < N);
        const ull blockPos = pos / blockBitNum;
        const ull offset   = pos % blockBitNum;
        return ((B[blockPos] >> offset) & 1);
    }

    void build() {
        ull num = 0;
        for (ull i = 0; i <= N; i++){
            if (i % LEVEL_L == 0) L[i / LEVEL_L] = num;
            if (i % LEVEL_S == 0) S[i / LEVEL_S] = num - L[i / LEVEL_L];
            if (i != N and i % blockBitNum == 0) {
                num += bit_count(B[i / blockBitNum]);
            }
        }
        ones = num;
        zeros = N - ones;
    }

    // B[0, pos)のbitの数
    ull rank(const ull bit, const ull pos) {
        assert(bit == 0 or bit == 1);
        assert(pos <= N);

        if (bit == 1) {
            return L[pos / LEVEL_L] + S[pos / LEVEL_S] + bit_count(B[pos / blockBitNum] & ((1ull << (pos % blockBitNum)) - 1));
        }
        else return pos - rank(1, pos);
    }

    // k番目(1-indexed)のbitの位置(0-indexed)を返す
    // 存在しない場合はNを返す
    ull select(const ull bit, const ull k) {
        assert(bit == 0 or bit == 1);
        assert(k > 0);

        if (bit == 0 and k > zeros) return N;
        if (bit == 1 and k > ones) return N;

        // 大ブロックL内を検索
        ull large_idx = 0;
        {
            ull left = 0;
            ull right = L.size();
            while (right - left > 1) {
                ull mid = (left + right) / 2;
                ull rank;
                if (bit == 1) rank = L[mid];
                else rank = mid * LEVEL_L - L[mid];

                if (rank < k) {
                    left = mid;
                    large_idx = mid;
                } 
                else right = mid;
            }
        }

        // 小ブロックS内を検索
        ull small_idx = (large_idx * LEVEL_L) / LEVEL_S;
        {
            ull left = (large_idx * LEVEL_L) / LEVEL_S;
            ull right = min(((large_idx + 1) * LEVEL_L) / LEVEL_S, (ull)S.size());
            while (right - left > 1) {
                ull mid = (left + right) / 2;
                ull rank;
                if (bit == 1) rank = L[large_idx] + S[mid];
                else rank = mid * LEVEL_S - (L[large_idx] + S[mid]);

                if (rank < k) {
                    left = mid;
                    small_idx = mid;
                } 
                else right = mid;
            }
        }

        // Bをブロック単位で順番に探索
        ull rank_pos = 0;
        {
            const ull begin_block_idx = (small_idx * LEVEL_S) / blockBitNum;
            ull total_bit;
            if (bit == 1) total_bit = L[large_idx] + S[small_idx];
            else total_bit = small_idx * LEVEL_S - (L[large_idx] + S[small_idx]);

            for (ull i = 0;; ++i) {
                ull b;
                if (bit == 1) b = bit_count(B[begin_block_idx + i]);
                else b = blockBitNum - bit_count(B[begin_block_idx + i]);

                if (total_bit + b >= k) {
                    ull block;
                    if (bit == 1) block = B[begin_block_idx + i];
                    else block = ~B[begin_block_idx + i];

                    rank_pos = (begin_block_idx + i) * blockBitNum + select_in_block(block, k - total_bit);
                    break;
                }

                total_bit += b;
            }
        }

        return rank_pos;
    }

    ull size() {
        return N;
    }

    ull select_in_block(ull x, ull k) {
        ull x1 = x - ((x & 0xAAAAAAAAAAAAAAAALLU) >> 1);
        ull x2 = (x1 & 0x3333333333333333LLU) + ((x1 >> 2) & 0x3333333333333333LLU);
        ull x3 = (x2 + (x2 >> 4)) & 0x0F0F0F0F0F0F0F0FLLU;

        ull pos = 0;
        for (;; pos += 8){
            ull k_next = (x3 >> pos) & 0xFFLLU;
            if (k <= k_next) break;
            k -= k_next;
        }

        ull v2 = (x2 >> pos) & 0xFLLU;
        if (k > v2) {
            k -= v2;
            pos += 4;
        }

        ull v1 = (x1 >> pos) & 0x3LLU;
        if (k > v1){
            k -= v1;
            pos += 2;
        }

        ull v0  = (x >> pos) & 0x1LLU;
        if (v0 < k){
            k -= v0;
            pos += 1;
        }

        return pos;
    }

    friend ostream& operator<< (ostream& os, BitVector& bv) {
        os << "L: ";
        rep(i, bv.L.size()) {
            os << bv.L[i] << ", ";
        }
        os << endl;
        os << "S: ";
        rep(i, bv.S.size()) {
            os << bv.S[i] << ", ";
        }
        os << endl;

        return os;
    }
};

template <typename T>
struct Node {
    T val;
    ull index;

    Node(T val, ull index) : val(val), index(index) {}

    operator T() const { return val; }
    friend ostream& operator<< (ostream& os, Node& node) {
        return os << node.val;
    }
};

template <typename T>
struct WaveletMatrix {
    using ull = unsigned long long;
    using S = Node<T>;

    vector<BitVector> bit_vectors;
    unordered_map<ull, ull> begin_indices;   // 最後のソートされた配列で各文字の開始位置
    vector<vector<T>> cumulative_sum;
    T min_val, max_val;

    ull N;  // 与えられた配列のサイズ
    ull bit_size;   // 文字を表すのに必要なbit数

    T NOTFOUND = numeric_limits<T>::max() / 2;

    WaveletMatrix (const vector<T> &A) {
        build(A);
    }

    WaveletMatrix (const string &S) {
        vector<T> A(S.size());
        rep(i, S.size()) A[i] = S[i];
        build(A);
    }

    void build(const vector<T> &A) {
        assert(A.size() > 0);
        fore(a, A) assert(a >= 0);

        N = A.size();
        bit_size = 0;
        max_val = *max_element(begin(A), end(A));
        min_val = *min_element(begin(A), end(A));
        while (T(1ull << bit_size) <= max_val + 1) ++bit_size;

        bit_vectors.assign(bit_size, BitVector(N));
        cumulative_sum.assign(bit_size, vector<T>(N + 1, 0));

        vector<T> cur = A;
        vector<T> nxt(N);
        repd(h, bit_size) {
            rep(i, N) if ((cur[i] >> h) & 1) bit_vectors[h].set(1, i);
            bit_vectors[h].build();

            auto it0 = nxt.begin();
            auto it1 = nxt.begin() + bit_vectors[h].zeros;

            rep(i, N) {
                if (bit_vectors[h].access(i) == 1) {
                    *it1 = cur[i];
                    ++it1;
                }
                else {
                    *it0 = cur[i];
                    ++it0;
                }
            }

            rep(i, N) {
                cumulative_sum[h][i + 1] = cumulative_sum[h][i] + cur[i];
            }
            
            swap(cur, nxt);
        }

        repd(i, N) {
            begin_indices[cur[i]] = i;
        }
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
            else pos = bit_vectors[h].rank(0, pos);
        }
        return val;
    }

    // k番目(1-indexed)のvalの位置(0-indexed)を返す
    // 存在しない場合はNを返す
    // 計算量: O(log(bit_size))
    ull select(T val, ull k) {
        assert(k > 0);
        if (!begin_indices.contains(val)) return N;

        ull index = begin_indices[val] + k;
        rep(h, bit_size){
            ull bit = ((val >> h) & 1); // 下からi番目のbit
            if (bit == 1) index -= bit_vectors[h].zeros;
            
            index = bit_vectors[h].select(bit, index) + 1;
        }
        return index - 1;
    }

    // v[l, r)の範囲でk番目(1-indexed)のvalの位置(0-indexed)を返す
    // 存在しない場合はNを返す
    // 計算量: O(log(bit_size))
    ull select(T val, ull k, ull l, ull r) {
        assert(l <= r and r <= N);
        if (l == r) return N;
        
        ull cr = count(l, r, val);
        if (cr < k) return N;

        ull cl = count(0, l, val);
        return select(val, cl + k);
    }

    // v[l, r)でk番目に大きい数値とindexを返す(kは1-indexed)
    // 計算量: O(log(bit_size))
    S kth_max(ull l, ull r, ull k) {
        assert(l < r and r <= N and 0 < k and k <= r - l);
        return quantile(l, r, r - l - k);
    }

    // v[l, r)でk番目に小さい数値とindexを返す(kは1-indexed)
    // 計算量: O(log(bit_size))
    S kth_min(ull l, ull r, ull k) {
        assert(l < r and r <= N and 0 < k and k <= r - l);
        return quantile(l, r, k - 1);
    }

    // v[l, r)の中央値(小さい方)と中央値(大きい方)を返す
    // 計算量: O(log(bit_size))
    pair<T, T> median(ull l, ull r) {
        assert(l < r and r <= N);
        T median_floor = quantile(l, r, floor(r - l + 1, 2) - 1).val;
        T median_ceil = quantile(l, r, ceil(r - l + 1, 2) - 1).val;

        return {median_floor, median_ceil};
    }

    // v[l, r)でk番目(0-indexed)に小さい数値とindex(0-indexed)を返す
    // 小さい順に並べてk番目の値
    // 計算量: O(log(bit_size))
    S quantile(ull l, ull r, ull k) {
        assert(l < r and r <= N and k < r - l);

        ull val = 0;
        repd(h, bit_size) {
            const ull zeros_l = bit_vectors[h].rank(0, l);
            const ull zeros_r = bit_vectors[h].rank(0, r);
            const ull zeros = zeros_r - zeros_l;    // lからendまでにある0の数
            const ull bit = (k >= zeros);   // k番目の値の上からi番目のbitが0か1か

            if (bit == 1) {
                k -= zeros;
                l = bit_vectors[h].zeros + l - zeros_l;
                r = bit_vectors[h].zeros + r - zeros_r;
            }
            else {
                l = zeros_l;
                r = zeros_l + zeros;
            }

            val = (val << 1) | bit;
        }

        return S(val, select(val, r - begin_indices[val]));
    }

    // v[0, pos)のvalの数
    // 計算量: O(log(bit_size))
    ull rank(T val, ull pos) {
        assert(pos <= N);
        if (pos == 0) return 0;
        if (!begin_indices.contains(val)) return 0;

        repd(h, bit_size) {
            ull bit = (val >> h) & 1;  // 上からi番目のbit
            pos = bit_vectors[h].rank(bit, pos);         // cのi番目のbitと同じ数値の数
            if (bit == 1) pos += bit_vectors[h].zeros;
        }

        ull l = begin_indices[val];
        return pos - l;
    }

    // v[l, r)のvalの数
    // 計算量: O(log(bit_size))
    ull rank(T val, ull l, ull r) {
        assert(l <= r and r <= N);
        if (l == r) return 0;
        if (!begin_indices.contains(val)) return 0;

        return rank(val, r) - rank(val, l);
    }

    // v[0, pos)のvalの数
    // 計算量: O(log(bit_size))
    ull count(ull l, ull r, T val) {
        return rank(val, l, r);
    }

    // v[l, r)でvalより小さい値の数を返す
    // 計算量: O(log(bit_size))
    ull count_less_than(ull l, ull r, T val) {
        assert(l <= r and r <= N);

        if (val <= min_val) return 0;
        if (val > max_val) return r - l;

        ull ret = 0;
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

    // v[0, pos)でvalより小さい値の数を返す
    // 計算量: O(log(bit_size))
    ull count_less_than(ull pos, T val) {
        assert(pos <= N);

        return count_less_than(0, pos, val);
    }

    // v[l, r)でvalより大きい値の数を返す
    // 計算量: O(log(bit_size))
    ull count_more_than(ull l, ull r, T val) {
        assert(l <= r and r <= N);

        if (val >= max_val) return 0;
        if (val < min_val) return r - l;

        ull ret = 0;
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

    // v[0, pos)でvalより大きい値の数を返す
    // 計算量: O(log(bit_size))
    ull count_more_than(ull pos, T val) {
        assert(pos <= N);
        return count_more_than(0, pos, val);
    }

    ull count_less_than_or_equal(ull l, ull r, T val) {
        return r - l - count_more_than(l, r, val);
    }

    ull count_more_than_or_equal(ull l, ull r, T val) {
        return r - l - count_less_than(l, r, val);
    }

    // v[l, r)で[lower, upper)に入る値の個数を返す
    ull count_in_range(ull l, ull r, T lower, T upper) {
        assert(l <= r and r <= N and lower <= upper);
        if (l == r) return 0;
        if (lower == upper) return 0;

        return count_less_than(l, r, upper) - count_less_than(l, r, lower);
    }

    // v[l, r)で頻度が高い順にk個の(値，頻度)を返す
    // 計算量: O(min(r - l, k)log(bit_size) * {priority_queueのlog})
    // priority_queueのlogが重そう
    vector<pair<T, ull>> top_k(ull l, ull r, ull k) {
        // (頻度，深さ，値)の順でソート
        auto comp = [](const tuple<ull, ull, ull, ull, T> &left, const tuple<ull, ull, ull, ull, T> &right) {
            // width
            if (get<0>(left) != get<0>(right)) {
                return get<0>(left) < get<0>(right);
            }
            // depth
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
    // 計算量: O(min(r - l, k)log(bit_size) * {priority_queueのlog})
    // priority_queueのlogが重そう
    vector<pair<T, ull>> max_k(ull l, ull r, ull k) {
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
            // depth
            if (get<3>(left) != get<3>(right)) {
                return get<3>(left) > get<3>(right);
            }
            return true;
        };

        return top_k(l, r, k, comp);
    }

    // v[l, r)で値が小さい順にk個の(値，頻度)を返す
    // 計算量: O(min(r - l, k)log(bit_size) * {priority_queueのlog})
    // priority_queueのlogが重そう
    vector<pair<T, ull>> min_k(ull l, ull r, ull k) {
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
            // depth
            if (get<3>(left) != get<3>(right)) {
                return get<3>(left) > get<3>(right);
            }
            return true;
        };

        return top_k(l, r, k, comp);
    }

    // T[l, r)で出現回数が多い順にk個の(値，頻度)を返す
    // 頻度が同じ場合は値が小さいものが優先される
    // 計算量: O(min(r - l, k)log(bit_size) * {priority_queueのlog})
    // priority_queueのlogが重そう
    vector<pair<T, ull>> top_k(ull l, ull r, ull k, auto comp) {
        assert(l <= r and r <= N);
        vector<pair<T, ull>> result;

        priority_queue<tuple<ull, ull, ull, ull, T>, vector<tuple<ull, ull, ull, ull, T>>, decltype(comp)> que(comp);  // width, height, value, left, right
        que.emplace(r - l, l, r, 0, 0);

        while (!que.empty()) {
            auto element = que.top(); que.pop();
            ull width, left, right, depth;
            T value;
            tie(width, left, right, depth, value) = element;

            if (depth >= bit_size) {
                result.emplace_back(value, right - left);
                if (result.size() >= k) break;
                
                continue;
            }

            ull height = bit_size - depth - 1;

            // 0
            const ull left0 = bit_vectors[height].rank(0, left);
            const ull right0 = bit_vectors[height].rank(0, right);
            if (left0 < right0) {
                que.emplace(right0 - left0, left0, right0, depth + 1, value);
            }

            // 1
            const ull left1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, left);
            const ull right1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, right);
            if (left1 < right1) {
                que.emplace(right1 - left1, left1, right1, depth + 1, value | (1ull << height));
            }
        }

        return result;
    };

    // T[l, r)で出現回数が多い順にk個の(値，頻度)の和を返す
    // 計算量: O(min(r - l, k)log(bit_size) * {priority_queueのlog})
    // priority_queueのlogが重そう
    T sum_top_k(ull l, ull r, ull k) {
        assert(l <= r and r <= N);
        assert(k <= r - l);

        auto topk = top_k(l, r, k);
        T ret = 0;
        for (auto [val, freq] : topk) {
            ret += val * freq;
        }
        return ret;
    }

    // T[l, r)で値が最大のものからk番目の値の和を返す
    // 計算量: O(log(bit_size))
    T sum_max_k(ull l, ull r, ull k) {
        assert(l <= r and r <= N);
        assert(k <= r - l);

        T kth_val = kth_max(l, r, k).val;
        ull kth_val_count = k - count_more_than(l, r, kth_val);
        return sum_more_than(l, r, kth_val) + kth_val * kth_val_count;
    }

    // T[l, r)で値が最小のものからk番目の値の和を返す
    // 計算量: O(log(bit_size))
    T sum_min_k(ull l, ull r, ull k) {
        assert(l <= r and r <= N);
        assert(k <= r - l);

        T kth_val = kth_min(l, r, k).val;
        ull kth_val_count = k - count_less_than(l, r, kth_val);
        return sum_less_than(l, r, kth_val) + kth_val * kth_val_count;
    }

    // T[l, r)で[lower, upper)に入る値の和を返す
    // 計算量: O(1)
    T sum(ull l, ull r) {
        return cumulative_sum[bit_size - 1][r] - cumulative_sum[bit_size - 1][l];
    }

    // T[l, r)でvalの和を返す
    // 計算量: O(log(bit_size))
    T sum(ull l, ull r, T val) {
        assert(l <= r and r <= N);
        if (!begin_indices.contains(val)) return 0;

        return count(l, r, val) * val;
    }

    // T[l, r)でval未満の値の和を返す
    // 計算量: O(log(bit_size))
    T sum_less_than(ull l, ull r, T val) {
        assert(l <= r and r <= N);
        if (val <= min_val) return 0;
        if (val > max_val) return sum(l, r);

        return range_sum(l, r, 0, 0, min_val, val);
    }

    // T[l, r)でvalより大きい値の和を返す
    // 計算量: O(log(bit_size))
    T sum_more_than(ull l, ull r, T val) {
        assert(l <= r and r <= N);
        if (val >= max_val) return 0;
        if (val < min_val) return sum(l, r);

        return range_sum(l, r, 0, 0, val + 1, max_val + 1);
    }

    // T[l, r)でlower <= val < upperを満たすvalの和を返す
    // 計算量: O(log(bit_size))
    T sum_in_range(ull l, ull r, T lower, T upper) {
        assert(l <= r and r <= N);
        assert(lower <= upper);
        if (lower <= min_val and max_val < upper) return sum(l, r);

        return range_sum(l, r, 0, 0, lower, upper);
    }

    // T[l, r)でlower <= val < upperを満たす最大のvalを返す
    // 存在しない場合はNOTFOUNDを返す
    // 計算量: O(log(bit_size))
    T prev_value(ull l, ull r, T lower, T upper) {
        assert(l <= r and r <= N);

        if (l == r) return NOTFOUND;
        if (lower >= upper) return NOTFOUND;
        if (lower > max_val) return NOTFOUND;
        if (upper <= min_val) return NOTFOUND;

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
                const T val0 = val << 1;
                st.emplace(l0, r0, depth + 1, val0, tight and bit == 0);
            }

            // d番目のbitが1のものを使う
            const ull l1 = bit_vectors[height].zeros + rank1_l;
            const ull r1 = bit_vectors[height].zeros + rank1_r;
            if (l1 != r1) {
                if (!tight or bit == 1) {
                    const T val1 = ((val << 1) | 1);
                    st.emplace(l1, r1, depth + 1, val1, tight);
                }
            }
        }

        return NOTFOUND;
    }

    // T[l, r)でlower <= val < upperを満たす最小のvalを返す
    T next_value(ull l, ull r, ull lower, ull upper) {
        assert(l <= r and r <= N);

        if (l == r) return NOTFOUND;
        if (lower >= upper) return NOTFOUND;
        if (lower > max_val) return NOTFOUND;
        if (upper <= min_val) return NOTFOUND;

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
                const T val1 = ((val << 1) | 1);
                st.emplace(l1, r1, depth + 1, val1, tight and bit == 1);
            }

            // d番目のbitが0のものを使う
            const ull l0 = rank0_l;
            const ull r0 = rank0_r;
            if (l0 != r0) {
                if (!tight or bit == 0) {
                    const T val0 = val << 1;
                    st.emplace(l0, r0, depth + 1, val0, tight);
                }
            }
        }

        return NOTFOUND;
    }

    // T[l, r)でval < upperを満たす最大のvalを返す
    T prev_value(ull l, ull r, T upper) {
        return prev_value(l, r, min_val, upper);
    }

    // T[l, r)でlower <= valを満たす最小のvalを返す
    T next_value(ull l, ull r, T lower) {
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

private:
    T range_sum(const ull l, const ull r, const ull depth, const T val, const T lower, const T upper) {
        if (l == r) return 0;

        if (depth == bit_size) {
            if (lower <= val and val < upper) {
                return val * (r - l);   // 値 * 頻度
            }
            return 0;
        }

        const ull height = bit_size - depth - 1;

        const T next_val = (1ull << height) | val;                   // 上からheight番目のbitを立てる
        const T all_one_val = ((1ull << height) - 1) | next_val;     // height以降のbitをたてる(これ以降全部1を選んだときの値)
        if(all_one_val < lower or upper <= val) return 0;

        // [l, pos)のすべての要素は[lower, upper)
        if (lower <= val and all_one_val < upper) {
            return cumulative_sum[height][r] - cumulative_sum[height][l];
        }

        const ull rank0_l = bit_vectors[height].rank(0, l);
        const ull rank0_r = bit_vectors[height].rank(0, r);
        const ull rank1_l = l - rank0_l;
        const ull rank1_r = r - rank0_r;

        return range_sum(rank0_l, rank0_r, depth + 1, val, lower, upper) +
               range_sum(bit_vectors[height].zeros + rank1_l, bit_vectors[height].zeros + rank1_r, depth + 1, next_val, lower, upper);
    }
};