#define PROBLEM "https://yukicoder.me/problems/no/2234"

#include "../../../string/manacher.cpp"

int main() {
    string S;
    cin >> S;

    ll N = S.size();
    Manacher<> manacher(S);

    ll idx = N - 1;

    rep(i, N) {
        if (manacher.is_palindrome(i, N)) {
            idx = i;
            break;
        }
    }

    string ans = S;
    repd(i, idx) ans += S[i];

    cout << ans << endl;

    return 0;
} 