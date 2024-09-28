#define PROBLEM "https://atcoder.jp/contests/abc306/tasks/abc306_e"

#include "../../../structure/semi-dynamic-wavelet-matrix.cpp"

int main() {
    ll N, K, Q;
    cin >> N >> K >> Q;

    vll X(Q), Y(Q);
    rep(i, Q) cin >> X[i] >> Y[i];
    --X;

    SemiDynamicWaveletMatrix<ll> wm(N, 0);
    rep(i, Q) wm.simulate_set(X[i], Y[i]);

    wm.build();

    rep(i, Q) {
        ll x = X[i], y = Y[i];
        wm.set(x, y);
        ll ans = wm.sum_max_k(0, N, K);
        
        cout << ans << endl;
    }
    
    return 0;
} 