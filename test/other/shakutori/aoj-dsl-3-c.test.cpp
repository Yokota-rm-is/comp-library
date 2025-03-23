#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C"

#include "../../../other/shakutori.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    while (Q--) {
        ll x;
        cin >> x;

        auto e = [&]() { return 0ll; };
        auto insert = [&](ll& value, ll idx) { value += a[idx]; };
        auto judge = [&](const ll& value) { return value <= x; };
        auto erase = [&](ll& value, ll idx) { value -= a[idx]; };

        cout << shakutori_inner_count<ll>(N, e, insert, judge, erase) << endl;
    }

    return 0;
}