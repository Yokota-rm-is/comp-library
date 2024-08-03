#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "../../../other/static-range-frequency.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    StaticRangeFrequency<ll> srf(a);

    while (Q--) {
        ll l, r, x;
        cin >> l >> r >> x;

        ll ans = srf.count(l, r, x);
        
        cout << ans << endl;
    }

    return 0;
} 