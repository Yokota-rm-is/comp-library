#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../../structure/bit-on-wavelet-matrix.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll X(N), Y(N), W(N);
    BITonWaveletMatrix<ll> wm;

    rep(i, N) {
        cin >> X[i] >> Y[i] >> W[i];
        wm.add_point(X[i], Y[i]);
    }

    vvll query(Q);
    rep(i, Q) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y, w;
            cin >> x >> y >> w;

            query[i] = {t, x, y, w};

            wm.add_point(x, y);
        }
        else {
            ll l, d, r, u;
            cin >> l >> d >> r >> u;

            query[i] = {t, l, d, r, u};
        }
    }

    wm.build();
    rep(i, N) {
        wm.add(X[i], Y[i], W[i]);
    }

    rep(i, Q) {
        if (query[i][0] == 0) {
            ll x = query[i][1], y = query[i][2], w = query[i][3];
            wm.add(x, y, w);
        }
        else {
            ll l = query[i][1], d = query[i][2], r = query[i][3], u = query[i][4];
            cout << wm.sum(l, r, d, u) << endl;
        }
    }
}