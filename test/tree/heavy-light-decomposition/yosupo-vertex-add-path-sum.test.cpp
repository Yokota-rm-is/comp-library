#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../../tree/heavy-light-decomposition.cpp"
#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    HeavyLightDecomposition hld(N);
    BinaryIndexedTree<ll> bit(2 * N - 1);    

    vll a(N);
    rep(i, N) {
        cin >> a[i];
    }

    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;
        hld.connect(u, v);
    }

    hld.build(0);

    rep(i, N) {
        bit.add(hld.get_vertex_index(i), a[i]);
    }

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll p, x;
            cin >> p >> x;
            bit.add(hld.get_vertex_index(p), x);
        }
        else {
            ll u, v;
            cin >> u >> v;

            ll ans = 0;
            auto prod = [&](ll l, ll r) {
                if (l > r) swap(l, r);
                ans += bit.sum(l, r);
            };
            hld.path_query(u, v, prod);

            cout << ans << endl;
        }
    }

    return 0;
}