#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&"

#include "../../../graph/dijkstra.cpp"

int main() {
    ll V, E, r;
    cin >> V >> E >> r;

    Dijkstra<ll> tree(V, true);
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;

        tree.connect(s, t, d);
    }

    tree(r);
    rep(i, V) {
        if (tree.cost[i] == inf64) cout << "INF" << endl;
        else cout << tree.cost[i] << endl;
    }

    return 0;
}