#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&"

#include "../../../structure/sqrt-decomposition.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    SqrtDecomposition<ll, ll, Add, Min> sd(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            sd.apply(s, t + 1, x);
        }
        else {
            ll s, t;
            cin >> s >> t;
            cout << sd.prod(s, t + 1) << endl;
        }
    }

    return 0;
}