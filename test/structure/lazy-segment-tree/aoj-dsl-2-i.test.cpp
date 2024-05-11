#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I&"

#include "../../../structure/lazy-segment-tree.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    RangeSetRangeSum<ll, ll> tree(n, 0);
    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply(s, t + 1, x);
        }
        else {
            ll s, t;
            cin >> s >> t;
            cout << tree.prod(s, t + 1) << endl;
        }
    }

    return 0;
}