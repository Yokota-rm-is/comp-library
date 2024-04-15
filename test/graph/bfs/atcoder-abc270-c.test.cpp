#define PROBLEM "https://atcoder.jp/contests/abc270/tasks/abc270_c"

#include "../../../graph/bfs.cpp"

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;

    BFS tree(N, false);
    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;

        tree.connect(u - 1, v - 1);
    }

    tree(X - 1);

    auto ans = tree.path_to(Y - 1);
    fore(a, ans) ++a;

    cout << ans << endl;

    return 0;
}