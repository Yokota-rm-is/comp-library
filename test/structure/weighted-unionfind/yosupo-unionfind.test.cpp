#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../../structure/weighted-unionfind.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    WeightedUnionFind<ll> tree(N);
    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll u, v;
            cin >> u >> v;
            tree.unite(u, v, 0);
        }
        else {
            ll u, v;
            cin >> u >> v;
            cout << tree.is_same(u, v) << endl;
        }
    }

    return 0;
}