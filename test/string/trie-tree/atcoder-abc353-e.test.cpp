#define PROBLEM "https://atcoder.jp/contests/abc353/tasks/abc353_e"
// https://atcoder.jp/contests/abc353/submissions/53397052

#include "../../../string/trie-tree.cpp"


int main() {
    ll N;
    cin >> N;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    Trie<26, 'a'> trie;
    rep(i, N) {
        trie.insert(S[i]);
    }

    ll ans = 0;
    auto A = trie.nodes;
    rep(i, 1, A.size()) {
        ans += A[i].common * (A[i].common - 1) / 2;
    }

    cout << ans << endl;

    return 0;
} 
