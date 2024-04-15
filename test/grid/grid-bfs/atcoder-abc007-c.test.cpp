#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc007/tasks/abc007_3"
// https://atcoder.jp/contests/abc007/submissions/52418706

#include "../../../grid/grid-bfs.cpp"

int main() {
    ll R, C;
    cin >> R >> C;

    GridBFS grid(R, C);
    ll sy, sx;
    cin >> sy >> sx;
    grid.start = {sy - 1, sx - 1};
    ll gy, gx;
    cin >> gy >> gx;
    grid.goal = {gy - 1, gx - 1};
    grid.input();

    grid.bfs();

    cout << grid.dist(grid.goal) << endl;

    return 0;
}