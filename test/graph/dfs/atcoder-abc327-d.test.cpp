#define PROBLEM "https://atcoder.jp/contests/abc327/tasks/abc327_d"

#include "../../../graph/dfs.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> A(M), B(M);
    rep(i, M) {
        ll a;
        cin >> a;
        --a;
        A[i] = a;
    }
    rep(i, M) {
        ll b;
        cin >> b;
        --b;
        B[i] = b;
    }

    DFS graph(N, false);
    rep(i, M) {
        graph.connect(A[i], B[i]);
    }

    cout << YesNo(graph.is_bipartite()) << endl;

    return 0;
}