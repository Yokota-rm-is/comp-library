#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/atc001/tasks/dfs_a"
// https://atcoder.jp/contests/atc001/submissions/52418686

#include "../../../grid/grid-dfs.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    GridDFS grid(H, W);
    grid.input();

    grid.dfs();

    cout << YesNo(grid.reach_goal()) << endl;

    return 0;
}