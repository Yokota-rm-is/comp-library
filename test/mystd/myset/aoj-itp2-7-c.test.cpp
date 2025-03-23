#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_C&"

#include "../../../mystd/myset.cpp"

int main() {
    Set<ll> st;

    ll q;
    cin >> q;

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x;
            cin >> x;

            st.insert(x);
            cout << st.size() << endl;
        }
        else if (t == 1) {
            ll x;
            cin >> x;

            cout << st.count(x) << endl;
        }
        else if (t == 2) {
            ll x;
            cin >> x;

            st.erase(x);
        }
        else {
            ll L, R;
            cin >> L >> R;

            for (auto p = st.lower_bound(L); p != st.end() and *p <= R; ++p) {
                cout << *p << endl;
            }
        }
    }

    return 0;
}