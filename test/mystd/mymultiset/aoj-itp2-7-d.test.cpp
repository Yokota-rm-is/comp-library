#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_D&"

#include "../../../mystd/mymultiset.cpp"

int main() {
    MultiSet<ll> ms;

    ll q;
    cin >> q;

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x;
            cin >> x;

            ms.insert(x);
            cout << ms.count_all() << endl;
        }
        else if (t == 1) {
            ll x;
            cin >> x;

            cout << ms.count(x) << endl;
        }
        else if (t == 2) {
            ll x;
            cin >> x;

            ms.erase_all(x);
        }
        else {
            ll L, R;
            cin >> L >> R;

            for (auto p = ms.lower_bound(L); p != ms.end() and p->first <= R; ++p) {
                ll x = p->first;
                ll n = p->second;

                rep(i, n) cout << x << endl;

            }
        }
    }

    return 0;
}