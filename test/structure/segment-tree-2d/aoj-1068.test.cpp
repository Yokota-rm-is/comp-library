#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"

#include "../../../structure/segment-tree-2d.cpp"

int main() {
    while (true) {
        ll r, c, q;
        cin >> r >> c >> q;

        if (r == 0) break;

        vector<vector<ll>> grid(r, vector<ll>(c, 0));
        rep(i, r) rep(j, c) cin >> grid[i][j]; 

        SegmentTree2D<ll, ll, Set, Min> tree(grid);

        while (q--) {
            ll r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            ++r2, ++c2;

            cout << tree.prod(r1, r2, c1, c2) << endl;
        }
    }

    return 0;
} 
