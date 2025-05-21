#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc294/tasks/abc294_g"
// https://atcoder.jp/contests/abc294/submissions/65601770

#include "../../../tree/euler-tour-path-query-with-segment-tree.cpp"

int main() {
    ll N;
    cin >> N;

    vll U(N - 1), V(N - 1), W(N - 1);
    rep(i, N - 1) {
        cin >> U[i] >> V[i] >> W[i];
    }
    --U, --V;

    EulerTourPath<ll> tree(N);
    rep(i, N - 1) {
        tree.connect(U[i], V[i], W[i]);
    }

    tree.build(0);

    ll Q;
    cin >> Q;

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll i, w;
            cin >> i >> w;

            --i;
            tree.set_edge(i, w);
        }
        else {
            ll u, v;
            cin >> u >> v;
            --u, --v;

            ll ans = tree.prod_sum(u, v);

            cout << ans << endl;
        }
    }

    return 0;
} 