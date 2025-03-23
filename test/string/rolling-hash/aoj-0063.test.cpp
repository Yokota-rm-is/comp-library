#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0063"

#include "../../../string/rolling-hash.cpp"

int main() {
    string S;

    ll ans = 0;
    while (cin >> S) {
        ll N = S.size();
        RollingHash rh(S);

        if (rh.is_palindrome(0, N)) ans++;
    }

    cout << ans << endl;

    return 0;
} 