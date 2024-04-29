#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include "../../../graph/dfs.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    DFS graph(V, true);
    rep(i, E) {
        ll s, t;
        cin >> s >> t;

        graph.connect(s, t);
    }

    graph.solve_all();

    cout << graph.has_cycle << endl; 

    return 0;
}