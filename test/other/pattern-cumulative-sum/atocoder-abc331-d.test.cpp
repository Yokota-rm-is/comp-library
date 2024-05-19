#define PROBLEM "https://atcoder.jp/contests/abc331/tasks/abc331_d"

#include "../../../other/pattern-cumulative-sum.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vvll P(N, vll(N));
    rep(i, N) {
        rep(j, N) {
            char c;
            cin >> c;
            if (c == 'B') P[i][j] = 1;
            else P[i][j] = 0;
        }
    }

    PatternCumulativeSum<ll> pcs(P);

    while (Q--) {
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << pcs.sum(x1, y1, x2 + 1, y2 + 1) << endl;
    }

    return 0;
}