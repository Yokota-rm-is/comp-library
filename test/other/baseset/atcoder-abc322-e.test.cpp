#define PROBLEM "https://atcoder.jp/contests/abc322/tasks/abc322_e"

#include "../../../other/baseset.cpp"

int main() {
    ll N, K, P;
    cin >> N >> K >> P;

    vll C(N);
    vvll A(N, vll(K));
    rep(i, N) {
        cin >> C[i];
        rep(j, K) cin >> A[i][j];
    }

    vvll dp(N + 1, vll(binpow(P + 1, K), inf64));
    dp[0][0] = 0;

    rep(i, N) {
        for (Baseset idx(P + 1); idx < (ll)dp[i].size(); ++idx) {
            if (dp[i][idx] == inf64) continue;
            
            chmin(dp[i + 1][idx], dp[i][idx]);
            
            Baseset next_idx(idx);
            next_idx.add(A[i]);
            chmin(dp[i + 1][next_idx], dp[i][idx] + C[i]);
        }
    }

    ll ans = dp.back().back();
    if (ans == inf64) ans = -1;

    cout << ans << endl;

    return 0;
} 
