#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"

#include "../../../structure/dynamic-wavelet-matrix.cpp"

int main() {
    ll N;
    cin >> N;

    vll a(N);
    rep(i, N) cin >> a[i];

    DynamicWaveletMatrix<ll> wm(max(a), a);

    ll Q;
    cin >> Q;

    while (Q--) {
        ll l, r, D;
        cin >> l >> r >> D;
        ++r;

        ll ans = inf64;

        if (wm.count(l, r, D) > 0) {
            ans = 0;
        }
        else {
            ll prev = wm.prev_value(l, r, D);
            if (prev != wm.NOTFOUND) chmin(ans, D - prev);
            ll next = wm.next_value(l, r, D);
            if (next != wm.NOTFOUND) chmin(ans, next - D);
        }
        cout << ans << endl;
    }
}