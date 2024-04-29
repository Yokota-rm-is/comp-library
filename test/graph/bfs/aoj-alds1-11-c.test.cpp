#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include "../../../graph/bfs.cpp"

int main() {
    ll V;
    cin >> V;

    BFS graph(V, true);
    rep(i, V) {
        ll u, k;
        cin >> u >> k;

        rep(j, k) {
            ll v;
            cin >> v;
            graph.connect(u - 1, v - 1);
        }
    }

    graph(0);

    rep(i, V) {
       if (graph.depth[i] == inf64) cout << i + 1 << " " << -1 << endl;
       else cout << i + 1 << " " << graph.depth[i] << endl;
    }

    return 0;
}