#define PROBLEM "https://atcoder.jp/contests/abc193/tasks/abc193_f"

#include "../../../graph/psp.cpp"
#include "../../../grid/grid-bfs.cpp"

int main() {
    ll N;
    cin >> N;

    GridBFS grid(N);
    grid.input();

    vector<char> vc = {'B', 'W'};
    
    // true: 決め打ちに合っている
    // false: 合っていない
    PSP<ll> flow(N * N);

    rep(y, N) rep(x, N) {
        ll index = N * y + x;
        char c = grid.field({y, x});
        char target = vc[(x + y) % 2];

        if (c == '?') {}
        else if (c == target) flow.set_cost_if_false(index, inf64);
        else flow.set_cost_if_true(index, inf64);

        if (x < N - 1) flow.set_gain_if_same(index, index + 1, 1);
        if (y < N - 1) flow.set_gain_if_same(index, index + N, 1);
    }

    ll ans = -flow.solve();

    cout << ans << endl;

    return 0;
}