#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B"

#include "../../../graph/dfs.cpp"

int main() {
    ll V;
    cin >> V;

    DFS tree(V, true);
    rep(i, V) {
        ll u, k;
        cin >> u >> k;

        rep(j, k) {
            ll v;
            cin >> v;
            tree.connect(u - 1, v - 1);
        }
    }

    tree.dfs_all();

    vector<pll> ans(V);
    rep(i, V) {
       ans[tree.pre_order[i].index].first = tree.pre_order[i].time;
       ans[tree.post_order[i].index].second = tree.post_order[i].time;
    }

    rep(i, V) {
        cout << i + 1 << " " << ans[i].first + 1 << " " << ans[i].second + 1 << endl; 
    }

    return 0;
}