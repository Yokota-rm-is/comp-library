#pragma once
#include "../base.cpp"

struct LazySegmentTree01 {
    long long N, _N, height;

    vector<long long> zeros, ones;
    vector<int> left_v, right_v;
    vector<long long> left_ones, right_ones, left_zeros, right_zeros;
    vector<long long> len_ones, len_zeros;
    vector<int> lazy_set, lazy_flip;
    vector<long long> len;

    LazySegmentTree01(long long n, bool a) : _N(n) {
        vector<bool> v(n, a);
        init(v);
    }

    LazySegmentTree01(vector<bool> &v) : _N(v.size()) {
        init(v);
    }

    LazySegmentTree01(vector<int> &v) : _N(v.size()) {
        vector<bool> u(v.size());
        rep(i, v.size()) u[i] = (v[i] > 0);
        init(u);
    }

    void init(vector<bool> &v) {
        _N = v.size();
        height = 1;
        N = 1;

        while (N < _N) {
            N *= 2;
            height++;
        }

        zeros.assign(2 * N, 0);
        ones.assign(2 * N, 0);
        left_v.assign(2 * N, -1);
        right_v.assign(2 * N, -1);
        left_ones.assign(2 * N, 0);
        right_ones.assign(2 * N, 0);
        left_zeros.assign(2 * N, 0);
        right_zeros.assign(2 * N, 0);
        len_ones.assign(2 * N, 0);
        len_zeros.assign(2 * N, 0);

        lazy_flip.assign(N, false);
        lazy_set.assign(N, -1);

        len.assign(2 * N, 0);

        rep(i, _N) {
            zeros[i + N] = !v[i];
            ones[i + N] = v[i];
            left_v[i + N] = v[i];
            right_v[i + N] = v[i];
            left_ones[i + N] = (v[i] == 1);
            right_ones[i + N] = (v[i] == 1);
            left_zeros[i + N] = (v[i] == 0);
            right_zeros[i + N] = (v[i] == 0);
            len_ones[i + N] = (v[i] == 1);
            len_zeros[i + N] = (v[i] == 0);

            len[i + N] = 1;
        }
        repd(i, 1, N) update(i);
    }

    // pは0-indexed
    void apply_set(long long p, bool f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        int v = f;
        left_v[k] = v;
        right_v[k] = v;
        zeros[k] = (v == 0);
        ones[k] = (v == 1);
        left_ones[k] = (v == 1);
        right_ones[k] = (v == 1);
        left_zeros[k] = (v == 0);
        right_zeros[k] = (v == 0);
        len_ones[k] = (v == 1);
        len_zeros[k] = (v == 0);

        rep(i, 1, height) update(k >> i);
    }

    // pは0-indexed
    void apply_flip(long long p) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        int v = !left_v[k];
        left_v[k] = v;
        right_v[k] = v;
        zeros[k] = (v == 0);
        ones[k] = (v == 1);
        left_ones[k] = (v == 1);
        right_ones[k] = (v == 1);
        left_zeros[k] = (v == 0);
        right_zeros[k] = (v == 0);
        len_ones[k] = (v == 1);
        len_zeros[k] = (v == 0);

