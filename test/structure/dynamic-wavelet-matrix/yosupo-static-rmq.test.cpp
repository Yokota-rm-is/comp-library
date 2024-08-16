#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

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
        ll l, r;
        cin >> l >> r;

        ll ans = wm.kth_min(l, r, 1);
        ans = comp.retrieve(ans);

        cout << ans << endl;
    }
}