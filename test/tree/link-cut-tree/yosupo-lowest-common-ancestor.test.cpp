#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../../tree/link-cut-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    using T = long long;
    auto op = [](T a, T b) { return a + b; };
    auto e = []() { return T(0); };
    using F = long long;
    auto mapping = [](T a, F f) { return a + f; };
    auto composition = [](F f1, F f2) { return f1 + f2; };
    auto id = []() { return F(0); };
    
    LinkCutTree<T, op, e, F, mapping, composition, id> tree;
    using Node = LinkCutTree<T, op, e, F, mapping, composition, id>::Node;
    vector<Node*> nodes(N);
    rep(i, N) {
        nodes[i] = tree.make_node(i, 0);
    }

    rep(i, 1, N) {
        ll p;
        cin >> p;
        tree.link(nodes[i], nodes[p]);
    }

    tree.evert(nodes[0]);

    while (Q--) {
        ll u, v;
        cin >> u >> v;

        cout << tree.lca(nodes[u], nodes[v])->idx << endl;
    }

    return 0;
}