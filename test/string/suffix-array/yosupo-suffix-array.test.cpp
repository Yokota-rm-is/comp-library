#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../../string/suffix-array.cpp"


int main() {
    string S;
    cin >> S;

    SuffixArray sa(S);
    vll ans;
    rep(i, sa.size()) ans.push_back(sa[i]);
    cout << ans << endl;

    return 0;
}