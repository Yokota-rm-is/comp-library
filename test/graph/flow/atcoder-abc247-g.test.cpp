#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc247/tasks/abc247_g"
// https://atcoder.jp/contests/abc247/submissions/68685172

#include "../../../graph/flow.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N), B(N), C(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i];
    --A, --B;

    ll H = 150, W = 150;
    ll inf = 1e9;
    vvll grid(H, vll(W, inf));
    rep(i, N) {
        grid[A[i]][B[i]] = min(grid[A[i]][B[i]], inf - C[i]);
    }

    MinCostFlow<ll, ll> mcf(H + W + 2);
    ll s = H + W, t = s + 1;
    rep(i, H) {
        mcf.connect(s, i, 1, 0);
    }
    rep(i, H) rep(j, W) {
        if (grid[i][j] == inf) continue;
        mcf.connect(i, H + j, 1, grid[i][j]);
    }
    rep(j, W) {
        mcf.connect(H + j, t, 1, 0);
    }

    auto slope = mcf.slope(s, t);

    vll ans;
    rep(i, slope.size()) {
        auto [l, r] = slope[i].first;
        auto [a, b] = slope[i].second;
        rep(j, l + 1, r + 1) {
            ans.push_back(inf * j - (a * j + b));
        }
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }

    return 0;
}