#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc005/tasks/arc005_3"
// https://atcoder.jp/contests/arc005/submissions/52537951

#include "../../../grid/grid-bfs.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    GridBFS grid(H, W);
    grid.input();

    grid.bfs01(grid.start);
    ll ans = (grid.get_dist(grid.goal) <= 2);

    cout << YESNO(ans) << endl;

    return 0;
}