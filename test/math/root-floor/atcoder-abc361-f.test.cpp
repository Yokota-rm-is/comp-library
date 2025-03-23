#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc361/tasks/abc361_f"

#include "../../../math/root-floor.cpp"
#include "../../../math/is-prime.cpp"

int main() {
    ll N;
    cin >> N;

    vector<ll> A(65, 0);
    rep(i, 2, 65) {
        A[i] = root_floor(N, i) - 1;
    }

    ll ans = 0;
    rep(i, 2, 65) {
        if (!is_prime(i)) continue;
        ans += A[i];
    }

    rep(i, 2, 65) {
        if (!is_prime(i)) continue;
        
        rep(j, i + 1, ceil(65, i)) {
            if (!is_prime(j)) continue;
            ans -= A[i * j]; 
        }
    }

    rep(i, 2, 65) {
        if (!is_prime(i)) continue;

        rep(j, i + 1, ceil(65, i)) {
            if (!is_prime(j)) continue;

            rep(k, j + 1, ceil(65, i * j)) {
                if (!is_prime(k)) continue;
                ans += A[i * j * k];
            }
        }
    }

    cout << ans + 1 << endl;
    
    return 0;
} 
