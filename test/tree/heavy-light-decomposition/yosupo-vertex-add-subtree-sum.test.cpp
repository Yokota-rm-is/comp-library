#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../../tree/heavy-light-decomposition.cpp"
#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    HeavyLightDecomposition hld(N);
    BinaryIndexedTree<ll> bit(2 * N - 1, 0);

    vll a(N);
    rep(i, N) {
        cin >> a[i];
    }

    vll p(N - 1);
    rep(i, N - 1) {
        cin >> p[i];
    
        hld.connect(i + 1, p[i]);
    }

    hld.build(0);

    rep(i, N) {
        bit.add(hld.get_vertex_index(i), a[i]);
    }

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll u, x;
            cin >> u >> x;
            bit.add(hld.get_vertex_index(u), x);
        }
        else {
            ll u;
            cin >> u;

            ll ans = 0;
            auto prod = [&](ll l, ll r) {
                if (l > r) swap(l, r);
                ans += bit.sum(l, r);
            };
            hld.subtree_query(u, prod);

            cout << ans << endl;
        }
    }

    return 0;
}