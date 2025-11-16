#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../../../tree/centroid-decomposition.cpp"
#include <atcoder/all>
using atcoder::convolution_ll;

int main() {
    ll N;
    cin >> N;

    vll A(N - 1), B(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i];

    CentroidDecomposition CD(N);
    rep(i, N - 1) {
        CD.connect(A[i], B[i]);
    }

    vvll G = CD.G;

    vll ans(N - 1, 0);

    function<void(ll)> dfs = [&](ll root) {
        ll centroid = CD.find_centroid(root);

        vvll depth(G[centroid].size(), vll(1, 0));
        vll depth_all(1, 1);

        rep(i, G[centroid].size()) {
            if (CD.done[G[centroid][i]]) continue;

            queue<array<ll, 3>> que;
            que.push({G[centroid][i], centroid, 1});
            while (!que.empty()) {
                auto [now, p, d] = que.front();
                que.pop();
                
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

        depth_all = convolution_ll(depth_all, depth_all);
        rep(i, 1, min(depth_all.size(), N)) ans[i - 1] += depth_all[i];

        rep(i, G[centroid].size()) {
            depth[i] = convolution_ll(depth[i], depth[i]);
            rep(j, 1, min(depth[i].size(), N)) ans[j - 1] -= depth[i][j];
        }

        fore(e, G[centroid]) {
            if (CD.done[e]) continue;
            dfs(e);
        }
    };

    dfs(0);
    fore(x, ans) x /= 2;
    cout << ans << endl;

    return 0;
} 