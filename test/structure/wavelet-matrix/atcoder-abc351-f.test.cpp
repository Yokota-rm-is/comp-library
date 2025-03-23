#define PROBLEM "https://atcoder.jp/contests/abc351/tasks/abc351_f"

#include "../../../structure/wavelet-matrix.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];

    ll maxA = *max_element(A) + 1;

    WaveletMatrix<ll> wm(A);
    ll ans = 0;
    rep(i, N) {
        ll a = A[i];
        ll num = wm.count_in_range(i + 1, N, a, maxA);
        ll sum = wm.sum_in_range(i + 1, N, a, maxA);

        ans += sum - a * num;
    }

    cout << ans << endl;

    return 0;
} 