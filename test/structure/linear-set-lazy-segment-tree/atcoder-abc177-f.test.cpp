#define PROBLEM "https://atcoder.jp/contests/abc177/tasks/abc177_f"

#include "../../../structure/linear-set-lazy-segment-tree.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    LazySegmentTree<ll, ll> tree(W, 0);

    rep(i, H) {
        ll l, r;
        cin >> l >> r;
        --l;

        ll x = (l > 0 ? tree.get(l - 1).min : inf32);

        tree.apply(l, r, {1, x + 1});

        ll ans = tree.prod_all().min;
        cout << (ans < inf32 ? ans + i + 1 : -1) << endl;
    }
}
