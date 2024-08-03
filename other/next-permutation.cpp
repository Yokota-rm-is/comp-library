#pragma once
#include "../base.cpp"

// 順列全列挙
// 計算量: O(N!) (N <= 10)
template<typename T>
auto apply_permutation = [](vector<T> &A) {
    auto ret = 0;

    sort(A.begin(), A.end());
    do {
        
    } while (next_permutation(A.begin(), A.end()));
    // prev_permutation(A.begin(), A.end()); // 逆順

    return ret;
};