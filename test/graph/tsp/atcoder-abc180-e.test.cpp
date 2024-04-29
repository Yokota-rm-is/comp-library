#define PROBLEM "https://atcoder.jp/contests/abc180/tasks/abc180_e"

#include "../../../graph/tsp.cpp"

int main() {
    ll N;
    cin >> N;

    vll X(N), Y(N), Z(N);
    rep(i, N) cin >> X[i] >> Y[i] >> Z[i];

    TSP tsp(N, true);
    rep(i, N) rep(j, N) {
        if (i == j) continue;

        ll d = abs(X[j] - X[i]) + abs(Y[j] - Y[i]) + max(0, Z[j] - Z[i]);
        tsp.connect(i, j, d);
    }

    tsp(0);
    ll ans = tsp.get_cycle_dist();

    if (ans == inf64) cout << -1 << endl;
    else cout << ans << endl; 

    return 0;
}