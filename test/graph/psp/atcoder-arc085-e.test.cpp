#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc085/tasks/arc085_c"
// https://atcoder.jp/contests/arc085/submissions/53049176

#include "../../../graph/psp.cpp"

int main() {
    ll N;
    cin >> N;

    vll a(N);
    rep(i, N) cin >> a[i];

    // false: 割らない
    // true: 割る
    PSP<ll> flow(N);

    rep(i, N) {
        flow.set_gain_if_false(i, a[i]);

        for (ll j = 2 * i + 1; j < N; j += i + 1) {
            flow.set_inf_cost_if_true_false(i, j);
        }
    }

    ll ans = -flow.solve();
    cout << ans << endl;

    return 0;
}