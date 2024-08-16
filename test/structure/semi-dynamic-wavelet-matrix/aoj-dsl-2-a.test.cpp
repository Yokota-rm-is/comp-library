#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&"

#include "../../../structure/semi-dynamic-wavelet-matrix.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    SemiDynamicWaveletMatrix<ll> wm(n, (1ll << 31) - 1);

    vll T(q), X(q), Y(q);

    rep(i, q) {
        cin >> T[i] >> X[i] >> Y[i];

        if (T[i] == 0) {
            wm.simulate_set(X[i], Y[i]);
        }
    } 

    wm.build();

    rep(i, q) {
        ll t = T[i], x = X[i], y = Y[i];

        if (t == 0) {
            wm.set(x, y);
        }
        else {
            cout << wm.kth_min(x, y + 1, 1) << endl;
        }

    }

    return 0;
}