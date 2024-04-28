#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/atc001/tasks/dfs_a"
// https://atcoder.jp/contests/atc001/submissions/52920327

#include "../../../grid/grid-unionfind.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    GridUnionFind grid(H, W);
    grid.input();

    cout << YesNo(grid.reach_goal()) << endl;

    return 0;
}