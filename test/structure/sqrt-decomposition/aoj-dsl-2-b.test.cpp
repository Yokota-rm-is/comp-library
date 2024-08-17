#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&"

#include "../../../structure/sqrt-decomposition.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    SqrtDecomposition<ll, ll, Add, Sum> sd(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y;
            cin >> x >> y;
            sd.apply(x - 1, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << sd.prod(x - 1, y) << endl;
        }
    }

    return 0;
}