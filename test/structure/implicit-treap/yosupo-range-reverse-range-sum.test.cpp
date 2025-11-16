#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../../../structure/implicit-treap.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ull> a(N);
    rep(i, N) cin >> a[i];

    using S = ll;
    using F = ll;
    auto op = [](S a, S b) { return a + b; };
    auto e = []() { return 0ll; };
    auto mapping = [](S x, F f) { return x; };
    auto composition = [](F &f, F s) { return; };
    auto id = []() { return 0ll; };
    ImplicitTreap<S, F, op, e, mapping, composition, id> tree;

    rep(i, N) tree.insert(i, a[i]);

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