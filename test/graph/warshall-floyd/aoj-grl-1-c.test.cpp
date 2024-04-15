#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&"

#include "../../../graph/warshall-floyd.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    WarshallFloyd<ll> tree(V, true);
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;

        tree.connect(s, t, d);
    }

    tree();
    if (tree.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    
    rep(i, V) {
        rep(j, V) {
            if (tree.cost[i][j] == inf64) cout << "INF";
            else cout << tree.cost[i][j];
            
            if (j < V - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}