#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&"

#include "../../../structure/segment-tree-on-wavelet-matrix.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    SegmentTreeonWaveletMatrix<ll, ll, Add, Sum> wm;

    vll A(n, 0);
    rep(i, n) wm.add_point(A[i], i);

    vll T(q), X(q), Y(q);

    rep(i, q) {
        cin >> T[i] >> X[i] >> Y[i];
        --X[i];
        if (T[i] == 0) {
            A[X[i]] += Y[i];
            wm.add_point(A[X[i]], X[i]);
        }
    } 

    wm.build();
    A.assign(n, 0);
    rep(i, n) wm.apply(A[i], i, A[i]);

   rep(i, q) {
        ll t = T[i], x = X[i], y = Y[i];

        if (t == 0) {
            wm.apply(A[x], x, -A[x]);

            A[x] += y;
            wm.apply(A[x], x, A[x]);
        }
        else {
            cout << wm.prod(inf64, x, y) << endl;
        }
    }

    return 0;
}