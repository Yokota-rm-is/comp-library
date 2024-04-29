#define PROBLEM "https://atcoder.jp/contests/abc270/tasks/abc270_c"

#include "../../../graph/dijkstra.cpp"

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;

    Dijkstra graph(N, false);
    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;

        graph.connect(u - 1, v - 1, 1);
    }

    graph(X - 1);

    auto ans = graph.get_path(Y - 1);
    fore(a, ans) ++a;

    cout << ans << endl;

    return 0;
}