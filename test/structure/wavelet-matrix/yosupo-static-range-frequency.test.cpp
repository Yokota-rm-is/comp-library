#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "../../../structure/wavelet-matrix.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    if (N == 0) {
        rep(i, Q) cout << 0 << endl;
        return 0;
    }
    
    WaveletMatrix<ll> wm(a);

    rep(i, Q) {
        ll l, r, x;
        cin >> l >> r >> x;

        cout << wm.count(l, r, x) << endl;
    }
}