#define PROBLEM "https://atcoder.jp/contests/abc353/tasks/abc353_e"

#include "../../../string/trie.cpp"


int main() {
    ll N;
    cin >> N;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    Trie trie;
    rep(i, N) {
        trie.insert(S[i]);
    }

    ll ans = 0;
    rep(i, N) {
        ll used = 1;

        auto pn = trie.search(S[i]);

        while (pn != trie.root) {
            ans += pn->depth * (pn->common - used);
            used = pn->common;
            pn = pn->p;
        }
    }

    cout << ans / 2 << endl;

    return 0;
} 
