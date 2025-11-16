#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc228/tasks/abc228_f"
// https://atcoder.jp/contests/abc228/submissions/68273056

#include "../../../other/cumulative-sum-2d.cpp"
#include "../../../structure/segment-tree-2d-abstract.cpp"

int main() {
    ll H, W, h1, w1, h2, w2;
    cin >> H >> W >> h1 >> w1 >> h2 >> w2;

    chmin(h2, h1);
    chmin(w2, w1);

    vvll A(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    CumulativeSum2D<ll> cs(A);

    vvll B(H - h2 + 1, vector<ll>(W - w2 + 1));
    rep(i, H - h2 + 1) rep(j, W - w2 + 1) {
        B[i][j] = cs.sum(i, j, i + h2, j + w2);
    }

    using S = ll;
    auto op = [](S a, S b) { return max(a, b); };
    auto e = []() { return 0; };
    using F = ll;
    auto mapping = [](S a, F f) { return a + f; };
    SegmentTree2D<S, op, e, F, mapping> seg(B);

    ll ans = 0;
    rep(i, H - h1 + 1) rep(j, W - w1 + 1) {
        ll ans_i = cs.sum(i, j, i + h1, j + w1) - seg.prod(i, j, i + h1 - h2 + 1, j + w1 - w2 + 1);

        chmax(ans, ans_i);
    }

    cout << ans << endl;

    return 0;
} 
