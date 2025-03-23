#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&"

#include "../../../structure/rotatable-binary-indexed-tree.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    RotatableBinaryIndexedTree<ll> tree(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.add(s - 1, t, x);
        }
        else {
            ll i;
            cin >> i;
            cout << tree.get(i - 1) << endl;
        }
    }

    return 0;
}