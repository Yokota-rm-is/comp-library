#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc320/tasks/abc320_b"

#include "../../../string/manacher.cpp"

int main() {
    string S;
    cin >> S;

    Manacher<> manacher(S);

    ll ans = 0;

    rep(i, S.size()) rep(j, i + 1, S.size() + 1) {
        if (manacher.is_palindrome(i, j)) {
            chmax(ans, j - i);
        }
    }

    cout << ans << endl;

    return 0;
} 