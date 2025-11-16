#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/pastbook2022/tasks/pastbook2022_e"
// https://atcoder.jp/contests/pastbook2022/submissions/67986990

#include "../../../graph/flow.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    MinCostFlow<ll, ll> mcf(V);
    rep(i, E) {
        ll u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        mcf.connect(u, v, c);
    }

    cout << mcf.max_flow(0, V - 1) << endl;

    return 0;
}