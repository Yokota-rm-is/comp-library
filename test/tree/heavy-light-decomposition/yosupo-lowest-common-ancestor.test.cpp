#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../../tree/heavy-light-decomposition.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    HeavyLightDecomposition hld(N);

    rep(i, 1, N) {
        ll p;
        cin >> p;
        hld.connect(i, p);
    }

    hld.build(0);

    while (Q--) {
        ll u, v;
        cin >> u >> v;

        cout << hld.lca(u, v) << endl;
    }

    return 0;
}