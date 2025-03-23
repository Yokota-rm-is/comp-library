#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&"

#include "../../../structure/lazy-segment-tree-plain.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    LazySegmentTree<ll> tree(n, (1ll << 31) - 1);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y;
            cin >> x >> y;
            tree.apply_set(x, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << tree.prod_min(x, y + 1) << endl;
        }
    }

    return 0;
}