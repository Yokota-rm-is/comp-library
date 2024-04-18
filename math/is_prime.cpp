#pragma once
#include "../base.cpp"

bool is_prime(long long N) {
    if (N < 2) return false;
    if (N == 2) return true;
    if (N % 2 == 0) return false;
    for (long long i = 3; i * i <= N; i += 2) {
        if (N % i == 0) return false;
    }
    return true;
}