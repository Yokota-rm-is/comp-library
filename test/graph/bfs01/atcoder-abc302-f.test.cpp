#define PROBLEM "https://atcoder.jp/contests/abc302/tasks/abc302_f"

#include "../../../graph/bfs01.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll A(N);
    vvll S(N);

    rep(i, N) {
        cin >> A[i];
        S[i].resize(A[i]);
        rep(j, A[i]) cin >> S[i][j];
        --S[i];
    }

    vvll B(M);
    rep(i, N) fore(s, S[i]) B[s].push_back(i);

    BFS01 bfs(N + M + 2, true);

    rep(i, N) {
        fore(s, S[i]) {
            bfs.connect(i, N + s, 0);
            bfs.connect(N + s, i, 1);
        }
    }

    ll start = N + M;
    ll goal = N + M + 1;

    rep(i, B[0].size()) {
        ll u = start;
        ll v = B[0][i];

        bfs.connect(u, v, 0);
    }

    rep(i, B[M - 1].size()) {
        ll u = B[M - 1][i];
        ll v = goal;

        bfs.connect(u, v, 0);
    }

    bfs.solve(start);

    ll ans = bfs.cost[goal];
    if (ans == inf64) ans = -1;

    cout << ans << endl;

    return 0;
} 
