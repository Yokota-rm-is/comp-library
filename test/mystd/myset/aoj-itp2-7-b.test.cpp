#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_B&"

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
        else {
            ll x;
            cin >> x;

            st.erase(x);
        }
    }

    return 0;
}