#define PROBLEM "https://atcoder.jp/contests/abc190/tasks/abc190_e"

#include "../../../graph/tsp.cpp"
#include "../../../graph/bfs.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll A(M), B(M);

    rep(i, M) cin >> A[i] >> B[i];

    ll K;
    cin >> K;
    vll C(K);
    rep(i, K) cin >> C[i];

    vll D(N, -1);
    rep(i, K) D[C[i] - 1] = i;

    BFS bfs(N, false);
    rep(i, M) {
        ll a = A[i] - 1, b = B[i] - 1;
        bfs.connect(a, b);
    }

    TSP tsp(K, false);

    fore(u, C) {
        bfs(u - 1);

        fore(v, C) {
            if (u == v) continue;
            if (!bfs.reach(v - 1)) continue;

            ll w = bfs.depth[v - 1];
            // cout << D[u - 1] << " " << D[v] << endl;
            tsp.connect(D[u - 1], D[v - 1], w);
        }

        bfs.init();
    }

    rep(i, tsp.V) tsp.dp[(1 << i)][i] = 1;

    rep(bit, (1 << tsp.V)) {
        rep(now, tsp.V) {
            if (tsp.dp[bit][now] > inf64 - 1) continue;

            fore(edge, tsp.G[now]) {
                long long next = edge.to;
                if (bit & (1 << next)) continue;

                long long next_bit = bit | (1 << next);

                if (chmin(tsp.dp[next_bit][next], tsp.dp[bit][now] + edge.weight)) {
                    tsp.prev[next_bit][next] = now;
                    chmax(tsp.max_visit, bit_count(next_bit));
                }
            }
        }
    }

    ll ans = min(tsp.dp[(1 << K) - 1]);

    if (ans == inf64) cout << -1 << endl; 
    else cout << ans << endl;

    return 0;
}