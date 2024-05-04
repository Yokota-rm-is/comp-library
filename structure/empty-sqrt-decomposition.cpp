#pragma once
#include "../base.cpp"


template<typename T, typename F>
struct EmptySqrtDecomposition {
    long long _N, N, sqrtN, K;
    
    vector<T> data;
    vector<T> bucket;
    vector<F> lazy;

    T e = inf64, id = inf64;

    EmptySqrtDecomposition(long long n) : _N(n) {
        vector<T> v(n, 0);
        init(v);
    }

    EmptySqrtDecomposition(long long n, T a) : _N(n) {
        vector<T> v(n, a);
        init(v);
    }

    EmptySqrtDecomposition(vector<T> &v) : _N(v.size()) {
        init(v);
    }

    void init(vector<T> &a) {
        sqrtN = 1;
        while ((sqrtN + 1) * (sqrtN + 1) < _N) ++sqrtN;

        K = (_N + sqrtN - 1) / sqrtN;
        N = K * sqrtN;
        
        data.assign(N, e);
        rep(i, _N) data[i] = a[i];

        bucket.assign(K, e);
        rep(k, K) update(k);

        lazy.assign(K, id);
    }

    void push(long long k) {
        long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

        rep(i, lk, rk) {
            if (lazy[k] != id) data[i] += lazy[k]; // 適切に書き換える
        }

        lazy[k] = id;
    }

    void update(long long k) {
        long long lk = k * sqrtN, rk = (k + 1) * sqrtN;
        
        bucket[k] = e;

        rep(i, lk, rk) {
            bucket[k] += data[i]; // 適切に書き換える
        }
    }

    void apply(long long p, T x) {
        push(p / sqrtN);
        data[p] += x; // 適切に書き換える
        update(p / sqrtN);
    }

    // [l, r)
    void apply(long long l, long long r, T x) {
        rep(k, K) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                if (lazy[k] == id) lazy[k] = x;
                else lazy[k] += x;  // 適切に書き換える

                bucket[k] += x;  // 適切に書き換える
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    data[i] += x;  // 適切に書き換える
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
    T prod(long long l, long long r) {
        T ret = 0; // 適切に書き換える

        rep(k, K) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                ret += bucket[k]; // 適切に書き換える
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    ret += data[i]; // 適切に書き換える
                }
                update(k);
            }
        }

        return ret;
    }
};