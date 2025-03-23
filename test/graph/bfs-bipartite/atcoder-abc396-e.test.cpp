#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc396/tasks/abc396_e"
// https://atcoder.jp/contests/abc396/submissions/63568289

#include "../../../graph/bfs-bipartite.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll X(M), Y(M), Z(M);
    rep(i, M) cin >> X[i] >> Y[i] >> Z[i];
    --X, --Y;

    vll A(N, 0);

    rep(i, 32) {
        BFS bfs(N, false);
        rep(j, M) {
            bfs.connect(X[j], Y[j], Z[j] & (1 << i));
        }

        bool ret = bfs();
        if (!ret) {
            cout << -1 << endl;
            return 0;
        }

        auto cc = bfs.cc;
        rep(j, cc.size()) {
            if (cc[j][0].size() < cc[j][1].size()) swap(cc[j][0], cc[j][1]);
            fore(v, cc[j][1]) {
                A[v] |= 1ll << i;
            }
        }
    }

    cout << A << endl;

    return 0;
} 