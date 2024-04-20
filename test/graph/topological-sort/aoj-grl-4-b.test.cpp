#define IGNORE
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&"

#include "../../../graph/topological-sort.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    TopologicalSort tree(V);
    rep(i, E) {
        ll s, t;
        cin >> s >> t;

        tree.connect(s, t, 1);
    }

    auto ans = tree();
    rep(i, V) {
        cout << ans[i] << endl;
    }


    return 0;
}