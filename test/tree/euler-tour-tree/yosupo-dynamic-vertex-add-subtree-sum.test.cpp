#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum"

#include "../../../tree/euler-tour-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) {
        cin >> a[i];
    }

    EulerTourTree<ll, ll> tree(a);

    vll U(N - 1), V(N - 1);
    rep(i, N - 1) {
        cin >> U[i] >> V[i];
    
        tree.link(U[i], V[i]);
    }

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll u, v, w, x;
            cin >> u >> v >> w >> x;
            tree.cut(u, v);
            tree.link(w, x);
        }
        else if (t == 1) {
            ll p, x;
            cin >> p >> x;
            tree.point_update(p, x);
        }
        else {
            ll v, p;
            cin >> v >> p;

            tree.reroot(p);
            ll ans = tree.query(v, p);

            cout << ans << endl;
        }
    }

    return 0;
}