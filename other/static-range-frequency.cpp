#pragma once
#include "../base.cpp"

template <typename T> 
struct StaticRangeFrequency {
    map<T, vector<long long>> mp;

    StaticRangeFrequency(const vector<T>& A) {
        rep(i, A.size()) mp[A[i]].push_back(i);
    }

    // [l, r) の範囲に x が何個あるかを返す
    // 計算量: O(log|max(A)|logN)
    long long count(long long l, long long r, T x) {
        if (!mp.contains(x)) return 0;

        auto left = lower_bound(mp[x].begin(), mp[x].end(), l);
        auto right = lower_bound(mp[x].begin(), mp[x].end(), r);
        return distance(left, right);
    }
};