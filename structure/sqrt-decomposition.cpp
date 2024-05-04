#pragma once
#include "../base.cpp"

template<typename T, typename F>
struct SqrtDecomposition {
    long long _N, N, sqrtN, K;
    
    vector<T> data;
    vector<T> bucket_sum, bucket_min, bucket_max;
    vector<F> lazy_add, lazy_lower, lazy_upper;
    vector<vector<T>> sorted, accumulated;

    T e = inf64, id = inf64;

    SqrtDecomposition(long long n) : _N(n) {
        vector<T> v(n, 0);
        init(v);
    }

    SqrtDecomposition(long long n, T a) : _N(n) {
        vector<T> v(n, a);
        init(v);
    }

    SqrtDecomposition(vector<T> &v) : _N(v.size()) {
        init(v);
    }

    void init(vector<T> &a) {
        sqrtN = 1;
        while ((sqrtN + 1) * (sqrtN + 1) < _N) ++sqrtN;

        K = (_N + sqrtN - 1) / sqrtN;
        N = K * sqrtN;
        
        data.assign(N, e);
        rep(i, _N) data[i] = a[i];

        bucket_sum.assign(K, 0);
        bucket_min.assign(K, inf64);
        bucket_max.assign(K, -inf64);
        // sorted.resize(K);
        // accumulated.resize(K);
        rep(k, K) update(k);

        lazy_add.assign(K, id);
        lazy_lower.assign(K, id);
        lazy_upper.assign(K, id);

        // rep(i, K) {
        //     rep(j, sqrtN) sorted[i].push_back(data[i * sqrtN + j]);
        //     sort(sorted[i]);

        //     accumulated[i].push_back(0);
        //     rep(j, sqrtN) accumulated[i].push_back(accumulated[i][j] + sorted[i][j]);
        // }
    }

    void push(long long k) {
        long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

        rep(i, lk, rk) {
            if (lazy_add[k] != id) data[i] += lazy_add[k];
            if (lazy_upper[k] != id) chmin(data[i], lazy_upper[k]);
            if (lazy_lower[k] != id) chmax(data[i], lazy_lower[k]);
        }

        lazy_add[k] = id;
        lazy_upper[k] = id;
        lazy_lower[k] = id;
    }

    void update(long long k) {
        long long lk = k * sqrtN, rk = (k + 1) * sqrtN;
        
        bucket_sum[k] = 0;
        bucket_min[k] = inf64;
        bucket_max[k] = -inf64;
        // sorted[k].resize(0);
        // accumulated[k].assign(1, 0);

        rep(i, lk, rk) {
            bucket_sum[k] += data[i];
            chmin(bucket_min[k], data[i]);
            chmax(bucket_max[k], data[i]);
            // sorted[k].push_back(data[i]);
        }

        // sort(sorted[k]);
        // rep(i, sqrtN) accumulated[k].push_back(accumulated[k][i] + sorted[k][i]);
    }

    void apply_add(long long p, T x) {
        push(p / sqrtN);
        data[p] += x;
        update(p / sqrtN);
    }

    // [l, r)
    void apply_add(long long l, long long r, T x) {
        rep(k, K) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                if (lazy_add[k] == id) lazy_add[k] = x;
                else lazy_add[k] += x;

                if (lazy_lower[k] != id) lazy_lower[k] += x;
                if (lazy_upper[k] != id) lazy_upper[k] += x;

                bucket_sum[k] += x * sqrtN;
                bucket_max[k] += x;
                bucket_min[k] += x;
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    data[i] += x;
                }
                update(k);
            }
        }
    }

    void apply_set(long long p, T x) {
        push(p / sqrtN);
        data[p] = x;
        update(p / sqrtN);
    }

    void apply_set(long long l, long long r, T x) {
        rep(k, K) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                lazy_upper[k] = x;
                lazy_lower[k] = x;

                bucket_sum[k] = x * sqrtN;
                bucket_max[k] = x;
                bucket_min[k] = x;
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    data[i] = x;
                }
                update(k);
            }
        }
    }

    void apply_chmin(long long p, T x) {
        push(p / sqrtN);
        chmin(data[p], x);
        update(p / sqrtN);
    }

    void apply_chmin(long long l, long long r, T x) {
        rep(k, K) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                if (lazy_upper[k] == id) lazy_upper[k] = x;
                else chmin(lazy_upper[k], x);
                
                if (lazy_lower[k] != id and lazy_lower[k] > lazy_upper[k]) lazy_lower[k] = lazy_upper[k];

                // long long key = x;
                // if (lazy_add[k] != id) key += lazy_add[k];
                // auto p = upper_bound(sorted[k].begin(), sorted[k].end(), key);
                // long long d = distance(sorted.begin(), p);

                // bucket_sum[k] += key * (sqrtN - d) - (accumulated[k][sqrtN] - accumulated[k][d]);
                chmin(bucket_max[k], x);
                chmin(bucket_min[k], x);
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    chmin(data[i], x);
                }
                update(k);
            }
        }
    }

    void apply_chmax(long long p, T x) {
        push(p / sqrtN);
        chmax(data[p], x);
        update(p / sqrtN);
    }

    void apply_chmax(long long l, long long r, T x) {
        rep(k, K) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                if (lazy_lower[k] == id) lazy_lower[k] = x;
                else chmax(lazy_lower[k], x);
                
                if (lazy_upper[k] != id and lazy_upper[k] < lazy_lower[k]) lazy_upper[k] = lazy_lower[k];

                // long long key = x;
                // if (lazy_add[k] != id) key += lazy_add[k];
                // auto p = upper_bound(sorted[k].begin(), sorted[k].end(), key);
                // long long d = distance(sorted.begin(), p);

                // bucket_sum[k] += key * d - accumulated[k][d];                

                chmax(bucket_max[k], x);
                chmax(bucket_min[k], x);
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    chmax(data[i], x);
                }
                update(k);
            }
        }
    }

    T get(long long p) {
        push(p / sqrtN);
        update(p / sqrtN);

        return data[p];
    }
    
    // [l, r)
    T prod_sum(long long l, long long r) {
        T ret = 0;

        rep(k, K) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                ret += bucket_sum[k];
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    ret += data[i];
                }
                update(k);
            }
        }

        return ret;
    }

    // [l, r)
    T prod_min(long long l, long long r) {
        T ret = inf64;

        rep(k, K) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;

            if (l <= lk && rk <= r) {
                chmin(ret, bucket_min[k]);
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    chmin(ret, data[i]);
                }
                update(k);
            }
        }

        return ret;
    }

    // [l, r)
    T prod_max(long long l, long long r) {
        T ret = -inf64;

        rep(k, K) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                chmax(ret, bucket_max[k]);
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    chmax(ret, data[i]);
                }
                update(k);
            }
        }

        return ret;
    }
};
