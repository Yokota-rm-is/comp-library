#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../../tree/tree-dfs.cpp"

int main() {
    ll n;
    cin >> n;
    
    TreeDFS<> tree(n);

    rep(i, n) {
        ll k;
        cin >> k;
        
        rep(j, k) {
            ll c;
            cin >> c;

            tree.connect(i, c);
        }
    }

    tree.build(0);

    ll q;
    cin >> q;

    while (q--) {
        ll u, v;
        cin >> u >> v;
        
        ll a = tree.lca(u, v);
        cout << a << endl;
    }

    return 0;
}