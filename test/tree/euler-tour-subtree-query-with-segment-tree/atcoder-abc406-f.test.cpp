#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc406/tasks/abc406_f"
// https://atcoder.jp/contests/abc406/submissions/65928612

#include "../../../tree/euler-tour-subtree-query-with-segment-tree.cpp"

int main() {
    ll N;
    cin >> N;

    vll U(N), V(N);
    rep(i, N - 1) cin >> U[i] >> V[i];
    --U, --V;

    using S = ll;
    auto op = [](S a, S b) { return a + b; };
    auto e = []() { return 0; };
    using F = ll;
    auto mapping = [](S a, F b) { return a + b; };

    EulerTourSubtree<S, op, e, F, mapping> tree(N);
    rep(i, N - 1) {
        tree.connect(U[i], V[i]);
    }
    rep(i, N) {
        tree.set_vertex_weight(i, 1);
    }

    tree.build(0);

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

            tree.apply_vertex(x, w);
            W += w;
        }
        else {
            ll y;
            cin >> y;
            --y;

            ll u = U[y], v = V[y];
            
            ll x;
            if (tree.pre_order[u] < tree.pre_order[v]) x = v;
            else x = u;

            ll w1 = tree.prod(x);
            ll w2 = W - w1;
            ll ans = w1 - w2;
            
            if (ans < 0) ans *= -1;
            cout << ans << endl;
        }
    }
    return 0;
} 