#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_aq"
// https://atcoder.jp/contests/typical90/submissions/52924275

#include "../../../grid/grid-dijkstra.cpp"

struct Cell {
    Coordinate point;
    ll idx;
    ll cost;

    Cell(Coordinate p, ll i, ll c) : point(p), idx(i), cost(c) {}

    friend bool operator< (const Cell &l, const Cell &r) {
        return l.cost < r.cost;
    }

    friend bool operator> (const Cell &l, const Cell &r) {
        return l.cost > r.cost;
    }
};

struct T90_43 : GridDijkstra {
    T90_43 (long long h, long long w) : GridDijkstra(h, w) {}

    void dijkstra(Coordinate start) {
        assert(!done(start) and !field.is_out(start) and !field.is_obj(start));

        Grid<vector<bool>> done2(H, W, vector<bool>(2, false));
        Grid<vector<long long>> cost2(H, W, vector<long long>(2, inf64));

        priority_queue<Cell, vector<Cell>, greater<Cell>> que;

        // 初期条件 (頂点 start を初期ノードとする)
        rep(i, 2) que.push(Cell(start, i, 0)); // noq を橙色頂点にする

        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            Cell cell = que.top(); // キューから先頭頂点を取り出す
            que.pop();

            Coordinate now = cell.point;
            ll di = cell.idx;
            ll cost_now = cell.cost;            

            if (done2(now)[di]) continue;
            done2(now)[di] = true;

            chmin(cost2(now)[di], cost_now);

            // v から辿れる頂点をすべて調べる
            rep(i, dirs.size()) {
                Coordinate next = now + dirs[i];

                if (field.is_out(next)) continue;
                if (field.is_obj(next)) continue;
                if (done2(next)[(i % 2)]) continue;

                long long c = 0;
                if ((i % 2) != di) c = 1;

                if (chmin(cost2(next)[i % 2], cost_now + c)) {
                    prev(next) = now;
                    que.push(Cell(next, i % 2, cost2(next)[i % 2]));
                }
            }
        }

        rep(y, H) rep(x, W) cost({y, x}) = min(cost2({y, x}));
        rep(y, H) rep(x, W) done({y, x}) = done2({y, x})[0] or done2({y, x})[1];
    }
};

int main() {
    ll H, W;
    cin >> H >> W;

    ll rs, cs;
    cin >> rs >> cs;

    ll rt, ct;
    cin >> rt >> ct;

    T90_43 grid(H, W);
    grid.input();

    grid.dijkstra({rs - 1, cs - 1});

    cout << grid.dist({rt - 1, ct - 1}) << endl;

    return 0;
}