#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B"

#include "../../../graph/dfs.cpp"

int main() {
    ll V;
    cin >> V;

    DFS graph(V, true);
    rep(i, V) {
        ll u, k;
        cin >> u >> k;

        rep(j, k) {
            ll v;
            cin >> v;
            graph.connect(u - 1, v - 1);
        }
    }

    graph.solve_all();

    vector<pll> ans(V);
    rep(i, V) {
       ans[graph.pre_order[i].index].first = graph.pre_order[i].time;
       ans[graph.post_order[i].index].second = graph.post_order[i].time;
    }

    rep(i, V) {
        cout << i + 1 << " " << ans[i].first + 1 << " " << ans[i].second + 1 << endl; 
    }

    return 0;
}