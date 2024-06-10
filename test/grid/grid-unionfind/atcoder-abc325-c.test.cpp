#define PROBLEM "https://atcoder.jp/contests/abc325/tasks/abc325_c"

#include "../../../grid/grid-unionfind.cpp"

int main() {
    ll H, W;
    input(H, W);

    GridUnionFind uf(H, W);
    uf.field.obj = uf.field.dot;
    uf.dirs = {
        Coordinate(0, 1),
        Coordinate(1, 0),
        Coordinate(0, -1),
        Coordinate(-1, 0),
        Coordinate(1, 1),
        Coordinate(1, -1),
        Coordinate(-1, 1),
        Coordinate(-1, -1)
    };
    uf.input();

    ll count = 0;
    rep(y, H) rep(x, W) if (uf.field(y, x) == '.') ++count;

    ll ans = uf.cc_size - count;

    cout << ans << endl;

    return 0;
} 