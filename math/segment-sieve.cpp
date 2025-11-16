#pragma once
#include "../base.cpp"

// 半開区間[l, r)に対する区間篩ライブラリ
// 計算量: D = r - lとして，O((D + sqrt(r)) loglog(r))
struct SegmentSieve {
    vector<bool> is_prime_small, is_prime_large;
    vector<long long> primes;
    vector<vector<pair<long long, long long>>> prime_factors;
    long long l, r, sqrt_r;

    SegmentSieve(long long l, long long r) : l(l), r(r) {
        assert(l >= 0 and r > l);
        sqrt_r = sqrt_ceil(r);
        is_prime_small.assign(sqrt_r, true);
        is_prime_large.assign(r - l, true);
        prime_factors.resize(r - l);
        
        solve();
    }

    void solve() {
        is_prime_small[0] = is_prime_small[1] = false;

        rep(i, 2, sqrt_r) {
            if (!is_prime_small[i]) continue;

            for (long long j = i * i; j < sqrt_r; j += i) {
                is_prime_small[j] = false;
            }
        }

        rep(i, 2, sqrt_r) {
            if (!is_prime_small[i]) continue;

            long long start = max(i, (l + i - 1) / i);
            for (long long j = start * i; j < r; j += i) {
                is_prime_large[j - l] = false;

                prime_factors[j - l].emplace_back(i, 0);
            }
        }

        rep(i, max(l, 2), r) {
            if (is_prime_large[i - l]) {
                primes.push_back(i);
                prime_factors[i - l].emplace_back(i, 1);
            }
            else {
                ll x = i;

                fore(p, prime_factors[i - l]) {
                    while (x % p.first == 0) {
                        x /= p.first;
                        p.second++;
                    }
                }

                if (x > 1) prime_factors[i - l].emplace_back(x, 1);
            }
        }
    }

    bool is_prime(long long x) {
        assert(l <= x and x < r);
        return is_prime_large[x - l];
    }

    vector<long long> get_primes() {
        return primes;
    }

    vector<pair<long long, long long>> factorize(long long x) {
        return prime_factors[x - l];
    }

    long long sqrt_ceil(long long x) {
        __uint128_t x_ = x;

        unsigned long long left = 0, right = ceil(pow((double)numeric_limits<unsigned long long>::max(), 1. / 2)) + 1;
    
        while (right - left > 1) {
            unsigned long long mid = left + (right - left) / 2;
            __uint128_t y = binpow<__uint128_t>(mid, 2);
            if (y >= x_) right = mid;
            else left = mid;
        }
        
        return right;
    }
};