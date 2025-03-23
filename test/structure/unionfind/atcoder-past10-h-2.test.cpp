#define PROBLEM "https://atcoder.jp/contests/past202203-open/tasks/past202203_h"

#include "../../../structure/unionfind.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    UnionFind<true, false, true> tree(N);
    
    while (Q--) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll u, v;
            cin >> u >> v;
            --u, --v;

            tree.unite(u, v);
        }
        else {
            ll u;
            cin >> u;
            --u;

            auto members = tree.members(u);
            sort(members);
            vll ans;
            for (auto m : members) ans.push_back(m + 1);

            cout << ans << endl;
        }
    }

    return 0;
}