#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d"

#include "../../../graph/topological-sort.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    TopologicalSort tree(N);
    rep(i, N + M) {
        ll A, B;
        cin >> A >> B;

        tree.connect(A - 1, B - 1, 1);
    }

    tree();
    auto ans = tree.prev;

    rep(i, N) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}