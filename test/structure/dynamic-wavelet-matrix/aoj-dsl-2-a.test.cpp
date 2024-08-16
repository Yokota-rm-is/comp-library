#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&"

#include "../../../structure/dynamic-wavelet-matrix.cpp"
#include "../../../other/compressor.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    vll A(n);
    A.push_back((1ll << 31) - 1);

    vll T(q), X(q), Y(q);

    rep(i, q) {
        cin >> T[i] >> X[i] >> Y[i];
        if (T[i] == 0) A.push_back(Y[i]);
    }

    Compressor<ll> comp(A);

    DynamicWaveletMatrix<ll> wm(comp.find((1ll << 31) - 1), n, comp.find((1ll << 31) - 1));

    rep(i, q) {
        ll t = T[i], x = X[i], y = Y[i];

        if (t == 0) {
            y = comp.find(y);
            wm.set(x, y);
        }
        else {
            ll ans = wm.kth_min(x, y + 1, 1);
            cout << comp.retrieve(ans) << endl;
        }
    }

    return 0;
}