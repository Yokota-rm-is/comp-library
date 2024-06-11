#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc324/tasks/abc324_c"

#include "../../../string/rolling-hash.cpp"

int main() {
    ll N;
    input(N);

    string T;
    input(T);

    RollingHash rh(T);

    set<ull> st;
    st.insert(rh.get());
    rep(i, T.size() + 1) {
        rep(c, 'a', 'z' + 1) {
            st.insert(rh.get(0, i) + Hash61(c) + rh.get(i, T.size()));
        }
    }
    
    rep(i, T.size()) {
        st.insert(rh.get(0, i) + rh.get(i + 1, T.size()));
        
        rep(c, 'a', 'z' + 1) {
            st.insert(rh.get(0, i) + Hash61(c) + rh.get(i + 1, T.size()));
        }
    }

    vll ans;
    rep(i, N) {
        string S;
        cin >> S;
        if (st.contains(RollingHash(S).get())) ans.push_back(i);
    }
    
    cout << ans.size() << endl;
    if (ans.size() > 0) {
        ++ans;
        cout << ans << endl;
    }

    return 0;
} 
