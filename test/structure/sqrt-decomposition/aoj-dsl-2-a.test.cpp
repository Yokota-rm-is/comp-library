#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&"

#include "../../../structure/sqrt-decomposition.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    SqrtDecomposition<ll, ll, Set, Min> sd(n, (1ll << 31) - 1);

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y;
            cin >> x >> y;
            sd.apply(x, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << sd.prod(x, y + 1) << endl;
        }
    }

    return 0;
}