#define PROBLEM "https://atcoder.jp/contests/abc151/tasks/abc151_d"

#include "../../../grid/grid-bfs.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    GridBFS grid(H, W);
    grid.input();

    ll ans = 0;

    rep(y, H) rep(x, W) {
        if (grid.field.is_obj(y, x)) continue;

        grid.init();
        grid.bfs(Coordinate{y, x});

        rep(i, H) rep(j, W) {
            if (!grid.seen(i, j)) continue;
            chmax(ans, grid.cost(i, j));
        }
    }

    cout << ans << endl;

    return 0;
}