#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include "../../../graph/bfs.cpp"

int main() {
    ll V;
    cin >> V;

    BFS tree(V, true);
    rep(i, V) {
        ll u, k;
        cin >> u >> k;

        rep(j, k) {
            ll v;
            cin >> v;
            tree.connect(u - 1, v - 1);
        }
    }

    tree(0);

    rep(i, V) {
       if (tree.depth[i] == inf64) cout << i + 1 << " " << -1 << endl;
       else cout << i + 1 << " " << tree.depth[i] << endl;
    }

    return 0;
}