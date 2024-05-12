#define PROBLEM "https://atcoder.jp/contests/abc334/tasks/abc334_e"

#include "../../../grid/grid-dfs.cpp"
#include "../../../math/modint.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    GridDFS grid(H, W);
    grid.input();

    grid.field.obj = grid.field.dot;
    grid.obj = grid.dot;

    grid.dfs_all();

    mapll mp;
    rep(y, H) rep(x, W) {
        if (grid.field(y, x) == grid.hash) {
            mp[grid.cc(y, x)]++;
        }
    }

    mint998 ans = 0;
    mint998 count = 0;
    
    rep(y, H) rep(x, W) {
        if (grid.field(y, x) != grid.obj) continue;
        
        count += 1;
        
        setll st;
        rep(i, 4) {
            Coordinate next = Coordinate(y, x) + grid.dirs[i];
            if (grid.field.is_out(next)) continue;
            if (grid.field.is_obj(next)) continue;
            st.insert(grid.cc(next));
        }

        ans += mp.size() - st.size() + 1; 
    }

    cout << ans / count << endl;

    return 0;
}