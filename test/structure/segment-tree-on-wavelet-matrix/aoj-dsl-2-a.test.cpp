#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&"

#include "../../../structure/segment-tree-on-wavelet-matrix.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    SegmentTreeonWaveletMatrix<ll, ll, Set, Min> wm;
    vll A(n, (1ll << 31) - 1);

    rep(i, n) wm.add_point(i, A[i]);

    vll T(q), X(q), Y(q);

    rep(i, q) {
        cin >> T[i] >> X[i] >> Y[i];

        if (T[i] == 0) {
            A[X[i]] = Y[i];
            wm.add_point(X[i], A[X[i]]);
        }
    } 

    wm.build();
    A.assign(n, (1ll << 31) - 1);
    rep(i, n) wm.apply(i, A[i], A[i]);

    rep(i, q) {
        ll t = T[i], x = X[i], y = Y[i];

        if (t == 0) {
            wm.apply(x, A[x], wm.op.e());

            A[x] = y;
            wm.apply(x, A[x], A[x]);
        }
        else {
            cout << wm.prod(x, y + 1) << endl;
        }
    }

    return 0;
}