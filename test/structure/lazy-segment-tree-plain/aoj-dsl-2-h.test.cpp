#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&"

#include "../../../structure/lazy-segment-tree-plain.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    LazySegmentTree<ll> tree(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply_add(s, t + 1, x);
        }
        else {
            ll s, t;
            cin >> s >> t;
            cout << tree.prod_min(s, t + 1) << endl;
        }
    }

    return 0;
}