#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_A&"

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
        else {
            ll x;
            cin >> x;

            cout << st.count(x) << endl;
        }
    }

    return 0;
}