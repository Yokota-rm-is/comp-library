#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&"

#include "../../../structure/sortable-segment-tree.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using Key = ll;
    using S = ll;
    auto op = [](S a, S b) { return min(a, b); };
    auto e = []() { return inf64; };
    using F = ll;
    auto mapping = [](S a, F b) { return b; };

    SegmentTree<Key, S, op, e, F, mapping> tree;
    rep(i, n) {
        tree.insert(i, i, (1ll << 31) - 1);
    }

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y;
            cin >> x >> y;
            tree.apply(x, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << tree.prod(x, y + 1) << endl;
        }
    }

    return 0;
}