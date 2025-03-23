#define PROBLEM "https://yukicoder.me/problems/no/2234"

#include "../../../string/rolling-hash.cpp"

int main() {
    string S;
    cin >> S;

    ll N = S.size();
    RollingHash rh(S);

    ll idx = N - 1;

    rep(i, N) {
        auto hash = rh.get(i, N);
        if (hash.is_palindrome()) {
            idx = i;
            break;
        }
    }

    string ans = S;
    repd(i, idx) ans += S[i];

    cout << ans << endl;

    return 0;
} 
