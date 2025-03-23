#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc377/tasks/abc377_g"
// https://atcoder.jp/contests/abc377/submissions/62017457

#include "../../../string/trie-tree.cpp"

int main() {
    ll N;
    cin >> N;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vll ans(N);
    rep(i, N) ans[i] = S[i].size();
    Trie trie;

    trie.insert(S[0]);

    rep(i, 1, N) {
        auto f = [&](auto node) {
            chmin(ans[i], ll(S[i].size()) - node.depth + (node.min_l - node.depth));
        };

        trie.search(S[i], f);
        trie.insert(S[i]);
    }

    rep(i, N) cout << ans[i] << endl;

    return 0;
} 
