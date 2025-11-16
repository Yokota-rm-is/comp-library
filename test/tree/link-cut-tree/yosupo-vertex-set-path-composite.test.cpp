#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../../../tree/link-cut-tree.cpp"
#include "../../../math/modint.cpp"
using mint = mint998;

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N), b(N);
    rep(i, N) {
        cin >> a[i] >> b[i];
    }

    using S = pair<mint, mint>;
    auto op = [](S a, S b) { return S(b.first * a.first, b.first * a.second + b.second); };
    auto e = []() { return S(1, 0); };
    using F = pair<mint, mint>;
    auto mapping = [](S a, F f) { return f; };
    auto composition = [](F f1, F f2) { 
        if (f2.first == 0) return f1;
        return f2; 
    };
    auto id = []() { return F(0, 0); };
    LinkCutTree<S, op, e, F, mapping, composition, id> tree;

    using Node = LinkCutTree<S, op, e, F, mapping, composition, id>::Node;
    vector<Node*> nodes(N);
    rep(i, N) {
        nodes[i] = tree.make_node(i, S(a[i], b[i]));
    }

    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;
        tree.link(nodes[u], nodes[v]);
    }

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll p, c, d;
            cin >> p >> c >> d;
            tree.apply(nodes[p], F(c, d));
        }
        else {
            ll u, v, x;
            cin >> u >> v >> x;

            auto [c, d] = tree.prod(nodes[u], nodes[v]);
            mint ans = c * x + d;

            cout << ans << endl;
        }
    }

    return 0;
}