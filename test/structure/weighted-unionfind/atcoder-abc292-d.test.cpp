#define PROBLEM "https://atcoder.jp/contests/abc292/tasks/abc292_d"

#include "../../../structure/weighted-unionfind.cpp"

int main() {
    long long N, M;
    cin >> N >> M;

    WeightedUnionFind<ll, true> tree(N);
    rep(i, M) {
        long long u, v;
        cin >> u >> v;
        --u; --v;

        tree.unite(u, v, 0);
    }

    bool ans = true;
    rep(i, N) {
        if (!tree.is_root(i)) continue;

        if (tree.size(i) != tree.edge_size(i)) {
            ans = false;
            break;
        }
    }

    cout << YesNo(ans) << endl;

    return 0;
}