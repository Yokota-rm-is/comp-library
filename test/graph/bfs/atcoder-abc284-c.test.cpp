#define PROBLEM "https://atcoder.jp/contests/abc284/tasks/abc284_c"

#include "../../../graph/bfs.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    BFS tree(N, false);
    rep(i, M) {
        ll u, v;
        cin >> u >> v;

        tree.connect(u - 1, v - 1);
    }

    tree.bfs_all();

    cout << tree.group << endl;

    return 0;
}