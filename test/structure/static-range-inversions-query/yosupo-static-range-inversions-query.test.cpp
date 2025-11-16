#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../../../structure/static-range-inversions-query.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll A(N);
    rep(i, N) cin >> A[i];

    StaticRangeInversionsQuery<ll> sriq(A);

    while (Q--) {
        ll l, r;
        cin >> l >> r;

        cout << sriq(l, r) << endl;
    }

    return 0;
}