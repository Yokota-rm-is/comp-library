#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_e"

#include "../../../structure/semi-dynamic-wavelet-matrix.cpp"

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    vll A(N);
    rep(i, N) cin >> A[i];

    SemiDynamicWaveletMatrix<ll> wm(A);
    wm.build();

    rep(i, N - M + 1) {
        cout << wm.sum_min_k(i, i + M, K);
        if (i < N - M) cout << " ";
    }
    cout << endl;
}