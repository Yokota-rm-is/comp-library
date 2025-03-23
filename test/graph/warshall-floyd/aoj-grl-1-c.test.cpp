#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&"
#include "../../../graph/warshall-floyd.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    WarshallFloyd<ll> graph(V, true);
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;

        graph.connect(s, t, d);
    }

    graph();
    if (graph.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    
    rep(i, V) {
        rep(j, V) {
            if (graph.cost[i][j] == inf64) cout << "INF";
            else cout << graph.cost[i][j];
            
            if (j < V - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}