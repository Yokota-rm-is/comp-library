#pragma once
#include "../base.cpp"

long long root_ceil(long long x, long long n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    __int128_t x_ = x;

    long long left = 0, right = llround(pow((double)INF64, 1. / n)) + 1;
  
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        __int128_t y = binpow<__int128_t>(mid, n);
        if (y >= x_) right = mid;
        else left = mid;
    }
    
    return right;
}