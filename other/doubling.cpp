#pragma once
#include "../base.cpp"

struct Doubling {
    vector<vector<long long>> dp{};
    long long N, maxK;
    long long logK;
    vector<long long> to;

    Doubling(vector<long long> &A, long long maxK): N(A.size()), maxK(maxK) {
        logK = 1;
        while ((1ll << logK) <= maxK) ++logK;

        dp.assign(logK, vector<long long>(N));

        rep(i, N) {
            dp.front()[i] = A[i];
        }

        rep(k, logK - 1) {
            rep(i, N) {
                ll next = dp[k][i];
                dp[k + 1][i] = dp[k][next];
            }
        }
    }

    long long get(long long start, long long K) {
        long long now = start;

        for (long long k = 0; K > 0; ++k) {
            if (K & 1) now = dp[k][now];
            K >>= 1;
        }

        return now;
    }
};