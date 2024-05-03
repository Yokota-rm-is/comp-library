#define PROBLEM "https://yukicoder.me/problems/no/1541"

#include "../../../graph/psp.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll k(N), C(N);
    vvll A(N), B(N);

    rep(i, N) {
        cin >> k[i] >> C[i];
        A[i].resize(k[i]);
        B[i].resize(k[i]);

        fore(a, A[i]) {
            cin >> a;
            --a;
        }
        fore(b, B[i]) cin >> b;
    }

    // true: 勉強する
    // false: 勉強しない
    PSP<ll> flow(N);

    rep(i, N) {
        flow.set_gain_if_true(i, M);
        flow.set_cost_if_true(i, C[i]);

        rep(j, k[i]) {
            flow.set_gain_if_both_true(i, A[i][j], B[i][j]);
        }
    }

    ll ans = -flow.solve();
    cout << ans << endl;

    return 0;
}