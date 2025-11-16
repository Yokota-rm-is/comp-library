#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../../tree/euler-tour-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) {
        cin >> a[i];
    }

    EulerTourTree<ll, ll> tree(a);

    vll p(N - 1);
    rep(i, N - 1) {
        cin >> p[i];
    
        tree.link(p[i], i + 1);
    }

    tree.reroot(0);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll u, x;
            cin >> u >> x;
            tree.point_update(u, x);
        }
        else {
            ll u;
            cin >> u;

            ll ans = tree.query(u, u == 0 ? -1 : p[u - 1]);

            cout << ans << endl;
        }
    }

    return 0;
}