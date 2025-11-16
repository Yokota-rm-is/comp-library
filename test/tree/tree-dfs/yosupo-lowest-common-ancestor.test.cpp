#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../../tree/tree-dfs.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;
    
    TreeDFS<ll> tree(N);

    rep(i, 1, N) {
        ll p;
        cin >> p;
        tree.connect(p, i);
    }

    tree.build(0);

    while (Q--) {
        ll u, v;
        cin >> u >> v;

        cout << tree.lca(u, v) << endl;
    }

    return 0;
}