#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../../structure/wavelet-matrix.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    WaveletMatrix<ll> wm(a);

    rep(i, Q) {
        ll l, r, k;
        cin >> l >> r >> k;

        cout << wm.kth_min(l, r, k + 1) << endl;
    }
}