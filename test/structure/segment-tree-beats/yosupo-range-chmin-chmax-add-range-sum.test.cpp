#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../../../structure/segment-tree-beats.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    SegmentTreeBeats<ll> tree(a);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll l, r, b;
            cin >> l >> r >> b;
            tree.apply_chmin(l, r, b);
        }
        if (t == 1) {
            ll l, r, b;
            cin >> l >> r >> b;
            tree.apply_chmax(l, r, b);
        }
        if (t == 2) {
            ll l, r, b;
            cin >> l >> r >> b;
            tree.apply_add(l, r, b);
        }
        if (t == 3) {
            ll l, r;
            cin >> l >> r;
            cout << tree.prod_sum(l, r) << endl;
        }
    }
}