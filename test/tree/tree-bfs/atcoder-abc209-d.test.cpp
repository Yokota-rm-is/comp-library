#define PROBLEM "https://atcoder.jp/contests/abc209/tasks/abc209_d"

#include "../../../tree/tree-bfs.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    TreeBFS tree(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;

        tree.connect(a - 1, b - 1, 1);
    }

    tree.lca_init(0);

    while (Q--) {
        ll c, d;
        cin >> c >> d;

        if (tree.get_dist(c - 1, d - 1) % 2 == 0) {
            cout << "Town" << endl;
        }
        else cout << "Road" << endl;
    }

    return 0;
}
