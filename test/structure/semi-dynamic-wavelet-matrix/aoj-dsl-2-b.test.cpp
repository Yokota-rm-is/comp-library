#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&"

#include "../../../structure/semi-dynamic-wavelet-matrix.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    SemiDynamicWaveletMatrix<ll> wm(n, 0);

    vll T(q), X(q), Y(q);

    rep(i, q) {
        cin >> T[i] >> X[i] >> Y[i];
        --X[i];
        if (T[i] == 0) {
            wm.simulate_add(X[i], Y[i]);
        }
    } 

    wm.build();

   rep(i, q) {
        ll t = T[i], x = X[i], y = Y[i];

        if (t == 0) {
            wm.add(x, y);
        }
        else {
            cout << wm.sum(x, y) << endl;
        }
    }

    return 0;
}