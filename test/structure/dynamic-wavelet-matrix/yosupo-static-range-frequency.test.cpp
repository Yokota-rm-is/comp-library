#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "../../../structure/dynamic-wavelet-matrix.cpp"
#include "../../../other/compressor.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    if (N == 0) {
        rep(i, Q) cout << 0 << endl;
        return 0;
    }
    
    Compressor<ll> comp(a);
    vll b = comp.compressed;
    DynamicWaveletMatrix<ll> wm(max(b), b);

    rep(i, Q) {
        ll l, r, x;
        cin >> l >> r >> x;

        ll ans = 0;
        if (comp.contains(x)) {
            x = comp.find(x);
            ans = wm.count(l, r, x);
        }

        cout << ans << endl;
    }
}