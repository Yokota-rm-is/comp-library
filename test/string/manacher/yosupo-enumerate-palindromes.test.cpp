#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../../string/manacher.cpp"

int main() {
    string S;
    cin >> S;

    Manacher<> manacher(S);

    vector<long long> ans;
    rep(i, S.size()) {
        ans.push_back(manacher.get_palindrome_odd_len(i));
        if (i < S.size() - 1) ans.push_back(manacher.get_palindrome_even_len(i));
    }

    cout << ans << endl;

    return 0;
}