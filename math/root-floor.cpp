#pragma once
#include "../base.cpp"

long long root_floor(long long x, long long n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    long long left = 1, right = llround(pow((double)INF64, 1. / n));
    __int128_t x_ = x;
    __int128_t y_ = binpow<__int128_t>(right, n);
    if (y_ <= x_) return right;
  
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        long long y = binpow(mid, n);
        if (y <= x) left = mid;
        else right = mid;
    }
    
    return left;
}