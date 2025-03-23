#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&"

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
            tree.apply_add(s - 1, t, x);
        }
        else {
            ll s, t;
            cin >> s >> t;
            cout << tree.prod_sum(s - 1, t) << endl;
        }
    }

    return 0;
}