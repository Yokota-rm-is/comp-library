#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "../../../math/modint.cpp"
#include "../../../structure/weighted-unionfind.cpp"

using mint = mint998;

int main() {
    ll N, Q;
    cin >> N >> Q;

    WeightedUnionFind<mint, false, true, false> tree(N);
    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll u, v, x;
            cin >> u >> v >> x;
            if (!tree.is_same(u, v)) {
                tree.unite(u, v, mint(x));
                cout << 1 << endl;
            }
            else {
                mint y = tree.diff(u, v);
                cout << (y == mint(x)) << endl;
            }
        }
        else {
            ll u, v;
            cin >> u >> v;
            if (tree.is_same(u, v)) {
                cout << tree.diff(u, v) << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}