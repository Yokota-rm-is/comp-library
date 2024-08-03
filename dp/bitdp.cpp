#pragma once
#include "../base.cpp"
#include "../mystd/mybitset.cpp"

// bitDP
// 計算量: O(2^N) (N<=19)
auto bitDP = [](long long N) {
    using T = long long;
    vector<T> dp(1 << N,inf64);
    dp[0] = 0;

    for (Bitset bit = 0; bit < (1ll << N); ++bit) {
        if (dp[bit] == inf64) continue;

        rep(i, N) {
            if (bit.test(i)) continue;

            T cost = 0;

            Bitset next_bit = bit;
            next_bit.set(i);

            chmin(dp[next_bit], dp[bit] + cost);
        }
    }

    return dp[(1 << N) - 1];
};