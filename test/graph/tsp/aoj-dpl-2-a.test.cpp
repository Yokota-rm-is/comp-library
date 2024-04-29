#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include "../../../graph/tsp.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    TSP tsp(V, true);
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;

        tsp.connect(s, t, d);
    }

    tsp(0);
    ll ans = tsp.get_cycle_dist();

    if (ans == inf64) cout << -1 << endl;
    else cout << ans << endl; 

    return 0;
}