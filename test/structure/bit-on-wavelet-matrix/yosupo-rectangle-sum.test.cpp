#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../../structure/bit-on-wavelet-matrix.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll x(N), y(N), w(N);
    BITonWaveletMatrix<ll> wm;

    rep(i, N) {
        cin >> x[i] >> y[i] >> w[i];
        wm.add_point(x[i], y[i]);
    }

    wm.build();
    rep(i, N) {
        wm.add(x[i], y[i], w[i]);
    }

    rep(i, Q) {
        ll l, d, r, u;
        cin >> l >> d >> r >> u;

        cout << wm.sum(l, r, d, u) << endl;
    }
}