#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&"

#include "../../../structure/lazysegmenttree.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    RangeSetRangeSum<ll, ll> tree(n, (1ll << 31) - 1);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply(s, t + 1, x);
        }
        else {
            ll i;
            cin >> i;
            cout << tree.get(i) << endl;
        }
    }

    return 0;
}