        rep(i, 1, height) update(k >> i);
    }

    // pは0-indexed
    void apply_and(long long p, bool f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        int v = left_v[k] & f;
        left_v[k] = v;
        right_v[k] = v;
        zeros[k] = (v == 0);
        ones[k] = (v == 1);
        left_ones[k] = (v == 1);
        right_ones[k] = (v == 1);
        left_zeros[k] = (v == 0);
        right_zeros[k] = (v == 0);
        len_ones[k] = (v == 1);
        len_zeros[k] = (v == 0);

        rep(i, 1, height) update(k >> i);
    }

    // pは0-indexed
    void apply_or(long long p, bool f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        int v = left_v[k] | f;
        left_v[k] = v;
        right_v[k] = v;
        zeros[k] = (v == 0);
        ones[k] = (v == 1);
        left_ones[k] = (v == 1);
        right_ones[k] = (v == 1);
        left_zeros[k] = (v == 0);
        right_zeros[k] = (v == 0);
        len_ones[k] = (v == 1);
        len_zeros[k] = (v == 0);

        rep(i, 1, height) update(k >> i);
    }

    // pは0-indexed
    void apply_xor(long long p, bool f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        int v = left_v[k] ^ f;
        left_v[k] = v;
        right_v[k] = v;
        zeros[k] = (v == 0);
        ones[k] = (v == 1);
        left_ones[k] = (v == 1);
        right_ones[k] = (v == 1);
        left_zeros[k] = (v == 0);
        right_zeros[k] = (v == 0);
        len_ones[k] = (v == 1);
        len_zeros[k] = (v == 0);

        rep(i, 1, height) update(k >> i);
    }

    void apply_set(long long l, long long r, bool f) {
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

    void apply_flip(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) all_apply_flip(l2++, true);
            if (r2 & 1) all_apply_flip(--r2, true);
            l2 >>= 1;
            r2 >>= 1;
        }

        rep(i, 1, height) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    void apply_and(long long l, long long r, bool f) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) {
                if (!f) all_apply_set(l2++, false);
                else l2++;
            }
            if (r2 & 1) {
                if (!f) all_apply_set(--r2, false);
                else --r2;
            }
            l2 >>= 1;
            r2 >>= 1;
        }

        rep(i, 1, height) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    void apply_or(long long l, long long r, bool f) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) {
                if (f) all_apply_set(l2++, true);
                else l2++;
            }
            if (r2 & 1) {
                if (f) all_apply_set(--r2, true);
                else --r2;
            }
            l2 >>= 1;
            r2 >>= 1;
        }

        rep(i, 1, height) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    void apply_xor(long long l, long long r, bool f) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) {
                if (f) all_apply_flip(l2++);
                else l2++;
            }
            if (r2 & 1) {
                if (f) all_apply_flip(--r2);
                else --r2;
            }
            l2 >>= 1;
            r2 >>= 1;
        }

        rep(i, 1, height) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    void apply_nand(long long l, long long r, bool f) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) {
                if (f) all_apply_flip(l2++);
                else all_apply_set(l2++, 1);
            }
            if (r2 & 1) {
                if (f) all_apply_flip(--r2);
                else all_apply_set(--r2, 1);
            }
            l2 >>= 1;
            r2 >>= 1;
        }

        rep(i, 1, height) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    void apply_nor(long long l, long long r, bool f) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) {
                if (!f) all_apply_flip(l2++);
                else all_apply_set(l2++, 0);
            }
            if (r2 & 1) {
                if (!f) all_apply_flip(--r2);
                else all_apply_set(--r2, 0);
            }
            l2 >>= 1;
            r2 >>= 1;
        }

        rep(i, 1, height) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    bool get(long long p) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        return ones[k];
    }

    // 半開区間[l, r)の配列の値を返す
    // l, rともに0-indexed
    bool prod_or(long long l, long long r) {
        assert(0 <= l && l < r && r <= _N);

        return prod_ones(l, r) > 0;
    }

    // 半開区間[l, r)の配列の値を返す
    // l, rともに0-indexed
    bool prod_and(long long l, long long r) {
        assert(0 <= l && l < r && r <= _N);

        return prod_zeros(l, r) == 0;
    }

    // 半開区間[l, r)の配列の値を返す
    // l, rともに0-indexed
    bool prod_xor(long long l, long long r) {
        assert(0 <= l && l < r && r <= _N);

        return prod_ones(l, r) % 2;
    }

    long long prod_ones(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long sml = 0, smr = 0;
        while (l < r) {
            if (l & 1) sml += ones[l++];
            if (r & 1) smr += ones[--r];
            l >>= 1;
            r >>= 1;
        }

        return sml + smr;
    }

    long long prod_zeros(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long sml = 0, smr = 0;
        while (l < r) {
            if (l & 1) sml += zeros[l++];
            if (r & 1) smr += zeros[--r];
            l >>= 1;
            r >>= 1;
        }

        return sml + smr;
    }

    long long prod_len_ones(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long sml = 0, smr = 0;
        long long left_one = 0, right_one = 0;
        while (l < r) {
            if (l & 1) {
                sml = max({sml, len_ones[l], right_one + left_ones[l]});
                right_one = (left_ones[l] == len[l]) ? right_one + left_ones[l] : right_ones[l];
                l++;
            }
            if (r & 1) {
                --r;
                smr = max({smr, len_ones[r], left_one + right_ones[r]});
                left_one = (right_ones[r] == len[r]) ? left_one + right_ones[r] : left_ones[r];
            }
            l >>= 1;
            r >>= 1;
        }

        return max({sml, smr, right_one + left_one});
    }

    long long prod_len_zeros(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long sml = 0, smr = 0;
        long long left_zero = 0, right_zero = 0;
        while (l < r) {
            if (l & 1) {
                sml = max({sml, len_zeros[l], right_zero + left_zeros[l]});
                right_zero = (left_zeros[l] == len[l]) ? right_zero + left_zeros[l] : right_zeros[l];
                l++;
            }
            if (r & 1) {
                --r;
                smr = max({smr, len_zeros[r], left_zero + right_zeros[r]});
                left_zero = (right_zeros[r] == len[r]) ? left_zero + right_zeros[r] : left_zeros[r];
            }
            l >>= 1;
            r >>= 1;
        }

        return max({sml, smr, right_zero + left_zero});
    }

