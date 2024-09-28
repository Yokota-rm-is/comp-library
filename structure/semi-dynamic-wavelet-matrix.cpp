#pragma once
#include "../base.cpp"

template <typename T>
struct BIT {
    long long N, _N, height;
    vector<T> bit;

    BIT() {}
    BIT(long long n) { 
        init(n); 
    }

    void init(long long n) {
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
        
        if (val == x) return;
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

struct SemiDynamicBitVector {
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

    vector<BIT<ull>> state; // activeでないなら1

    SemiDynamicBitVector(ull n) : N(n), state(2, n) {
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

        deactivate(bit, pos);
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

    ull active_rank(const ull bit, const ull pos) {
        assert(bit == 0 or bit == 1);
        assert(pos <= N);

        return rank(bit, pos) - state[bit].sum(pos);
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

    bool is_active(const ull pos) {
        ull bit = access(pos);
        return state[bit].get(pos) == 0;
    }

    void activate(const ull bit, const ull pos) {
        state[bit].set(pos, 0);
    }

    void deactivate(const ull bit, const ull pos) {
        state[bit].set(pos, 1);
    }

    // select only active element
    ull active_select(const ull bit, const ull rank) {
        assert(bit == 0 or bit == 1);
        assert(rank > 0);
        if (bit == 0 and rank > zeros) return N;
        if (bit == 1 and rank > ones) return N;

        // 大ブロックL内を検索
        ull large_idx = 0;
        {
            ull left = 0;
            ull right = L.size();
            while (right - left > 1) {
                ull mid = (left + right) / 2;
                ull r = L[mid]; // [0, mid)にある1の数
                if (bit) {
                    r = r - state[bit].sum(mid * LEVEL_L);  // [0, mid)にあるactiveな1の数
                }
                else {
                    r = mid * LEVEL_L - L[mid] - state[bit].sum(mid * LEVEL_L);     // [0, mid)にあるactiveな0の数
                }

                if (r < rank) {
                    left = mid;
                    large_idx = mid;
                } else {
                    right = mid;
                }
            }
        }

        // 小ブロックS内を検索
        ull small_idx = (large_idx * LEVEL_L) / LEVEL_S;
        {
            ull left = (large_idx * LEVEL_L) / LEVEL_S;
            ull right = min(((large_idx  + 1) * LEVEL_L) / LEVEL_S, (ull)S.size());
            while (right - left > 1) {
                ull mid = (left + right) / 2;
                ull r = L[large_idx] + S[mid];   // [0, mid)にある1の数
                if (bit) {
                    r = r - state[bit].sum(mid * LEVEL_S);                 // [0, mid]にあるactiveな1の数
                }
                else {
                    r = mid * LEVEL_S - r - state[bit].sum(mid * LEVEL_S); // [0, mid)にあるactiveな0の数
                }

                if (r < rank) {
                    left = mid;
                    small_idx = mid;
                } 
                else {
                    right = mid;
                }
            }
        }

        // Bをブロック単位で順番に探索
        ull rank_pos = 0;
        {
            const ull begin_block_idx = (small_idx * LEVEL_S) / blockBitNum;
            ull total_bit = L[large_idx] + S[small_idx];
            if (bit) {
                total_bit = total_bit - state[bit].sum(small_idx * LEVEL_S);
            }
            else {
                total_bit = small_idx * LEVEL_S - total_bit - state[bit].sum(small_idx * LEVEL_S);
            }

            for (ull i = 0; begin_block_idx + i < B.size(); ++i) {
                if ((begin_block_idx + i) * blockBitNum > N) {
                    break;
                }

                ull b = bit_count(B[begin_block_idx + i]);   // ブロック内の1の数
                if (bit) {
                    b = b - state[bit].sum((begin_block_idx + i) * blockBitNum, min(N, (begin_block_idx + i + 1) * blockBitNum));
                }
                else {
                    b = (blockBitNum - b) - state[bit].sum((begin_block_idx + i) * blockBitNum, min(N, (begin_block_idx + i + 1) * blockBitNum));
                }

                // blockをすべていれると超えるならblock内を探索
                if (total_bit + b >= rank) {
                    ull block = (bit) ? B[begin_block_idx + i] : ~B[begin_block_idx + i];
                    ull x = active_select_in_block(block, rank - total_bit, (begin_block_idx + i) * blockBitNum, bit);

                    if (x == N) return N;

                    rank_pos = (begin_block_idx + i) * blockBitNum + x;
                    return rank_pos;
                }
                total_bit += b;
            }
        }

        return N;
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

    ull active_select_in_block(ull block, ull rank, ull base, ull bit) {
        for (int i = 0; base + i < N; ++i) {
            if (bit and state[bit].get(base + i) == 1) continue;
            if (!bit and state[!bit].get(base + i) == 1) continue;

            if (block & (1ull << i)) rank--;
            if (rank <= 0) return i;
        }

        return N;
    }

    friend ostream& operator<< (ostream& os, SemiDynamicBitVector& bv) {
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
struct SemiDynamicWaveletMatrix {
    using ull = unsigned long long;

    vector<SemiDynamicBitVector> bit_vectors;
    unordered_map<ull, ull> begin_indices;   // 最後のソートされた配列で各文字の開始位置
    vector<BIT<T>> cumulative_sum;
    BIT<T> inactive_count;
    T min_val = numeric_limits<T>::max(), max_val = numeric_limits<T>::min();

    ull N, _N;  // 与えられた配列のサイズ
    ull bit_size;   // 文字を表すのに必要なbit数

    vector<vector<T>> sim_values, values;
    vector<ull> indices;

    T NOTFOUND = numeric_limits<T>::max() / 2;

    SemiDynamicWaveletMatrix (long long n, T a): N(0), _N(n), sim_values(n), values(n), indices(n + 1) {
        rep(i, _N) simulate_set(i, a);
    }

    SemiDynamicWaveletMatrix (const vector<T> &A): N(0), _N(A.size()), sim_values(A.size()), values(A.size()), indices(A.size() + 1) {
        rep(i, _N) simulate_set(i, A[i]);
    }

    void simulate_set(ull pos, T val) {
        assert(pos < _N);
        assert(val >= 0);
        sim_values[pos].push_back(val);
        ++N;
        chmax(max_val, val);
        chmin(min_val, val);
    }

    void simulate_add(ull pos, T val) {
        simulate_set(pos, sim_values[pos].back() + val);
    }

    void build() {
        indices[0] = 0;
        rep(i, _N) {
            indices[i + 1] = indices[i] + sim_values[i].size();
        }

        bit_size = 0;
        while (T(1ull << bit_size) <= max_val + 1) ++bit_size;

        bit_vectors.assign(bit_size, N);
        cumulative_sum.assign(bit_size, N);
        inactive_count.init(N);

        vector<T> cur;
        rep(i, _N) {
            fore(v, sim_values[i]) {
                cur.push_back(v);
            }
        }
        vector<T> nxt(N);

        repd(h, bit_size) {
            rep(i, N) {
                if ((cur[i] >> h) & 1) bit_vectors[h].set(1, i);
                else bit_vectors[h].set(0, i);
            }
            bit_vectors[h].build();

            auto it0 = nxt.begin();
            auto it1 = nxt.begin() + bit_vectors[h].zeros;

            rep(i, N) {
                ull bit = bit_vectors[h].access(i);
                if (bit == 1) {
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

        repd(i, N) {
            begin_indices[cur[i]] = i;
            inactive_count.add(i, 1);
        }

        rep(i, _N) {
            set(i, sim_values[i].front());
        }
    }

    void activate(ull index, T val) {
        assert(index < N);

        repd(h, bit_size) {
            ull bit = bit_vectors[h].access(index);   // もとの数値のi番目のbit
            bit_vectors[h].activate(bit, index);
            cumulative_sum[h].add(index, val);

            if (bit == 1) {
                index = bit_vectors[h].rank(1, index) + bit_vectors[h].zeros;
            }
            else index = bit_vectors[h].rank(0, index);
        }   

        inactive_count.set(index, 0);
    }

    void deactivate(ull index) {
        assert(index < N);

        repd(h, bit_size) {
            ull bit = bit_vectors[h].access(index);   // もとの数値のi番目のbit
            bit_vectors[h].deactivate(bit, index);
            cumulative_sum[h].set(index, 0);

            if (bit == 1) {
                index = bit_vectors[h].rank(1, index) + bit_vectors[h].zeros;
            }
            else index = bit_vectors[h].rank(0, index);
        }   

        inactive_count.set(index, 1);
    }

    void set(ull pos, T val) {
        assert(pos < _N);
        assert(val >= 0);
        assert(val == sim_values[pos][values[pos].size()]);

        ull index = indices[pos] + values[pos].size();
        if (values[pos].size() > 0) deactivate(index - 1);
        activate(index, val);
        values[pos].push_back(val);
    }

    void add(ull pos, T val) {
        set(pos, values[pos].back() + val);
    }

    // v[pos]
    // 計算量: O(log(bit_size))
    T access(ull pos) {
        assert(pos < N);

        ull index = indices[pos] + values[pos].size() - 1;

        T val = 0;
        repd(h, bit_size) {
            ull bit = bit_vectors[h].access(index);   // もとの数値のi番目のbit
            if (bit == 1) {
                val |= (1ull << h);
                index = bit_vectors[h].rank(1, index) + bit_vectors[h].zeros;
            }
            else index = bit_vectors[h].rank(0, index);
        }
        return val;
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

    // v[l, r)の中央値(小さい方)と中央値(大きい方)を返す
    // 計算量: O(log(bit_size))
    pair<T, T> median(ull l, ull r) {
        assert(l < r and r <= N);
        T median_floor = quantile(l, r, floor(r - l + 1, 2) - 1);
        T median_ceil = quantile(l, r, ceil(r - l + 1, 2) - 1);

        return {median_floor, median_ceil};
    }

    // v[l, r)でk番目(0-indexed)に小さい数値を返す
    // 小さい順に並べてk番目の値
    // 計算量: O(log(bit_size))
    T quantile(ull l, ull r, ull k) {
        assert(l < r and r <= N and k < r - l);

        l = indices[l], r = indices[r];

        ull val = 0;
        repd(h, bit_size) {
            ull zeros_l = bit_vectors[h].active_rank(0, l);
            ull zeros_r = bit_vectors[h].active_rank(0, r);
            const ull zeros = zeros_r - zeros_l;    // lからendまでにある0の数
            const ull bit = (k >= zeros);   // k番目の値の上からi番目のbitが0か1か

            zeros_l = bit_vectors[h].rank(0, l);
            zeros_r = bit_vectors[h].rank(0, r);

            if (bit == 1) {
                k -= zeros;
                l = bit_vectors[h].zeros + l - zeros_l;
                r = bit_vectors[h].zeros + r - zeros_r;
            }
            else {
                l = zeros_l;
                r = zeros_r;
            }

            if ((l > r) or ((r - l) < k)) {
                return NOTFOUND;
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
        if (!begin_indices.contains(val)) return 0;

        ull index = indices[pos];

        ull bit;
        repd(h, bit_size) {
            bit = (val >> h) & 1;  // 上からi番目のbit
            index = bit_vectors[h].rank(bit, index);         // cのi番目のbitと同じ数値の数
            if (bit == 1) index += bit_vectors[h].zeros;
        }

        ull l = begin_indices[val];
        return index - l - inactive_count.sum(l, index);
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
        l = indices[l], r = indices[r];
        repd(h, bit_size) {
            if (l >= r) break;
            const ull bit = (val >> h) & 1;

            const ull active_rank0_l = bit_vectors[h].active_rank(0, l);
            const ull active_rank0_r = bit_vectors[h].active_rank(0, r);

            const ull rank0_l = bit_vectors[h].rank(0, l);
            const ull rank0_r = bit_vectors[h].rank(0, r);
            const ull rank1_l = l - rank0_l;
            const ull rank1_r = r - rank0_r;

            if (bit == 1) {
                ret += (active_rank0_r - active_rank0_l);    // i番目のbitが0のものは除外される
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
        l = indices[l], r = indices[r];
        repd(h, bit_size) {
            const ull bit = (val >> h) & 1;

            const ull active_rank1_l = bit_vectors[h].active_rank(1, l);
            const ull active_rank1_r = bit_vectors[h].active_rank(1, r);

            const ull rank0_l = bit_vectors[h].rank(0, l);
            const ull rank0_r = bit_vectors[h].rank(0, r);
            const ull rank1_l = l - rank0_l;
            const ull rank1_r = r - rank0_r;

            if (bit == 1) {
                l = bit_vectors[h].zeros + rank1_l;
                r = bit_vectors[h].zeros + rank1_r;
            }
            else {
                ret += (active_rank1_r - active_rank1_l);    // i番目のbitが1のものは除外される
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
        que.emplace(r - l, indices[l], indices[r], bit_size - 1, 0);

        while (!que.empty()) {
            auto element = que.top(); que.pop();
            ull width, left, right, height;
            T value;
            tie(width, left, right, height, value) = element;

            if (height == 0) {
                ull bit = bit_vectors[height].access(left);
                ull active_rank_l = bit_vectors[height].active_rank(bit, left);
                ull active_rank_r = bit_vectors[height].active_rank(bit, right);
                result.emplace_back(value, active_rank_r - active_rank_l);
                if (result.size() >= k) break;
                
                continue;
            }

            // 0
            const ull active_left0 = bit_vectors[height].active_rank(0, left);
            const ull active_right0 = bit_vectors[height].active_rank(0, right);
            const ull left0 = bit_vectors[height].rank(0, left);
            const ull right0 = bit_vectors[height].rank(0, right);
            if (active_left0 < active_right0) {
                que.emplace(active_right0 - active_left0, left0, right0, height - 1, value);
            }

            // 1
            const ull active_left1 = bit_vectors[height].active_rank(1, left);
            const ull active_right1 = bit_vectors[height].active_rank(1, right);
            const ull left1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, left);
            const ull right1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, right);
            if (active_left1 < active_right1) {
                que.emplace(active_right1 - active_left1, left1, right1, height - 1, value | (1ull << height));
            }
        }

        return result;
    };

    // T[l, r)で出現回数が多い順にk個の(値，頻度)の和を返す
    // 計算量: O(min(r - l, k)log(bit_size)
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

        T kth_val = kth_max(l, r, k);
        ull kth_val_count = k - count_more_than(l, r, kth_val);
        return sum_more_than(l, r, kth_val) + kth_val * kth_val_count;
    }

    // T[l, r)で値が最小のものからk番目の値の和を返す
    // 計算量: O(log(bit_size))
    T sum_min_k(ull l, ull r, ull k) {
        assert(l <= r and r <= N);
        assert(k <= r - l);

        T kth_val = kth_min(l, r, k);
        ull kth_val_count = k - count_less_than(l, r, kth_val);
        return sum_less_than(l, r, kth_val) + kth_val * kth_val_count;
    }

    // T[l, r)で[lower, upper)に入る値の和を返す
    // 計算量: O(1)
    T sum(ull l, ull r) {
        assert(l <= r and r <= N);
        l = indices[l], r = indices[r];
        return cumulative_sum[bit_size - 1].sum(l, r);
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

        l = indices[l], r = indices[r];

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
            const ull l0 = bit_vectors[height].active_rank(0, l);
            const ull r0 = bit_vectors[height].active_rank(0, r);
            if (l0 != r0) { // 範囲がつぶれてない
                const T val0 = val << 1;
                st.emplace(rank0_l, rank0_r, depth + 1, val0, tight and bit == 0);
            }

            // d番目のbitが1のものを使う
            const ull l1 = bit_vectors[height].active_rank(1, l);
            const ull r1 = bit_vectors[height].active_rank(1, r);
            if (l1 != r1) {
                if (!tight or bit == 1) {
                    const T val1 = ((val << 1) | 1);
                    st.emplace(bit_vectors[height].zeros + rank1_l, bit_vectors[height].zeros + rank1_r, depth + 1, val1, tight);
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

        l = indices[l], r = indices[r];

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
            const ull l1 = bit_vectors[height].active_rank(1, l);
            const ull r1 = bit_vectors[height].active_rank(1, r);
            if (l1 != r1) {
                const T val1 = ((val << 1) | 1);
                st.emplace(bit_vectors[height].zeros + rank1_l, bit_vectors[height].zeros + rank1_r, depth + 1, val1, tight and bit == 1);
            }

            // d番目のbitが0のものを使う
            const ull l0 = bit_vectors[height].active_rank(0, l);
            const ull r0 = bit_vectors[height].active_rank(0, r);
            if (l0 != r0) { // 範囲がつぶれてない
                if (!tight or bit == 0) {
                    const T val0 = val << 1;
                    st.emplace(rank0_l, rank0_r, depth + 1, val0, tight);
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

        l1 = indices[l1], r1 = indices[r1];
        l2 = indices[l2], r2 = indices[r2];

        queue<tuple<ull, ull, ull, ull, ull, ull>> que; // l1, r1, l2, r2, height, value
        que.emplace(l1, r1, l2, r2, bit_size - 1, 0);
        while (!que.empty()) {
            auto element = que.front(); que.pop();
            ull l1, r1, l2, r2, height, value;
            tie(l1, r1, l2, r2, height, value) = element;

            if (height == 0) {
                ull bit = bit_vectors[height].access(l1);
                ull active_l1 = bit_vectors[height].active_rank(bit, l1);
                ull active_r1 = bit_vectors[height].active_rank(bit, r1);
                ull active_l2 = bit_vectors[height].active_rank(bit, l2);
                ull active_r2 = bit_vectors[height].active_rank(bit, r2);
                if (active_l1 < active_r1 and active_l2 < active_r2) {
                    intersection.emplace_back(value, active_r1 - active_l1, active_r2 - active_l2);
                }
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
    T range_sum(ull l, ull r, const ull depth, const T val, const T lower, const T upper) {
        if (l == r) return 0;

        if (depth == 0) {
            l = indices[l], r = indices[r];
        }

        if (depth == bit_size) {
            if (lower <= val and val < upper) {
                return val * (r - l - inactive_count.sum(l, r));   // 値 * 頻度
            }
            return 0;
        }

        const ull height = bit_size - depth - 1;

        const T next_val = (1ull << height) | val;                   // 上からheight番目のbitを立てる
        const T all_one_val = ((1ull << height) - 1) | next_val;     // height以降のbitをたてる(これ以降全部1を選んだときの値)
        if (all_one_val < lower or upper <= val) return 0;

        // [l, pos)のすべての要素は[lower, upper)
        if (lower <= val and all_one_val < upper) {
            return cumulative_sum[height].sum(l, r);
        }

        const ull rank0_l = bit_vectors[height].rank(0, l);
        const ull rank0_r = bit_vectors[height].rank(0, r);
        const ull rank1_l = l - rank0_l;
        const ull rank1_r = r - rank0_r;

        return range_sum(rank0_l, rank0_r, depth + 1, val, lower, upper) +
               range_sum(bit_vectors[height].zeros + rank1_l, bit_vectors[height].zeros + rank1_r, depth + 1, next_val, lower, upper);
    }
};
