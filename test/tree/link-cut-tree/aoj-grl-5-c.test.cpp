#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../../tree/link-cut-tree.cpp"

int main() {
    ll n;
    cin >> n;

    using T = long long;
    auto op = [](T a, T b) { return a + b; };
    auto e = []() { return T(0); };
    using F = long long;
    auto mapping = [](T a, F f) { return a + f; };
    auto composition = [](F f1, F f2) { return f1 + f2; };
    auto id = []() { return F(0); };
    
    LinkCutTree<T, op, e, F, mapping, composition, id> tree;
    using Node = LinkCutTree<T, op, e, F, mapping, composition, id>::Node;
    vector<Node*> nodes(n);
    rep(i, n) {
        nodes[i] = tree.make_node(i, 0);
    }

    rep(i, n) {
        ll k;
        cin >> k;
        
        rep(j, k) {
            ll c;
            cin >> c;

            tree.link(nodes[i], nodes[c]);
        }
    }

    tree.evert(nodes[0]);

    ll q;
    cin >> q;

    while (q--) {
        ll u, v;
        cin >> u >> v;
        
        Node* a = tree.lca(nodes[u], nodes[v]);
        cout << (a ? a->idx : -1) << endl;
    }

    return 0;
}