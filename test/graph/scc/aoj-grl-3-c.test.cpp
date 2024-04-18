#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&"

#include "../../../graph/scc.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    SCC graph(V);
    rep(i, E) {
        ll s, t;
        cin >> s >> t;

        graph.connect(s, t);
    }

    graph.find_scc();

    ll Q;
    cin >> Q;
    while (Q--) {
        ll u, v;
        cin >> u >> v;

        cout << graph.is_same(u, v) << endl;
    }

    return 0;
}