#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_g"

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
    ll ans = max(tree.maximum_cost);

    cout << ans << endl;

    return 0;
}