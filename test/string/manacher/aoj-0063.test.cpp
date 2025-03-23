#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0063"

#include "../../../string/manacher.cpp"

int main() {
    string S;

    ll ans = 0;
    while (cin >> S) {
        ll N = S.size();
        Manacher<> manacher(S);

        if (manacher.is_palindrome(0, N)) ans++;
    }

    cout << ans << endl;

    return 0;
} 