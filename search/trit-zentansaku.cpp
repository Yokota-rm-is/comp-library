#include "../base.cpp"

// bit全探索 3進数ver.
// 計算量: O(N3^N) (N<=13)
auto exhaustive_search = [](long long N) {
    long long ret = 0;
    vector<ll> v(N);

    for (long long bit = 0; bit < binpow(3ll, N); ++bit) {
        ll x = bit;
        rep(i, N) {
            v[i] = x % 3;
            x /= 3;
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

// 順列込みbit全探索 3進数ver.
// 計算量: O(N!3^N) (N<=6)
auto exhaustive_search_with_permutation = [](long long N) {
    long long ret = 0;
    vector<ll> v(N);

    for (long long bit = 0; bit < binpow(3ll, N); ++bit) {
        ll x = bit;
        rep(i, N) {
            v[i] = x % 3;
            x /= 3;
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

        // do {
            
        // } while (next_permutation(.begin(), .end()));
    }

    return ret;
};