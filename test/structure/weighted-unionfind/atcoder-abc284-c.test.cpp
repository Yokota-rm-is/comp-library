#define PROBLEM "https://atcoder.jp/contests/abc284/tasks/abc284_c"

#include "../../../structure/weighted-unionfind.cpp"

int main() {
    long long N, M;
    cin >> N >> M;

    WeightedUnionFind tree(N);
    rep(i, M) {
        long long u, v;
        cin >> u >> v;
        --u, --v;

        tree.unite(u, v, 0);
    }

    cout << tree.group_count() << endl;

    return 0;
}