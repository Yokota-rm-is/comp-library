#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&"

#include "../../../graph/bellman-ford.cpp"

int main() {
    ll V, E, r;
    cin >> V >> E >> r;

    BellmanFord<ll> tree(V, true);
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;

        tree.connect(s, t, d);
    }

    tree(r);
    if (tree.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    
    rep(i, V) {
        if (tree.cost[i] == inf64) cout << "INF" << endl;
        else cout << tree.cost[i] << endl;
    }

    return 0;
}