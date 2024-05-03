#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&"

#include "../../../graph/flow.cpp"

int main() {
    ll V, E, F;
    cin >> V >> E >> F;

    MinCostFlow<ll, ll> graph(V);
    rep(i, E) {
        ll u, v, c, d;
        cin >> u >> v >> c >> d;

        graph.connect(u, v, d, c);
    }

    auto [flow, cost] = graph.min_cost_flow(0, V - 1, F);
    if (flow < F) cout << -1 << endl;
    else cout << cost << endl;

    return 0;
}