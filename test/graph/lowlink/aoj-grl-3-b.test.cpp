#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "../../../graph/lowlink.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    vector<pll> edge(E);

    LowLink graph(V, false);
    rep(i, E) {
        ll s, t;
        cin >> s >> t;
        if (s > t) swap(s, t);
        graph.connect(s, t);

        edge[i] = {s, t};
    }

    sort(edge);

    graph();
    rep(i, E) {
        auto [s, t] = edge[i];
        if (graph.is_bridge(s, t)) cout << s << " " << t << endl;
    }

    return 0;
}