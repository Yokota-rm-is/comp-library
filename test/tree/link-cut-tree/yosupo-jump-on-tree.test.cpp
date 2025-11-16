#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

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

    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        tree.link(nodes[a], nodes[b]);
    }

    while (Q--) {
        ll s, t, i;
        cin >> s >> t >> i;

        Node* kth_node = tree.get_kth(nodes[s], nodes[t], i);
        cout << (kth_node ? kth_node->idx : -1) << endl;
    }

    return 0;
}