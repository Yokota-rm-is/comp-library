#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"

#include "../../../structure/offline-dynamic-connectivity.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll A(N);
    rep(i, N) cin >> A[i];

    using T = ll;
    auto op = [](T a, T b) { return a + b; };
    auto inv = [](T a) { return -a; };
    OfflineDynamicConnectivity<false, T, op, inv> odc(N, A);
    
    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll u, v;
            cin >> u >> v;
            odc.link(u, v);
        }
        else if (t == 1) {
            ll u, v;
            cin >> u >> v;
            odc.cut(u, v);
        }
        else if (t == 2) {
            ll v, x;
            cin >> v >> x;
            odc.apply(v, x);
        }
        else {
            ll v;
            cin >> v;
            odc.query(v);
        }
    }

    odc.build();
    vll ans = odc.run([](UndoUnionFind<T, op, inv>& uf, int v) {
        return uf.prod(v);
    });

    cout << ans << endl;

    return 0;
} 
