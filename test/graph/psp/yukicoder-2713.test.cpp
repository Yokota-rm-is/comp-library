#define PROBLEM "https://yukicoder.me/problems/no/2713"

#include "../../../graph/psp.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll A(N);
    fore(a, A) cin >> a;
    
    vll B(M);
    fore(b, B) cin >> b;

    vvll C(M);
    rep(i, M) {
        ll K;
        cin >> K;
        C[i].resize(K);

        fore(c, C[i]) {
            cin >> c; 
            --c;
        }
    }

    // true: 使う
    // false: 使わない
    PSP<ll> flow(N);

    rep(i, N) {
        flow.set_cost_if_true(i, A[i]);
    }

    rep(i, M) {
        flow.set_gain_if_all_true(C[i], B[i]);
    }

    ll ans = -flow.solve();
    cout << ans << endl;

    return 0;
}