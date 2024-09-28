#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&"

#include "../../../structure/bit-on-wavelet-matrix.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    vll A(n, 0);

    BITonWaveletMatrix<ll> wm;

    vll T(q), X(q), Y(q);

    rep(i, q) {
        cin >> T[i] >> X[i] >> Y[i];
        --X[i];
        if (T[i] == 0) {
            A[X[i]] += Y[i];
            wm.add_point(X[i], A[X[i]]);
        }
    } 

    wm.build();
    A.assign(n, 0);

   rep(i, q) {
        ll t = T[i], x = X[i], y = Y[i];

        if (t == 0) {
            if (A[x] != 0) wm.set(x, A[x], 0);
            A[x] += y;
            wm.add(x, A[x], A[x]);
        }
        else {
            cout << wm.sum(x, y, 0, inf64) << endl;
        }
    }

    return 0;
}