private:
    // k番目のノードの値を子の値で更新
    void update(long long k) {
        assert(1 <= k and k <= N - 1);

        zeros[k] = zeros[2 * k] + zeros[2 * k + 1];
        ones[k] = ones[2 * k] + ones[2 * k + 1];
        left_v[k] = left_v[2 * k];
        right_v[k] = right_v[2 * k + 1];
        left_ones[k] = left_ones[2 * k] + (left_ones[2 * k] == len[2 * k] ? left_ones[2 * k + 1] : 0);
        right_ones[k] = right_ones[2 * k + 1] + (right_ones[2 * k + 1] == len[2 * k + 1] ? right_ones[2 * k] : 0);
        left_zeros[k] = left_zeros[2 * k] + (left_zeros[2 * k] == len[2 * k] ? left_zeros[2 * k + 1] : 0);
        right_zeros[k] = right_zeros[2 * k + 1] + (right_zeros[2 * k + 1] == len[2 * k + 1] ? right_zeros[2 * k] : 0);
        len_ones[k] = max({len_ones[2 * k], len_ones[2 * k + 1], right_ones[2 * k] + left_ones[2 * k + 1]});
        len_zeros[k] = max({len_zeros[2 * k], len_zeros[2 * k + 1], right_zeros[2 * k] + left_zeros[2 * k + 1]});

        len[k] = len[2 * k] + len[2 * k + 1];
    }

    void all_apply_set(long long k, int f) {
        if (f == -1) return;

        zeros[k] = (f == 0) * len[k];
        ones[k] = (f == 1) * len[k];

        left_v[k] = f;
        right_v[k] = f;

        left_ones[k] = (f == 1) * len[k];
        right_ones[k] = (f == 1) * len[k];
        left_zeros[k] = (f == 0) * len[k];
        right_zeros[k] = (f == 0) * len[k];

        len_ones[k] = (f == 1) * len[k];
        len_zeros[k] = (f == 0) * len[k];

        if (k < N) {
            lazy_set[k] = f;
            lazy_flip[k] = false;
        }
    }

    void all_apply_flip(long long k, bool f = true) {
        if (!f) return;

        swap(zeros[k], ones[k]);

        left_v[k] = !left_v[k];
        right_v[k] = !right_v[k];

        swap(left_ones[k], left_zeros[k]);
        swap(right_ones[k], right_zeros[k]);

        swap(len_ones[k], len_zeros[k]);

        if (k < N) {
            lazy_flip[k] ^= f;
            if (lazy_set[k] != -1) lazy_set[k] ^= f;
        }
    }

    // k番目のノードを子に伝搬
    void push(long long k) {
        assert(1 <= k and k <= N * 2 - 1);

        all_apply_flip(2 * k, lazy_flip[k]);
        all_apply_flip(2 * k + 1, lazy_flip[k]);
        lazy_flip[k] = false;

        all_apply_set(2 * k, lazy_set[k]);
        all_apply_set(2 * k + 1, lazy_set[k]);
        lazy_set[k] = -1;
    }
};
