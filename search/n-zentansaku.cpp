#include "../base.cpp"

struct ExhaustiveSearch {
    long long N, M;

    ExhaustiveSearch(long long n, long long m) : N(n), M(m) {};

    auto operator() () {
        long long ret = 0;
        vector<ll> v(N);

        for (long long bit = 0; bit < binpow(M, N); ++bit) {
            // v[i]:= 0 ~ M - 1の状態が格納される
            ll x = bit;
            rep(i, N) {
                v[i] = x % M;
                x /= M;
            }

            // sort(v.begin(), v.end());
            // do {
                
            // } while (next_permutation(v.begin(), v.end()));
            // prev_permutation(v); // 逆順
        }
    }
};

auto exhaustive_search = [](long long N, long long base) {
    long long ret = 0;
    vector<ll> v(N);

    for (long long bit = 0; bit < binpow(base, N); ++bit) {
        ll x = bit;
        rep(i, N) {
            v[i] = x % base;
            x /= base;
        }

        rep(i, N) {
            if (v[i] == 0) {
                // i番目が0の処理を書く

            }
            else if (v[i] == 1) {
                // i番目が1の処理を書く

            }
            else {
                // i番目が2の処理を書く

            }
        }
    }

    return ret;
};