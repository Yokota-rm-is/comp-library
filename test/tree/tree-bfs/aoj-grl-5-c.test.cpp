#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&"

#include "../../../tree/tree-bfs.cpp"

int main() {
    ll n;
    cin >> n;

    TreeBFS tree(n);
    rep(i, n) {
        ll k;
        cin >> k;
        rep(j, k) {
            ll c;
            cin >> c;
            tree.connect(i, c, 1);
        }
    }

    tree.lca_init(0);

    ll q;
    cin >> q;
    while (q--) {
        ll u, v;
        cin >> u >> v;
        cout << tree.lca(u, v) << endl;
    }

    return 0;
}
