#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../../structure/segment-tree-on-wavelet-matrix.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll x(N), y(N), w(N);
    SegmentTreeonWaveletMatrix<ll, ll, Add, Sum> wm;

    rep(i, N) {
        cin >> x[i] >> y[i] >> w[i];
        wm.add_point(y[i], x[i]);
    }

    wm.build();
    rep(i, N) {
        wm.apply(y[i], x[i], w[i]);
    }

    rep(i, Q) {
        ll l, d, r, u;
        cin >> l >> d >> r >> u;

        cout << wm.prod(u, l, r) - wm.prod(d, l, r) << endl;
    }
}