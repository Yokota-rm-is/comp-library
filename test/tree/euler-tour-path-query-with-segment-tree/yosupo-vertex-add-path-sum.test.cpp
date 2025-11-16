#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../../tree/euler-tour-path-query-with-segment-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    using S = ll;
    auto op = [](S a, S b) { return a + b; };
    auto inv = [](S a) { return -a; };
    auto e = []() { return 0LL; };
    using F = ll;
    auto mapping = [](S a, F f) { return a + f; };
    EulerTourPath<S, op, inv, e, F, mapping> tree(N);

    vll a(N);
    rep(i, N) {
        cin >> a[i];
    }

    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;
        tree.connect(u, v);
    }

    rep(i, N) {
        tree.set_vertex_weight(i, a[i]);
    }

    tree.build(0);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll p, x;
            cin >> p >> x;
            tree.apply_vertex(p, x);
        }
        else {
            ll u, v;
            cin >> u >> v;

            ll ans = tree.prod(u, v);

            cout << ans << endl;
        }
    }

    return 0;
}