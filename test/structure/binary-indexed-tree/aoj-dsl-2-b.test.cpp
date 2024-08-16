#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&"

#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    BinaryIndexedTree<ll> tree(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y;
            cin >> x >> y;
            tree.add(x - 1, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << tree.sum(x - 1, y) << endl;
        }
    }

    return 0;
}