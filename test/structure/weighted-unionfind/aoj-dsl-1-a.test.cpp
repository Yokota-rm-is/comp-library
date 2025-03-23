#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&"

#include "../../../structure/weighted-unionfind.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    WeightedUnionFind<ll> tree(n);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y;
            cin >> x >> y;
            tree.unite(x, y, 0);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << tree.is_same(x, y) << endl;
        }
    }

    return 0;
}