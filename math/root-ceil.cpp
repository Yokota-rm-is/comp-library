#pragma once
#include "../base.cpp"

unsigned long long root_ceil(unsigned long long x, unsigned long long n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    __int128_t x_ = x;

    unsigned long long left = 0, right = ceil(pow((double)numeric_limits<unsigned long long>::max(), 1. / n)) + 1;
  
    while (right - left > 1) {
        unsigned long long mid = midpoint(left, right);
        __int128_t y = binpow<__int128_t>(mid, n);
        if (y >= x_) right = mid;
        else left = mid;
    }
    
    return right;
}