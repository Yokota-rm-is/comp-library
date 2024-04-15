#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&"

#include "../../../structure/bit.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    BIT<ll> tree(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.add(s - 1, t, x);
        }
        else {
            ll s, t;
            cin >> s >> t;
            cout << tree.sum(s - 1, t) << endl;
        }
    }

    return 0;
}