#define PROBLEM "https://atcoder.jp/contests/abc142/tasks/abc142_e"

#include "../../../mystd/mybitset.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll a(M), b(M);
    vector<vll> c(M);

    rep(i, M) {
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);

        rep(j, b[i]) cin >> c[i][j];
    }

    vll d(M);
    rep(i, M) {
        long long bit = 0;
        fore(j, c[i]) {
            bit |= (1 << (j - 1));
        }
        d[i] = bit;
    }

    vector<long long> dp(1 << N,inf64);
    dp[0] = 0;

    auto f = [&](Bitset bit) {
        if (dp[bit] == inf64) return;

        rep(i, M) {
            ll next_bit = bit.to_ll() | d[i];
            long long cost = a[i];

            chmin(dp[next_bit], dp[bit] + cost);
        }
    };

    bitDP(N, f);
    
    ll ans = dp[(1 << N) - 1];
    if (ans == inf64) cout << -1 << endl; 
    else cout << ans << endl;

    return 0;
}