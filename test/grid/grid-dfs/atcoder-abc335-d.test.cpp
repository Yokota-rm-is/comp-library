#define PROBLEM "https://atcoder.jp/contests/abc335/tasks/abc335_d"

#include "../../../grid/grid-dfs.cpp"

int main() {
    ll N;
    cin >> N;

    GridDFS grid(N);

    auto A = grid.spiral_search();
    Grid<ll> ans(N, N, 0);

    rep(i, A.size()) {
        auto a = A[i];
        ans(a) = i + 1;
    }

    rep(y, N) {
        rep(x, N) {
            if (y == N / 2 and x == N / 2) {
                cout << "T";
            }
            else {
                cout << ans(y, x);
            }

            if (x < N - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}