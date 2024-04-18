#define PROBLEM "https://atcoder.jp/contests/abc223/tasks/abc223_d"

#include "../../../graph/topological-sort.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    TopologicalSort tree(N);
    rep(i, M) {
        ll A, B;
        cin >> A >> B;

        tree.connect(A - 1, B - 1);
    }

    auto ans = tree();
    if (ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    else {
        rep(i, N) {
            cout << ans[i] + 1;
            if (i < N - 1) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}