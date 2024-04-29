#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_g"

#include "../../../graph/topological-sort.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    TopologicalSort graph(N);
    rep(i, N + M) {
        ll A, B;
        cin >> A >> B;

        graph.connect(A - 1, B - 1, 1);
    }

    graph();
    ll ans = max(graph.maximum_cost);

    cout << ans << endl;

    return 0;
}