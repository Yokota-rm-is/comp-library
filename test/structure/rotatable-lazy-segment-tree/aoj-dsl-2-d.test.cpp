#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&"

#include "../../../structure/rotatable-lazy-segment-tree.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    RotatableLazySegmentTree<ll> tree(n, (1ll << 31) - 1);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply_set(s, t + 1, x);
        }
        else {
            ll i;
            cin >> i;
            cout << tree.get(i) << endl;
        }
    }

    return 0;
}