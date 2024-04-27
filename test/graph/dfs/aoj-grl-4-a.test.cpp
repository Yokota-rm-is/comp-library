#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include "../../../graph/dfs.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    DFS tree(V, true);
    rep(i, E) {
        ll s, t;
        cin >> s >> t;

        tree.connect(s, t);
    }

    tree.dfs_all();

    cout << tree.has_cycle << endl; 

    return 0;
}