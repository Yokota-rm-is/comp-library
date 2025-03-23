#pragma once
#include "../base.cpp"

template<typename T>
struct LazySegmentTree {
    long long N, _N, height;

    vector<T> sum_v, max_v, min_v;
    vector<T> lazy_add, lazy_set;
    vector<long long> len;

    LazySegmentTree(long long n, T a) : _N(n) {
        vector<T> v(n, a);
        init(v);
    }

    LazySegmentTree(vector<T> &v) : _N(v.size()) {
        init(v);
    }

    void init(vector<T> &v) {
        _N = v.size();
        height = 1;
        N = 1;

        while (N < _N) {
            N *= 2;
            height++;
        }

        max_v.assign(2 * N, -inf64);
        min_v.assign(2 * N, inf64);
        sum_v.assign(2 * N, 0);
        
        lazy_add.assign(N, 0);
        lazy_set.assign(N, inf64);

        len.assign(2 * N, 0);

        rep(i, _N) {
            max_v[i + N] = v[i];
            min_v[i + N] = v[i];
            sum_v[i + N] = v[i];
            len[i + N] = 1;
        }
        repd(i, 1, N) update(i);
    }

    // pは0-indexed
    void apply_add(long long p, T f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        sum_v[k] += f;
        max_v[k] += f;
        min_v[k] += f;
        rep(i, 1, height) update(k >> i);
    }

    void apply_set(long long p, T f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        sum_v[k] = f;
        max_v[k] = f;
        min_v[k] = f;
        rep(i, 1, height) update(k >> i);
    }

    // l, rともに0-indexed
    void apply_add(long long l, long long r, T f) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) all_apply_add(l2++, f);
            if (r2 & 1) all_apply_add(--r2, f);
            l2 >>= 1;
            r2 >>= 1;
        }

        rep(i, 1, height) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    void apply_set(long long l, long long r, T f) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) all_apply_set(l2++, f);
            if (r2 & 1) all_apply_set(--r2, f);
            l2 >>= 1;
            r2 >>= 1;
        }

        rep(i, 1, height) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    T get(long long p) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        return sum_v[k];
    }

    // 半開区間[l, r)の配列の値を返す
    // l, rともに0-indexed
    T prod_sum(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        T sml = 0, smr = 0;
        while (l < r) {
            if (l & 1) sml = sml + sum_v[l++];
            if (r & 1) smr = sum_v[--r] + smr;
            l >>= 1;
            r >>= 1;
        }

        return sml + smr;
    }

    T prod_max(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        T sml = -inf64, smr = -inf64;
        while (l < r) {
            if (l & 1) sml = max(sml, max_v[l++]);
            if (r & 1) smr = max(max_v[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return max(sml, smr);
    }

    T prod_min(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        T sml = inf64, smr = inf64;
        while (l < r) {
            if (l & 1) sml = min(sml, min_v[l++]);
            if (r & 1) smr = min(min_v[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return min(sml, smr);
    }

private:
    // k番目のノードの値を子の値で更新
    void update(long long k) {
        assert(1 <= k and k <= N - 1);

        sum_v[k] = sum_v[k * 2] + sum_v[k * 2 + 1];
        max_v[k] = max(max_v[k * 2], max_v[k * 2 + 1]);
        min_v[k] = min(min_v[k * 2], min_v[k * 2 + 1]);
        len[k] = len[k * 2] + len[k * 2 + 1];
    }

    void all_apply_add(long long k, T f) {
        if (f == 0) return;

        sum_v[k] += f * len[k];
        max_v[k] += f;
        min_v[k] += f;

        if (k < N) {
            if (lazy_set[k] != inf64) lazy_set[k] += f;
            else lazy_add[k] += f;
        }
    }

    void all_apply_set(long long k, T f) {
        if (f == inf64) return;

        sum_v[k] = f * len[k];
        max_v[k] = f;
        min_v[k] = f;

        if (k < N) {
            lazy_set[k] = f;
            lazy_add[k] = 0;
        }
    }

    // k番目のノードを子に伝搬
    void push(long long k) {
        assert(1 <= k and k <= N * 2 - 1);

        all_apply_add(2 * k, lazy_add[k]);
        all_apply_add(2 * k + 1, lazy_add[k]);
        lazy_add[k] = 0;

        all_apply_set(2 * k, lazy_set[k]);
        all_apply_set(2 * k + 1, lazy_set[k]);
        lazy_set[k] = inf64;
    }
};