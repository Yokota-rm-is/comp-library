#pragma once
#include "../base.cpp"
#include "../mystd/mybitset.cpp"

// bit全探索
// 計算量: O(N2^N) (N<=20)
auto exhaustive_search = [](long long N) {
    long long ret = 0;

    for (Bitset bit = 0; bit < (1ll << N); ++bit) {
        rep(i, N) {
            if (bit.test(i)) {
                // iがbitに含まれる場合の処理を書く

            }
            else {
                // iがbitに含まれない場合の処理を書く

            }
        }
    }

    return ret;
};

// 順列込みbit全探索
// 計算量: O(N!2^N) (N <= 7)
auto exhaustive_search_with_permutation = [](long long N) {
    long long ret = 0;

    for (Bitset bit = 0; bit < (1ll << N); ++bit) {
        vll v;
        rep(i, N) {
            if (bit.test(i)) {
                // iがbitに含まれる場合の処理を書く
                v.push_back(i);

            }
            else {
                // iがbitに含まれない場合の処理を書く

            }
        }

        do {
            
        } while (next_permutation(v.begin(), v.end()));
    }

    return ret;
};