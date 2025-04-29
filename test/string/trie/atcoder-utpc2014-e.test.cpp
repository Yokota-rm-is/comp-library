#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/utpc2014/tasks/utpc2014_e"
// https://atcoder.jp/contests/utpc2014/submissions/65324019

#include "../../../string/trie.cpp"

int main() {
    ll N;
    cin >> N;

    vector<string> A(N);
    vll B(N);
    rep(i, N) cin >> A[i] >> B[i];

    Trie<pll> trie({0, 0});

    rep(i, N) {
        reverse(A[i]);
        auto pn = trie.insert(A[i]);
        pn->data.second += B[i];

        while (pn != trie.root) {
            auto ppn = pn->p;
            fore(p, ppn->ch) {
                auto [c, pcn] = p;

                chmax(ppn->data.first, pcn->data.first + pcn->data.second);
            }

            pn = ppn;
        }

        cout << trie.root->data.first << endl;
    }

    return 0;
} 
