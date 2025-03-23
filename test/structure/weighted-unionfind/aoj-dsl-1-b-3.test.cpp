#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&"

#include "../../../structure/weighted-unionfind.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    WeightedUnionFind<ll, false, true, false> tree(n);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y, z;
            cin >> x >> y >> z;
            tree.unite(x, y, z);
        }
        else {
            ll x, y;
            cin >> x >> y;
            if (tree.is_same(x, y)) cout << tree.diff(x, y) << endl;
            else cout << "?" << endl;
        }
    }

    return 0;
}