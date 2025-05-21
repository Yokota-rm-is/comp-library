#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc304/tasks/abc304_f"

#include "../../../other/bit-vector.cpp"
#include "../../../math/modint.cpp"
#include "../../../math/eratosthenes.cpp"

using mint = mint998;

int main() {
    ll N;
    cin >> N;

    string S;
    cin >> S;

    BitVector bv(2 * N, 1);
    rep(i, N) if (S[i] == '.') bv.set(i, 0);

    Eratosthenes era(N);
    vll div = era.divisors(N);

    vector<mint> dp(N + 1, 0);

    rep(d, 1, N + 1) {
        BitVector b(d, 1);

        rep(i, 0, N, d) {
            b &= bv.get(i, i + d);
        }

        ll bc = b.bit_count();
        dp[d] = mint(2).pow(bc);
    }

    fore(d, div) {
        fore(e, era.divisors(d, false)) {
            if (d == e) continue;
            dp[d] -= dp[e];
        }
    }

    mint ans = 0;
    fore(d, div) {
        if (d == N) continue;
        ans += dp[d];
    }

    cout << ans << endl;

    return 0;
} 
