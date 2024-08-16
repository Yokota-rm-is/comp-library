#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../../structure/dynamic-wavelet-matrix.cpp"
#include "../../../other/compressor.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    Compressor<ll> comp(a);
    vll b = comp.compressed;

    DynamicWaveletMatrix<ll> wm(max(b), b);

    rep(i, Q) {
        ll l, r, k;
        cin >> l >> r >> k;

        ll ans = wm.kth_min(l, r, k + 1);

        cout << comp.retrieve(ans) << endl;
    }
}