#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../../../structure/undo-unionfind.cpp"


int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<array<ll, 4>> A;
    rep(i, Q) {
        ll t, k, u, v;
        cin >> t >> k >> u >> v;
        A.push_back({t, k + 1, u, v});
    }

    vector<vector<array<ll, 5>>> G(Q + 1);
    rep(i, Q) {
        auto [t, k, u, v] = A[i];
        G[k].push_back({t, k, u, v, i});
    }

    UndoUnionFind tree(N);
    vll ans(Q, -1);

    auto dfs = [&](auto f, ll now) -> void {
        fore(g, G[now]) {
            auto [t, k, u, v, i] = g;

            if (t == 0) {
                tree.unite(u, v);
                f(f, i + 1);
                tree.undo();
            }
            else {
                ans[i] = tree.is_same(u, v);
            }
        }
    };

    dfs(dfs, 0);
    rep(i, Q) {
        if (ans[i] < 0) continue;
        cout << ans[i] << endl;
    }
}