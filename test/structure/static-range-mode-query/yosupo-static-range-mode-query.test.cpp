#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"

#include "../../../structure/static-range-mode-query.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];
    
    SqrtDecomposition<ll> sd(a);

    rep(i, Q) {
        ll l, r;
        cin >> l >> r;

        auto ans = sd.query(l, r);
        
        cout << ans.value << " " << ans.freq << endl;
    }
}