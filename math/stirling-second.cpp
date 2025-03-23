#pragma once
#include "../base.cpp"

template <long long MOD = -1>
struct StirlingSecond {
    long long N, K;
    vector<vector<long long>> dp;
    vector<long long> fact, inv, fact_inv;

    StirlingSecond(long long n) : N(n), K(n) {
        assert(n <= 26 or MOD != -1);
        init();
    }

    StirlingSecond(long long n, long long k) : N(n), K(min(k, n)) {
        assert(n <= 26 or MOD != -1);
        init();
    }

    void init() {
        if (N * K <= 1e7) {
            dp = vector<vector<long long>>(N + 1, vector<long long>(K + 1, 0));
            dp[0][0] = 1;
            rep(i, 1, N + 1) {
                rep(j, 1, N + 1) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
                    if (MOD != -1) dp[i][j] %= MOD;
                }
            }
        }
        else {
            fact = vector<long long>(N + 1, 0);
            inv = vector<long long>(N + 1, 0);
            fact_inv = vector<long long>(N + 1, 0);

            fact[0] = fact[1] = 1;
            fact_inv[0] = fact_inv[1] = 1;
            inv[1] = 1;
            
            rep(i, 2, N + 1) {
                fact[i] = fact[i - 1] * i % MOD;
                inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
                fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
            }
        }
    }

    long long get(long long k) {
        return get(N, k);
    }

    long long get(long long n, long long k) {
        assert(n <= N);
        if (k > n) return 0;
        assert(k <= K);

        if (N * K <= 1e7) {
            return dp[n][k];
        }
        else {
            long long ret = 0;
            rep(i, k + 1) {
                if ((k - i) % 2 == 0) {
                    ret += MOD + (nCk(k, i) * pow(i, n) % MOD);
                    ret %= MOD;
                }
                else {
                    ret += MOD - (nCk(k, i) * pow(i, n) % MOD);
                    ret %= MOD;
                }
            }
            return ret * fact_inv[k] % MOD;
        }
    }

    long long operator()(long long k) {
        return get(N, k);
    }

    long long operator()(long long n, long long k) {
        return get(n, k);
    }

    long long nCk(long long n, long long k) {
        assert(!(n < k));
        assert(!(n < 0 || k < 0));
        assert(MOD != -1);

        return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
    }

    long long pow(long long x, long long n) {
        assert(MOD != -1);

        long long ret = 1;
        while (n) {
            if (n & 1) ret = ret * x % MOD;
            x = x * x % MOD;
            n >>= 1;
        }
        return ret;
    }
};