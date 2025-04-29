#pragma once
#include "../base.cpp"

unsigned long long root_floor(unsigned long long x, unsigned long long n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    unsigned long long left = 0, right = floor(pow((double)numeric_limits<unsigned long long>::max(), 1. / n));
    __int128_t x_ = x;
    __int128_t y_ = binpow<__int128_t>(right, n);
    if (y_ <= x_) return right;
  
    while (right - left > 1) {
        unsigned long long mid = midpoint(left, right);
        __int128_t y = binpow<__int128_t>(mid, n);
        if (y <= x_) left = mid;
        else right = mid;
    }
    
    return left;
}