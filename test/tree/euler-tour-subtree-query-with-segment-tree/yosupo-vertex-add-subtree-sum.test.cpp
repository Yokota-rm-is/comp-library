#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../../tree/euler-tour-subtree-query-with-segment-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    using S = ll;
    auto op = [](S x, S y) { return x + y; };
    auto e = []() { return 0ll; };
    using F = ll;
    auto mapping = [](S x, F y) { return x + y; };
    auto id = []() { return 0ll; };

    EulerTourSubtree<S, op, e, F, mapping, id> tree(N);

    vll a(N);
    rep(i, N) {
        cin >> a[i];
    }

    vll p(N - 1);
    rep(i, N - 1) {
        cin >> p[i];
    
        tree.connect(i + 1, p[i]);
    }

    rep(i, N) {
        tree.set_vertex_weight(i, a[i]);
    }

    tree.build(0);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll u, x;
            cin >> u >> x;
            tree.apply_vertex(u, x);
        }
        else {
            ll u;
            cin >> u;

            ll ans = tree.prod(u);

            cout << ans << endl;
        }
    }

    return 0;
}