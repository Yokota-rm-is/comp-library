#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_c"
// https://atcoder.jp/contests/tenka1-2016-final/submissions/65328536

#include "../../../string/trie.cpp"

int main() {
    string S;
    cin >> S;

    ll M;
    cin >> M;

    vector<string> P(M);
    rep(i, M) cin >> P[i];

    vll W(M);
    rep(i, M) cin >> W[i];


    Trie<ll> trie(0);
    rep(i, M) {
        auto pn = trie.insert(P[i]);
        chmax(pn->data, W[i]);
    }

    vll dp(S.size() + 1, 0);
    rep(i, S.size()) {
        string T = S.substr(i, 200);

        chmax(dp[i + 1], dp[i]);

        auto f = [&](auto pn) {
            chmax(dp[i + pn->depth], dp[i] + pn->data);
        };

        trie.search(T, f);
    }

    cout << dp[S.size()] << endl;

    return 0;
} 