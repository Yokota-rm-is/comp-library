#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&"

#include "../../../graph/dijkstra.cpp"

int main() {
    ll V, E, r;
    cin >> V >> E >> r;

    Dijkstra<ll> graph(V, true);
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;

        graph.connect(s, t, d);
    }

    graph(r);
    rep(i, V) {
        if (graph.cost[i] == inf64) cout << "INF" << endl;
        else cout << graph.cost[i] << endl;
    }

    return 0;
}