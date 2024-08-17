#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&"

#include "../../../structure/sqrt-decomposition.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    SqrtDecomposition<ll, ll, Add, Sum> sd(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            sd.apply(s - 1, t, x);
        }
        else {
            ll s, t;
            cin >> s >> t;
            cout << sd.prod(s - 1, t) << endl;
        }
    }

    return 0;
}