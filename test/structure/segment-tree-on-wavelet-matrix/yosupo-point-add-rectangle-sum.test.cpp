#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../../structure/segment-tree-on-wavelet-matrix.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll X(N), Y(N), W(N);
    SegmentTreeonWaveletMatrix<ll, ll, Add, Sum> wm;

    rep(i, N) {
        cin >> X[i] >> Y[i] >> W[i];
        wm.add_point(Y[i], X[i]);
    }

    vvll query(Q);
    rep(i, Q) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y, w;
            cin >> x >> y >> w;

            query[i] = {t, x, y, w};

            wm.add_point(y, x);
        }
        else {
            ll l, d, r, u;
            cin >> l >> d >> r >> u;

            query[i] = {t, l, d, r, u};
        }
    }

    wm.build();
    rep(i, N) {
        wm.apply(Y[i], X[i], W[i]);
    }

    rep(i, Q) {
        if (query[i][0] == 0) {
            ll x = query[i][1], y = query[i][2], w = query[i][3];
            wm.apply(y, x, w);
        }
        else {
            ll l = query[i][1], d = query[i][2], r = query[i][3], u = query[i][4];
            cout << wm.prod(u, l, r) - wm.prod(d, l, r) << endl;
        }
    }
}