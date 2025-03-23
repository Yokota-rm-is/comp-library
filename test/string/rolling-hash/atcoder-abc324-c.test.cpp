#define PROBLEM "https://atcoder.jp/contests/abc324/tasks/abc324_c"

#include "../../../string/rolling-hash.cpp"

int main() {
    ll N;
    cin >> N;

    string T;
    cin >> T;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vll ans;

    RollingHash rht(T);

    rep(i, N) {
        RollingHash rhs(S[i]);
    
        if (S[i].size() == T.size()) {
            if (rht == rhs) {
                ans.push_back(i);
                continue;
            }

            rep(j, T.size()) {
                if (rhs.erase(j) == rht.erase(j)) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        else if (S[i].size() == T.size() + 1) {
            rep(j, S[i].size()) {
                if (rhs.erase(j) == rht) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        else if (S[i].size() == T.size() - 1) {
            rep(j, T.size()) {
                if (rhs == rht.erase(j)) {
                    ans.push_back(i);
                    break;
                }
            }
        }
    }
    
    cout << ans.size() << endl;
    ++ans;
    cout << ans << endl;

    return 0;
} 
