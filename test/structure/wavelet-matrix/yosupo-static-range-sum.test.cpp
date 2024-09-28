#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../../structure/wavelet-matrix.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    WaveletMatrix<ll> wm(a);

    rep(i, Q) {
        ll l, r;
        cin >> l >> r;

        cout << wm.sum(l, r) << endl;
    }
}