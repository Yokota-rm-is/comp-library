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

template <typename T>
struct BIT {
    long long N, _N, height;
    vector<T> bit;

    BIT() {}
    BIT(long long n) { 
        init(n); 
    }

    void init(int n) {
        _N = n;
        N = 1;
        height = 1;
        while (N < (_N + 1)) {
            N *= 2;
            ++height;
        }
        bit.assign(N + 1, 0);
    }

    // 位置p (0-indexed)にxを加える
    void add(long long p, T x) {
        assert(0 <= p and p < _N);

        ++p; // 1-indexed

        for (int idx = p; idx < N; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }

    // 位置p (0-indexed)の値をxにする
    void set(long long p, T x) {
        assert(0 <= p and p < _N);

        T val = get(p);
        add(p, x - val);
    }

    // 半開区間[0, r) (0-indexed)の総和を求める
    T sum(long long r) {
        assert(0 <= r and r <= _N);

        if (r == 0) return 0;
        
        T ret = 0;
        for (int idx = r; idx > 0; idx -= (idx & -idx)) {
            ret += bit[idx];
        }
        return ret;
    }

    // 半開区間[l, r) (0-indexed)の総和を求める
    T sum(long long l, long long r) {
        assert(0 <= l and l <= r and r <= _N);

        if (l == r) return 0;
        else return sum(r) - sum(l);
    }

    // 位置p (0-indexed)の値を求める
    T get(long long p) {
        assert(0 <= p and p < _N);

        return sum(p + 1) - sum(p);
    }
};

template <typename T>
struct BITonWaveletMatrix {
    using uint = unsigned int;
    using ull = unsigned long long;
    using Point = pair<long long, long long>;

    ull N, logN;
    vector<BitVector> bit_vectors;
    vector<BIT<T>> bit;
    vector<Point> ps;
    vector<long long> ys;

    unordered_map<long long, T> original;

    BITonWaveletMatrix() {}
    BITonWaveletMatrix(const vector<pair<long long, long long>>& A) {
        rep(i, A.size()) {
            add_point(A[i].first, A[i].second);
        }
        build();
    }

    void add_point(ll y, ll x) {
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
        bit.assign(logN, N);
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

    T access(long long y, long long x) {
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

        return bit[0].get(i);
    }

    ull xid(long long x) const {
        auto comp = [](const Point& a, const Point& b) { return a.first < b.first;};
        return lower_bound(ps.begin(), ps.end(), make_pair(x, -inf64), comp) - ps.begin();
    }

    ull yid(long long y) const { 
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin(); }

    // (x, y)にvalを加える
    void add(long long y, long long x, T val) {
        ull i = lower_bound(ps.begin(), ps.end(), Point{x, y}) - ps.begin();
        ull j = yid(y);

        repd(h, logN) {
            ull i0 = bit_vectors[h].rank(0, i);
            if ((j >> h) & 1) {
                i += bit_vectors[h].zeros - i0;
            } else {
                i = i0;
            }
            bit[h].add(i, val);
        }
    }

    // (x, y)の値をvalにする
    void set(long long y, long long x, T val) {
        ull i = lower_bound(ps.begin(), ps.end(), Point{x, y}) - ps.begin();
        ull j = yid(y);

        repd(h, logN) {
            ull i0 = bit_vectors[h].rank(0, i);
            if ((j >> h) & 1) {
                i += bit_vectors[h].zeros - i0;
            } else {
                i = i0;
            }
            bit[h].set(i, val);
        }
    }

    // [h1, h2) x [w1, w2)の範囲の和を返す
    T sum(long long h1, long long h2, long long w1, long long w2) {
        return sum(h2, w1, w2) - sum(h1, w1, w2);
    }

    // [0, h) x [w1, w2)の範囲の和を返す
    T sum(long long h, long long w1, long long w2) {
        ll l = xid(w1), r = xid(w2);
        ll u = yid(h);

        T res = 0;
        repd(h, logN) {
            ull l0 = bit_vectors[h].rank(0, l), r0 = bit_vectors[h].rank(0, r);
            if ((u >> h) & 1) {
                res += bit[h].sum(l0, r0);
                l += bit_vectors[h].zeros - l0;
                r += bit_vectors[h].zeros - r0;
            } 
            else {
                l = l0, r = r0;
            }
        }
        return res;
    }

    // [0, h) x [0, w)の総和を求める
    T sum(long long h, long long w) {
        return sum(h, 0, w);
    }
};