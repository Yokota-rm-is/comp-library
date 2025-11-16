#define IGNORE
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"

#include "../../../structure/semi-dynamic-segment-tree-2d.cpp"

int main() {
    while (true) {
        ll r, c, q;
        cin >> r >> c >> q;

        if (r == 0) break;

        vector<vector<ll>> grid(r, vector<ll>(c, 0));
        rep(i, r) rep(j, c) cin >> grid[i][j]; 

        SemiDynamicSegmentTree2D<ll, ll, Set, Min> tree(r, c);
        rep(i, r) rep(j, c) tree.add_point(i, j);

        tree.build();
        rep(i, r) rep(j, c) tree.apply(i, j, grid[i][j]);

        while (q--) {
            ll r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;

            cout << tree.prod(r1, r2 + 1, c1, c2 + 1) << endl;
        }
    }

    return 0;
} 
