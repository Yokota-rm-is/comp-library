#define PROBLEM "https://atcoder.jp/contests/abc304/tasks/abc304_f"

#include "../../../math/eratosthenes.cpp"
#include "../../../math/modint.cpp"

using mint = mint998;

int main() {
    ll N;
    cin >> N;

    string S;
    cin >> S;

    Eratosthenes era(N + 1);

    vll divisors = era.divisors(N);
    divisors.pop_back();
    ll K = divisors.size();

    mint ans = 0;

    vvll A(N);
    vector<mint> B(N);
    rep(k, K) {
        ll i = divisors[k];

        A[i].assign(i, 1);

        rep(j, N) {
            ll a = (S[j] == '#');
            A[i][j % i] &= a;
        }

        mint cnt = 1;
        rep(j, i) cnt *= A[i][j] + 1;
        
        vll div = era.divisors(i);
        div.pop_back();
        fore(j, div) {
            cnt -= B[j];
        }
        B[i] = cnt;
        ans += cnt;
    }

    cout << ans << endl;

    return 0;
} 

