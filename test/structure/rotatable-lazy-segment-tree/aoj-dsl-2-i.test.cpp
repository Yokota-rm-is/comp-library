#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I&"

#include "../../../structure/rotatable-lazy-segment-tree.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    RotatableLazySegmentTree<ll> tree(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply_set(s, t + 1, x);
        }
        else {
            ll s, t;
            cin >> s >> t;
            cout << tree.prod_sum(s, t + 1) << endl;
        }
    }

    return 0;
}