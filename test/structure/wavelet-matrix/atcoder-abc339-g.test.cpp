#define PROBLEM "https://atcoder.jp/contests/abc339/tasks/abc339_g"

#include "../../../structure/wavelet-matrix.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];

    WaveletMatrix<ll> wm(A);

    ll Q;
    cin >> Q;

    ll B = 0;

    while (Q--) {
        ll alpha, beta, gamma;
        cin >> alpha >> beta >> gamma;

        ll L = alpha ^ B;
        ll R = beta ^ B;
        ll X = gamma ^ B;

        --L;
        
        ll ans = wm.sum_less_than(L, R, X) + wm.count(L, R, X) * X;
        cout << ans << endl;
        B = ans;
    }

    return 0;
} 
