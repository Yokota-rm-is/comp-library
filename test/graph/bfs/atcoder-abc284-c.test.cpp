#define PROBLEM "https://atcoder.jp/contests/abc284/tasks/abc284_c"

#include "../../../graph/bfs.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    BFS graph(N, false);
    rep(i, M) {
        ll u, v;
        cin >> u >> v;

        graph.connect(u - 1, v - 1);
    }

    graph.solve_all();

    cout << graph.group << endl;

    return 0;
}