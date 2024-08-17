#define PROBLEM "https://atcoder.jp/contests/abc176/tasks/abc176_d"

#include "../../../graph/bfs01.cpp"

struct ABC176D : BFS01 {
    using BFS01::BFS01;
    ll H, W;

    ABC176D(ll h, ll w) : BFS01(h * w, false), H(h), W(w) {}

    void connect(ll h1, ll w1, ll h2, ll w2, ll weight) {
        BFS01::connect(h1 * W + w1, h2 * W + w2, weight);
    }

    void solve(ll h, ll w) {
        BFS01::solve(h * W + w);
    }
};

int main() {
    ll H, W;
    cin >> H >> W;

    ll ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    --ch, --cw, --dh, --dw;

    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    ABC176D bfs(H, W);

    rep(i, H) rep(j, W) {
        if (grid[i][j] == '#') continue;

        vector<pll> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        fore(d, dirs) {
            auto [dx, dy] = d;

            ll ni = i + dx;
            ll nj = j + dy;

            if (ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if (grid[ni][nj] == '#') continue;

            bfs.connect(i, j, ni, nj, 0);
        }

        rep(dx, -2, 3) {
            rep(dy, -2, 3) {
                if (dx == 0 and dy == 0) continue;

                ll ni = i + dx;
                ll nj = j + dy;

                if (ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
                if (grid[ni][nj] == '#') continue;

                bfs.connect(i, j, ni, nj, 1);
            }
        }
    }

    bfs.solve(ch, cw);
    ll ans = bfs.cost[dh * W + dw];
    if (ans == inf64) ans = -1;

    cout << ans << endl;

    return 0;
}