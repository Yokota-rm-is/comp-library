#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../../tree/euler-tour-path-query-with-segment-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    EulerTourPath<ll> tree(N);

    rep(i, 1, N) {
        ll p;
        cin >> p;
        tree.connect(i, p);
    }

    tree.build(0);

    while (Q--) {
        ll u, v;
        cin >> u >> v;

        cout << tree.lca(u, v) << endl;
    }

    return 0;
}