#pragma once
#include "../base.cpp"

template <long long MOD = -1>
struct Bell {
    long long N, K;
    vector<vector<long long>> dp, cum;
    vector<long long> table, inv, fact_inv;

    Bell(long long n) : N(n), K(n) {
        assert(n <= 26 or MOD != -1);
        init();
    }

    Bell(long long n, long long k) : N(n), K(min(k, n)) {
        assert(n <= 26 or MOD != -1);
        init();
    }

    void init() {
        if (N * K <= 1e7) {
            dp = vector<vector<long long>>(N + 1, vector<long long>(K + 1, 0));
            cum = vector<vector<long long>>(N + 1, vector<long long>(1, 0));
            dp[0][0] = 1;
            rep(i, 1, N + 1) {
                rep(j, 1, K + 1) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
                    if (MOD != -1) dp[i][j] %= MOD;
                }
            }
        }
        else {
            table = vector<long long>(N + 1, 0);
            inv = vector<long long>(N + 1, 0);
            fact_inv = vector<long long>(N + 1, 0);

            fact_inv[0] = fact_inv[1] = 1;
            inv[1] = 1;
            rep(i, 2, N + 1) {
                inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
                fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
            }

            table[0] = 1;
            rep(i, 1, N + 1) {
                table[i] = 0;
                if (i % 2 == 1) table[i] = (table[i - 1] + (MOD - fact_inv[i])) % MOD;
                else table[i] = (table[i - 1] + fact_inv[i]) % MOD;
            }
        }
    }

    long long get(long long k) {
        return get(N, k);
    }

    long long get(long long n, long long k) {
        assert(n <= N);
        chmin(k, n);
        assert(k <= K);

        if (N * K <= 1e7) {
            if (cum[n].size() <= k) {
                rep(i, cum[n].size() - 1, k) {
                    cum[n].push_back((cum[n].back() + dp[n][i + 1]));
                    if (MOD != -1) cum[n][i + 1] %= MOD;
                }
            }
            return cum[n][k];
        }
        else {
            long long ret = 0;
            rep(i, k + 1) {
                ret += (pow(i, n) * fact_inv[i] % MOD) * table[k - i] % MOD;
                ret %= MOD;
            }
            return ret;
        }
    }

    long long operator()(long long k) {
        return get(N, k);
    }

    long long operator()(long long n, long long k) {
        return get(n, k);
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