#define PROBLEM "https://atcoder.jp/contests/abc176/tasks/abc176_d"

#include "../../../grid/grid-bfs.cpp"

struct ABC176D : GridBFS {
    using GridBFS::GridBFS;

    ABC176D(ll H, ll W) : GridBFS(H, W) {}

    void bfs01(Coordinate now) {
        assert(!seen(now) and !field.is_out(now) and !field.is_obj(now));

        deque<Coordinate> que;

        // 初期条件 (頂点 start を初期ノードとする)
        cost(now) = 0;

        que.push_front(now); // noq を橙色頂点にする

        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            now = que.front(); // キューから先頭頂点を取り出す
            que.pop_front();

            if (seen(now)) continue;
            seen(now) = true;

            // v から辿れる頂点をすべて調べる
            rep(i, dirs.size()) {
                Coordinate next = now + dirs[i];
                if (field.is_out(next)) continue;
                if (field.is_obj(next)) continue;
                if (seen(next)) continue;

                ll c = 0; 

                if (chmin(cost(next), cost(now) + c)) {
                    prev(next) = now;
                    que.push_front(next);
                }
            }

            rep(dx, -2, 3) {
                rep(dy, -2, 3) {
                    if (dx == 0 and dy == 0) continue;

                    Coordinate next = now + Coordinate(dx, dy);
                    if (field.is_out(next)) continue;
                    if (field.is_obj(next)) continue;
                    if (seen(next)) continue;

                    ll c = 1;

                    if (chmin(cost(next), cost(now) + c)) {
                        prev(next) = now;
                        que.push_back(next);
                    }
                }
            }
        }
    }
};

int main() {
    ll H, W;
    cin >> H >> W;

    ll ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    --ch, --cw, --dh, --dw;

    ABC176D grid(H, W);
    grid.input();

    grid.bfs01({ch, cw});
    ll ans = grid.cost({dh, dw});
    if (ans == inf64) ans = -1;

    cout << ans << endl;

    return 0;
}