#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc294/tasks/abc294_g"
// https://atcoder.jp/contests/abc294/submissions/65933717

#include "../../../tree/heavy-light-decomposition.cpp"
#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    ll N;
    cin >> N;

    vll U(N - 1), V(N - 1), W(N - 1);
    rep(i, N - 1) {
        cin >> U[i] >> V[i] >> W[i];
    }
    --U, --V;

    HeavyLightDecomposition hld(N);
    rep(i, N - 1) {
        hld.connect(U[i], V[i]);
    }

    hld.build(0);

    BinaryIndexedTree<ll> bit(N * 2 - 1);
    rep(i, N - 1) {
        bit.add(hld.get_edge_index(i), W[i]);
    }

    ll Q;
    cin >> Q;

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll i, w;
            cin >> i >> w;

            --i;
            bit.set(hld.get_edge_index(i), w);
        }
        else {
            ll u, v;
            cin >> u >> v;
            --u, --v;

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