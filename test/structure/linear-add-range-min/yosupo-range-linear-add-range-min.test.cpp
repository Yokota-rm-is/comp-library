#define PROBLEM "https://judge.yosupo.jp/problem/range_linear_add_range_min"

#include "../../../structure/linear-add-range-min.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    LinearAddRangeMin<ll, ll> seg(a);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll l, r, b, c;
            cin >> l >> r >> b >> c;

            seg.apply(l, r, b, c);
        }
        else {
            ll l, r;
            cin >> l >> r;

            cout << seg.prod(l, r) << endl;
        }
    }
}

