#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../../structure/semi-dynamic-wavelet-matrix.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    SemiDynamicWaveletMatrix<ll> wm(a);
    wm.build();

    rep(i, Q) {
        ll l, r;
        cin >> l >> r;

        cout << wm.sum(l, r) << endl;
    }
}