#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc406/tasks/abc406_f"
// https://atcoder.jp/contests/abc406/submissions/65934410

#include "../../../tree/heavy-light-decomposition.cpp"
#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    ll N;
    cin >> N;

    vll U(N - 1), V(N - 1);

    rep(i, N - 1) {
        cin >> U[i] >> V[i];
    }
    --U, --V;

    HeavyLightDecomposition hld(N);
    rep(i, N - 1) {
        hld.connect(U[i], V[i]);
    }
    hld.build(0);

    BinaryIndexedTree<long long> bit(2 * N - 1, 0);

    rep(i, N) {
        bit.add(hld.get_vertex_index(i), 1);
    }

    ll W = N;
    
    ll Q;
    cin >> Q;

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll x, w;
            cin >> x >> w;
            --x;

            bit.add(hld.get_vertex_index(x), w);
            W += w;
        }
        else {
            ll y;
            cin >> y;
            --y;

            ll w1 = 0;
            auto prod = [&](ll l, ll r) {
                w1 += bit.sum(l, r);
            };
            hld.subtree_query(N + y, prod);

            ll w2 = W - w1;
            ll ans = abs(w1 - w2);
            
            cout << ans << endl;
        }
    }

    return 0;
} 