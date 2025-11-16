#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include "../../../graph/lowlink.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    LowLink graph(V);
    rep(i, E) {
        ll s, t;
        cin >> s >> t;
        graph.connect(s, t);
    }

    graph.build();
    rep(i, V) {
        if (graph.is_articulation(i)) cout << i << endl;
    }

    return 0;
}