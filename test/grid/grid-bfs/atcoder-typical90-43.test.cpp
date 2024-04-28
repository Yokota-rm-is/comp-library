#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_aq"
// https://atcoder.jp/contests/typical90/submissions/52922278

#include "../../../grid/grid-bfs.cpp"

struct T90_43 : GridBFS {
    T90_43 (long long h, long long w) : GridBFS(h, w) {}

    void bfs01(Coordinate start) {
        assert(!seen(start) and !field.is_out(start) and !field.is_obj(start));

        deque<Coordinate> que;

        // 初期条件 (頂点 start を初期ノードとする)
        cost(start) = 0;

        que.push_front(start); // noq を橙色頂点にする

        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            Coordinate now = que.front(); // キューから先頭頂点を取り出す
            que.pop_front();

            if (seen(now)) continue;
            seen(now) = true;

            // v から辿れる頂点をすべて調べる
            rep(i, dirs.size()) {
                Coordinate next = now;
                ll c = 0; 
                if (now != start) c = 1; // ここにコストが1になる条件を書く

                while (true) {
                    next += dirs[i];
                    if (field.is_out(next)) break;
                    if (field.is_obj(next)) break;

                    if (cost(next) >= cost(now) + c) {
                        cost(next) = cost(now) + c;
                        prev(next) = now;
                        
                        if (c == 0) que.push_front(next);
                        else que.push_back(next);
                    }
                    else break;
                }
            }
        }
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

    grid.bfs01({rs - 1, cs - 1});

    cout << grid.dist({rt - 1, ct - 1}) << endl;

    return 0;
}