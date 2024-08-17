#define PROBLEM "https://atcoder.jp/contests/abc324/tasks/abc324_c"

#include "../../../string/rolling-hash.cpp"

int main() {
    ll N;
    input(N);

    string T;
    input(T);

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vll ans;

    RollingHash rht(T);

    rep(i, N) {
        RollingHash rhs(S[i]);
    
        if (S[i].size() == T.size()) {
            if (lcp(rht, rhs) + lcs(rht, rhs) >= (ll)T.size() - 1) {
                ans.push_back(i);
                continue;
            }
        }
        else if (S[i].size() == T.size() + 1) {
            if (lcp(rht, rhs) + lcs(rht, rhs) >= (ll)T.size()) {
                ans.push_back(i);
                continue;
            }
        }
        else if (S[i].size() == T.size() - 1) {
            if (lcp(rht, rhs) + lcs(rht, rhs) >= (ll)T.size() - 1) {
                ans.push_back(i);
                continue;
            }
        }
    }
    
    cout << ans.size() << endl;
    ++ans;
    cout << ans << endl;

    return 0;
} 
