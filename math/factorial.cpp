#pragma once
#include "../base.cpp"

template<long long MOD = 998244353, long long MAX = 510000>
struct Factorial {
    vector<long long> fact, finv;

    Factorial() : fact(MAX), finv(MAX) {
        fact[0] = fact[1] = 1;
        finv[0] = finv[1] = 1;
        vector<long long> inv_(MAX);
        inv_[1] = 1;
        for (int i = 2; i < MAX; i++){
            fact[i] = fact[i - 1] * i % MOD;
            inv_[i] = MOD - inv_[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv_[i] % MOD;
        }
    };

    long long operator() (long long n) {
        if (n < 0) return 0;
        return fact[n];
    }

    long long inv(long long n) {
        if (n < 0) return 0;
        return finv[n];
    }
};