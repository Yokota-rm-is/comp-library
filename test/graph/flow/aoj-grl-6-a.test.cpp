#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&"

#include "../../../graph/flow.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    MinCostFlow<ll, ll> graph(V);
    rep(i, E) {
        ll u, v, c;
        cin >> u >> v >> c;

        graph.connect(u, v, c);
    }

    long long ans = graph.max_flow(0, V - 1);
    cout << ans << endl;

    return 0;
}