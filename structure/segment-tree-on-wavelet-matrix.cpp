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

                    rank_pos = (begin_block_idx + i) * blockBitNum + selectInBlock(block, k - total_bit);
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

    ull selectInBlock(ull x, ull k) {
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

template<typename T>
struct Node {
    T value;
    long long index;
    long long size;
    long long coeff;

    Node(T v, long long i = -1, long long s = 0, long long c = 1) : value(v), index(i), size(s), coeff(c) {};

    bool operator< (const Node &other) const {
        return value < other.value;
    }

    bool operator== (const T other) const {
        return value == other;
    }

    bool operator!= (const T other) const {
        return value != other;
    }

    operator T() const {
        return value;
    }

    friend ostream& operator << (ostream &os, const Node<T>& node) {
        return os << node.value;
    }
};

template<typename T>
struct Operation {
    using S = Node<T>;

    Operation() {};

    virtual T e() = 0;

    virtual S operator() (const S& x, const S& y) = 0;
};

template<typename T = long long>
struct NoOperation : Operation<T> {
    using S = Node<T>;

    NoOperation(): _e(T()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        if (x == e()) return y;
        else if (y == e()) return x;

        T value = x.value;
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T>
struct Max : Operation<T> {
    using S = Node<T>;

    Max(): _e(numeric_limits<T>::min()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = max(x.value, y.value);
        long long index = (y.value > x.value ? y.index : x.index);
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T>
struct Min: Operation<T> {
    using S = Node<T>;

    Min(): _e(numeric_limits<T>::max()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = min(x.value, y.value);
        long long index = (y.value < x.value ? y.index : x.index);
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T>
struct Sum: Operation<T> {
    using S = Node<T>;

    Sum(): _e(T()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = x.value + y.value;
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = size;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T>
struct Mul: Operation<T> {
    using S = Node<T>;

    Mul(): _e(T(1)) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = x.value * y.value;
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T = long long>
struct GCD : Operation<T> {
    using S = Node<T>;

    GCD(): _e(T(0)) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = gcd(x.value, y.value);
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T = long long>
struct LCM : Operation<T> {
    using S = Node<T>;

    LCM(): _e(T(1)) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = lcm(x.value, y.value);
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }


private:
    T _e;
};

template<typename T, typename F>
struct Mapping {
    using S = Node<T>;

    Mapping() {};

    virtual F id() = 0;

    void operator() (S &x, const F f) {
        if (f == id()) return;

        map(x, f);
    }

    virtual void map(S &x, const F f) = 0;
};

template<typename T, typename F>
struct Add: Mapping<T, F> {
    using S = Node<T>;

    Add(): _id(F(0)) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        x.value += f;
    }

private:
    F _id;
};

template<typename T, typename F>
struct Multiply: Mapping<T, F> {
    using S = Node<T>;

    Multiply(): _id(F(1)) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        x.value *= f;
    }

private:
    F _id;
};

template<typename T, typename G>
struct Affine: Mapping<T, pair<G, G>> {
    using S = Node<T>;
    using F = pair<G, G>;

    Affine(): _id(F(1, 0)) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        x.value = f.first * x.value + f.second;
    }

private:
    F _id;
};

template<typename T, typename F>
struct Set: Mapping<T, F> {
    using S = Node<T>;

    Set(): _id(numeric_limits<F>::min()) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override { 
        x.value = T(f);
    }

private:
    F _id;
};

template<typename T, 
    typename F,
    template<class, class> class _mapping,
    template<class> class _op>
struct SegmentTree {
    using S = Node<T>;

    long long N, _N, height;
    vector<S> node;
    _op<T> op;
    _mapping<T, F> mapping;

    SegmentTree(): _N(0), op(), mapping() {}
    SegmentTree(long long n) : _N(n), op(), mapping() {
        init();
    }
    SegmentTree(long long n, T a) : _N(n), op(), mapping() { 
        init();

        rep(i, _N) node[i + N] = S(a, i, 1, 1);
        repd(i, 1, N) update(i);
    }
    SegmentTree(const vector<T>& v): _N(v.size()), op(), mapping() { 
        init();

        rep(i, _N) node[i + N] = S(v[i], i, 1, 1);
        repd(i, 1, N) update(i); 
    }

    void init() {
        N = 1;
        height = 1;
        while (N < (_N + 1)) {
            N *= 2;
            ++height;
        }

        node.assign(2 * N, S(op.e()));
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply(long long p, F f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        mapping(node[k], f);
        rep(i, 1, height) update(k >> i);
    }

    T get(long long p) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        return node[k];
    }

    // 半開区間[l, r)の配列の値を返す
    // l, rともに0-indexed
    S prod(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        S sml(op.e()), smr(op.e());
        while (l < r) {
            if (l & 1) sml = op(sml, node[l++]);
            if (r & 1) smr = op(node[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    // 半開区間[l, r) (0-indexed)の要素の数を求める
    T count(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        return prod(l, r).size;
    }

private:
    // k番目のノードの値を子の値で更新
    void update(long long k) {
        assert(1 <= k and k <= N - 1);

        node[k] = op(node[k * 2], node[k * 2 + 1]);
    }
};

template<typename T, 
    typename F,
    template<class, class> class _mapping,
    template<class> class _op>
struct SegmentTreeonWaveletMatrix {
    using uint = unsigned int;
    using ull = unsigned long long;
    using Point = pair<long long, long long>;
    using S = Node<T>;

    ull N, logN;
    vector<BitVector> bit_vectors;
    vector<SegmentTree<T, F, _mapping, _op>> tree;
    vector<Point> ps;
    vector<long long> ys;

    _op<T> op;
    _mapping<T, F> mapping;

    unordered_map<long long, T> original;

    SegmentTreeonWaveletMatrix() {}
    SegmentTreeonWaveletMatrix(const vector<pair<long long, long long>>& A) {
        rep(i, A.size()) {
            add_point(A[i].first, A[i].second);
        }
        build();
    }

    void add_point(ll x, ll y) {
        ps.emplace_back(x, y);
        ys.emplace_back(y);
    }

    void build() {
        sort(ps.begin(), ps.end());
        ps.erase(unique(ps.begin(), ps.end()), ps.end());
        N = ps.size();

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        vector<uint> cur(N), nxt(N);
        rep(i, N) cur[i] = yid(ps[i].second);

        logN = 0;
        while ((1ull << logN) <= N) ++logN;
        bit_vectors.assign(logN, N);
        tree.assign(logN, N);
        repd(h, logN) {
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
            
            swap(cur, nxt);
        }
    }

    T access(long long x, long long y) {
        ull i = lower_bound(ps.begin(), ps.end(), Point{x, y}) - ps.begin();
        ull j = yid(y);

        repd(h, logN) {
            ull i0 = bit_vectors[h].rank(0, i);
            if ((j >> h) & 1) {
                i += bit_vectors[h].zeros - i0;
            } else {
                i = i0;
            }
        }

        return tree[0].get(i);
    }

    ull xid(long long x) const {
        auto comp = [](const Point& a, const Point& b) { return a.first < b.first;};
        return lower_bound(ps.begin(), ps.end(), make_pair(x, -inf64), comp) - ps.begin();
    }

    ull yid(long long y) const { 
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin(); }

    // p番目の配列の値に対して，valでmapping
    void apply(long long x, long long y, T val) {
        ull i = lower_bound(ps.begin(), ps.end(), Point{x, y}) - ps.begin();
        ull j = yid(y);

        repd(h, logN) {
            ull i0 = bit_vectors[h].rank(0, i);
            if ((j >> h) & 1) {
                i += bit_vectors[h].zeros - i0;
            } else {
                i = i0;
            }
            tree[h].apply(i, val);
        }
    }

    // // [l, r), [d, u)の範囲の和を返す
    // S prod(long long l, long long r, long long d, long long u) {
    //     return prod(l, r, u) - prod(l, r, d);
    // }

    // [l, r), [0, u)の範囲の和を求める
    T prod(long long l, long long r, long long u) {
        l = xid(l), r = xid(r);
        u = yid(u);

        S res(op.e());
        repd(h, logN) {
            ull l0 = bit_vectors[h].rank(0, l), r0 = bit_vectors[h].rank(0, r);
            if ((u >> h) & 1) {
                res = op(res, tree[h].prod(l0, r0));
                l += bit_vectors[h].zeros - l0;
                r += bit_vectors[h].zeros - r0;
            } 
            else {
                l = l0, r = r0;
            }
        }
        return res;
    }

    // [l, r)の総和を求める
    T prod(long long l, long long r) {
        return prod(l, r, inf64);
    }

    // [l, r), [d, u)の範囲の要素の数を求める
    T count(long long l, long long r, long long d, long long u) {
        return count(l, r, u) - count(l, r, d);
    }

    // [l, r), [0, u)の範囲の要素の数を求める
    T count(long long l, long long r, T u) {
        l = xid(l), r = xid(r);
        u = yid(u);

        T res = 0;
        repd(h, logN) {
            ull l0 = bit_vectors[h].rank(0, l), r0 = bit_vectors[h].rank(0, r);
            if ((u >> h) & 1) {
                res += tree[h].count(l0, r0);
                l += bit_vectors[h].zeros - l0;
                r += bit_vectors[h].zeros - r0;
            } 
            else {
                l = l0, r = r0;
            }
        }
        return res;
    }

    // [l, r)の要素の数を求める
    T count(long long l, long long r) {
        return count(l, r, inf64);
    }
};