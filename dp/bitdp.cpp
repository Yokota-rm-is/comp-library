#pragma once
#include "../base.cpp"

// bitDP
// 計算量: O(2^N) (N<=19)
auto bitDP = [](long long N, long long M) {
    using T = long long;
    vector<T> dp(1 << N,inf64);
    dp[0] = 0;

    rep(bit, (1 << N)) {
        if (dp[bit] == inf64) continue;

        rep(i, M) {
            long long next = 0;
            if (bit & (1 << next)) continue;

            T cost = 0;

            long long next_bit = bit | (1 << next);

            chmin(dp[next_bit], dp[bit] + cost);
        }
    }

    return dp[(1 << N) - 1];
};