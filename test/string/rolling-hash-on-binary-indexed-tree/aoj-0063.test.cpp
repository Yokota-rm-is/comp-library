#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0063"

#include "../../../string/rolling-hash-on-binary-indexed-tree.cpp"

int main() {
    string S;

    ll ans = 0;
    while (cin >> S) {
        ll N = S.size();
        RollingHashonBinaryIndexedTree bit(S);

        if (bit.get(0, N).is_palindrome()) ans++;
    }

    cout << ans << endl;

    return 0;
} 