#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/yahoo-procon2018-final-open/tasks/yahoo_procon2018_final_c"
// https://atcoder.jp/contests/yahoo-procon2018-final-open/submissions/68436981

#include "../../../tree/centroid-decomposition.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll A(N - 1), B(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i];
    --A, --B;

    vll V(Q), K(Q);
    rep(i, Q) cin >> V[i] >> K[i];
    --V;

    CentroidDecomposition CD(N);
    rep(i, N - 1) {
        CD.connect(A[i], B[i]);
    }

    vvll G = CD.G;

    vector<vector<pll>> queries(N);
    rep(i, Q) {
        queries[V[i]].emplace_back(K[i], i);
    }

    vll ans(Q, 0);
    function<void(ll)> dfs = [&](ll root) {
        ll centroid = CD.find_centroid(root);

        vector<array<ll, 3>> belongs;
        vvll depth(G[centroid].size(), vll(1, 0));
        vll depth_all(1, 1);

        rep(i, G[centroid].size()) {
            if (CD.done[G[centroid][i]]) continue;

            queue<array<ll, 3>> que;
            que.push({G[centroid][i], centroid, 1});
            while (!que.empty()) {
                auto [now, p, d] = que.front();
                que.pop();
                
                belongs.push_back({now, i, d});
                if (depth[i].size() <= d) depth[i].push_back(0);
                ++depth[i][d];

                if (depth_all.size() <= d) depth_all.push_back(0);
                ++depth_all[d];

                for (auto next : G[now]) {
                    if (next == p) continue;
                    if (CD.done[next]) continue;
                    que.push({next, now, d + 1});
                }
            }
        }

        for (auto& [v, i, d] : belongs) {
            for (auto [k, idx] : queries[v]) {
                ll x = k - d;

                if (x >= 0 and depth_all.size() > x) {
                    ans[idx] += depth_all[x] - (depth[i].size() > x ? depth[i][x] : 0);
                }
            }
        }

        for (auto [k, idx] : queries[centroid]) {
            ll x = k;

            if (x >= 0 and depth_all.size() > x) {
                ans[idx] += depth_all[x];
            }
        }

        fore(e, G[centroid]) {
            if (CD.done[e]) continue;
            dfs(e);
        }
    };

    dfs(0);

    rep(i, Q) {
        cout << ans[i];
        if (i < Q - 1) cout << "\n";
    }
    cout << endl;

    return 0;
} 