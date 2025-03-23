#define PROBLEM "https://atcoder.jp/contests/abc327/tasks/abc327_d"

#include "../../../graph/bfs-bipartite.cpp"

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

    BFS bfs(N, false);
    rep(i, M) {
        bfs.connect(A[i], B[i]);
    }

    bool ans = bfs();

    cout << YesNo(ans) << endl;

    return 0;
}