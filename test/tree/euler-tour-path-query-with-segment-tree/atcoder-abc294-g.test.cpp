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

    using S = ll;
    auto op = [](S a, S b) { return a + b; };
    auto inv = [](S a) { return -a; };
    auto e = []() { return 0LL; };
    using F = ll;
    auto mapping = [](S a, F f) { return f; };
    EulerTourPath<S, op, inv, e, F, mapping> tree(N);
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
            tree.apply_edge(i, w);
        }
        else {
            ll u, v;
            cin >> u >> v;
            --u, --v;

            ll ans = tree.prod(u, v);

            cout << ans << endl;
        }
    }

    return 0;
} 