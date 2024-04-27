#define PROBLEM "https://atcoder.jp/contests/abc190/tasks/abc190_e"

#include "../../../dp/bitdp.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll A(M), B(M);

    rep(i, M) cin >> A[i] >> B[i];

    ll K;
    cin >> K;
    vll C(K);
    rep(i, K) cin >> C[i];

    vector<vll> G(N);
    rep(i, M) {
        ll a = A[i] - 1, b = B[i] - 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vll D(N, -1);
    rep(i, K) D[C[i]] = i;

    vector dp(1 << K, vector<long long>(K, inf64));
    rep(i, K) dp[1 << i][i] = 1;

    rep(bit, 1, (1 << K)) {
        rep(i, K) {
            if (dp[bit][i] == inf64) continue;

            fore(j, G[i]) {
                if (D[j] < 0) {
                    fore(k, G[j]) {
                        if (!st.contains(k)) continue;
                        if ()
                    }
                }
                if (bit & (1 << j)) continue;

                ll next_bit = bit | j;
                chmin(dp[next_bit][j], dp[bit][i] + 1);
                
                rep(k, N) {
                    if (bit & (1 << k)) {
                        chmin(dp[next_bit][k], dp[next_bit][j] + 1);
                    }
                }
            }
        }
    }

    ll ans = inf64;
    rep(bit, (1 << N)) {
        if ((bit & flg) == flg) {
            rep(i, N) chmin(ans, dp[bit][i]);
        } 
    }

    if (ans == inf64) cout << -1 << endl; 
    else cout << ans << endl;

    return 0;
}