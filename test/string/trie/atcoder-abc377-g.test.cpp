#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc377/tasks/abc377_g"
// https://atcoder.jp/contests/abc377/submissions/65328881

#include "../../../string/trie.cpp"

int main() {
    ll N;
    cin >> N;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    Trie trie(inf64);

    auto f = [&](auto node, const string& word) {
        chmin(node->data, (ll)word.size());
    };

    rep(i, N) {
        ll ans = S[i].size();
        auto pn = trie.search(S[i]);

        while (true) {
            chmin(ans, ll(pn->data + S[i].size() - 2 * pn->depth));

            if (pn == trie.root) break;
            pn = pn->p;
        }

        cout << ans << endl;

        trie.insert(S[i], f);
    }

    return 0;
} 
