#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&"

#include "../../../structure/dualsegmenttree.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    RangeAddPointGet<ll, ll> tree(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply(s - 1, t, x);
        }
        else {
            ll i;
            cin >> i;
            cout << tree.get(i - 1) << endl;
        }
    }

    return 0;
}