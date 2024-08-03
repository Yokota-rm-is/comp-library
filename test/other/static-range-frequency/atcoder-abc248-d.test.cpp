#define PROBLEM "https://atcoder.jp/contests/abc248/tasks/abc248_d"

#include "../../../other/static-range-frequency.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];

    StaticRangeFrequency<ll> srf(A);

    ll Q;
    cin >> Q;
    while (Q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        --l;
        
        cout << srf.count(l, r, x) << endl;
    }

    return 0;
} 