#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../../../structure/sortable-segment-tree.cpp"


int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ull> a(N);
    rep(i, N) cin >> a[i];

    using Key = ll;
    using S = ll;
    auto op = [](S a, S b) { return a + b; };
    auto e = []() { return 0; };
    using F = bool;
    auto mapping = [](S a, F b) { return a; };

    SegmentTree<Key, S, op, e, F, mapping> tree;

    rep(i, N) tree.insert(i, i, a[i]);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll l, r;
            cin >> l >> r;
            tree.reverse(l, r);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << tree.prod(l, r) << endl;
        }
    }

    return 0;
}