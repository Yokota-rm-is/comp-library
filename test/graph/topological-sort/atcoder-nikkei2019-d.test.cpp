#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d"

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
    auto ans = grpah.prev;

    rep(i, N) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}