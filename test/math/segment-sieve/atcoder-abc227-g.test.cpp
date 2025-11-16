#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc227/tasks/abc227_g"
// https://atcoder.jp/contests/abc227/submissions/67211879

#include "../../../math/segment-sieve.cpp"
#include "../../../math/modint.cpp"

using mint = mint998;

int main() {
    ll N, K;
    cin >> N >> K;

    K = min(N - K, K);
    
    if (K == 0) {
        cout << 1 << endl;
        return 0;
    }

    ll M = 1e6 + 1;

    SegmentSieve sieve_large(N - K + 1, N + 1), sieve_small(0, K + 1);
    vector<ll> factor_cnt(M, 0);
    ll cnt = 0;

    rep(i, N - K + 1, N + 1) {
        auto factors = sieve_large.factorize(i);
        for (auto& [p, exp] : factors) {
            if (p >= M) cnt++;
            else factor_cnt[p] += exp;
        }
    }

    rep(i, 2, K + 1) {
        auto factors = sieve_small.factorize(i);
        for (auto& [p, exp] : factors) {
            factor_cnt[p] -= exp;
        }
    }

    mint ans = 1;
    rep(i, M) {
        ans *= (factor_cnt[i] + 1);
    }
    ans *= mint(2).pow(cnt);

    cout << ans << endl;

    return 0;
} 
