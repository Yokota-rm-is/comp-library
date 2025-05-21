#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include "../../../mystd/myset.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    Set<ll> st;
    rep(i, N) st.insert(a[i]);

    while (Q--) {
        ll t, x;
        cin >> t >> x;

        if (t == 0) {
            st.insert(x);
        }
        else if (t == 1) {
            st.erase(x);
        }
        else if (t == 2) {
            if (st.size() < x) cout << -1 << endl;
            else cout << st.kth_min(x) << endl;
        }
        else if (t == 3) {
            cout << st.count_less_than_or_equal(x) << endl;
        }
        else if (t == 4) {
            auto it = st.find_less_than_or_equal(x);
            if (it == st.end()) cout << -1 << endl;
            else cout << *it << endl;
        } 
        else {
            auto it = st.find_greater_than_or_equal(x);
            if (it == st.end()) cout << -1 << endl;
            else cout << *it << endl;
        }
    }
}