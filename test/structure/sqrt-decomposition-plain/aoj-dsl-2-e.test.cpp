#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&"

#include "../../../structure/sqrt-decomposition-plain.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    SqrtDecomposition<ll, ll> sd(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            sd.apply_add(s - 1, t, x);
        }
        else {
            ll i;
            cin >> i;
            cout << sd.get(i - 1) << endl;
        }
    }

    return 0;
}