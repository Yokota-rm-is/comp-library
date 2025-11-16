#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include "../../../tree/link-cut-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) {
        cin >> a[i];
    }

    using S = ll;
    auto op = [](S a, S b) { return a + b; };
    auto e = []() { return S(0); };
    using F = ll;
    auto mapping = [](S a, F f) { return a + f; };
    auto composition = [](F f1, F f2) { return f1 + f2; };
    auto id = []() { return F(0); };
    LinkCutTree<S, op, e, F, mapping, composition, id> tree;

    using Node = LinkCutTree<S, op, e, F, mapping, composition, id>::Node;
    vector<Node*> nodes(N);
    rep(i, N) {
        nodes[i] = tree.make_node(i, a[i]);
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
            ll u, v, w, x;
            cin >> u >> v >> w >> x;

            tree.cut(nodes[u], nodes[v]);
            tree.link(nodes[w], nodes[x]);
        }
        else if (t == 1) {
            ll p, x;
            cin >> p >> x;
            tree.apply(nodes[p], x);
        }
        else {
            ll u, v;
            cin >> u >> v;

            ll ans = tree.prod(nodes[u], nodes[v]);

            cout << ans << endl;
        }
    }

    return 0;
}