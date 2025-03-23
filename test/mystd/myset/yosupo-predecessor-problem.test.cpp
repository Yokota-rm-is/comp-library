#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "../../../mystd/myset.cpp"


int main() {
    ll N, Q;
    cin >> N >> Q;

    string T;
    cin >> T;

    Set<ll> st;
    rep(i, N) {
        if (T[i] == '1') {
            st.insert(i);
        }
    }

    while (Q--) {
        ll c, k;
        cin >> c >> k;

        if (c == 0) {
            st.insert(k);
        } 
        else if (c == 1) {
            st.erase(k);
        } 
        else if (c == 2) {
            cout << st.contains(k) << endl;
        }
        else if (c == 3) {
            auto p = st.find_greater_than_or_equal(k);
            cout << (p != st.end() ? *p : -1) << endl;
        }
        else {
            auto p = st.find_less_than_or_equal(k);
            cout << (p != st.end() ? *p : -1) << endl;
        }
    }
}