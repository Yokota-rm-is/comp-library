#pragma once
#include "../base.cpp"

map<long long, long long> prime_factorization(long long N) {
    map<long long, long long> ret;
    while (N % 2 == 0) {
        ret[2]++;
        N /= 2;
    }

    for (long long i = 3; i * i <= N; i += 2) {
        while (N % i == 0) {
            ret[i]++;
            N /= i;
        }
    } 
    if (N > 1) ret[N]++;
    return ret;
}