#define PROBLEM "https://yukicoder.me/problems/no/738"

#include "../../../structure/semi-dynamic-wavelet-matrix.cpp"

int main() {
    ll N, K;
    cin >> N >> K;

    vll A(N);
    rep(i, N) cin >> A[i];

    SemiDynamicWaveletMatrix<ll> wm(A);
    wm.build();

    ll ans = inf64;
    rep(i, N - K + 1) {
        auto [median_floor, median_ceil] = wm.median(i, i + K);

        {
            ll a = median_floor;
            ll count_upper = wm.count_more_than(i, i + K, a);
            ll sum_upper = wm.sum_more_than(i, i + K, a);
            ll cost_upper = sum_upper - count_upper * a;

            ll count_lower = wm.count_less_than(i, i + K, a);
            ll sum_lower = wm.sum_less_than(i, i + K, a);
            ll cost_lower = count_lower * a - sum_lower;

            chmin(ans, cost_upper + cost_lower);
        }

        if (median_ceil != median_floor) {
            ll a = median_ceil;
            ll count_upper = wm.count_more_than(i, i + K, a);
            ll sum_upper = wm.sum_more_than(i, i + K, a);
            ll cost_upper = sum_upper - count_upper * a;

            ll count_lower = wm.count_less_than(i, i + K, a);
            ll sum_lower = wm.sum_less_than(i, i + K, a);
            ll cost_lower = count_lower * a - sum_lower;

            chmin(ans, cost_upper + cost_lower);
        }
    }

    cout << ans << endl;
}