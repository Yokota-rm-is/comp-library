#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_f"
// https://atcoder.jp/contests/abc281/submissions/65812784

#include "../../../math/binary-trie.cpp"

int main() {
    ll N;
    cin >> N;

    vector<ull> A(N);
    rep(i, N) cin >> A[i];

    BinaryTrie<ull, 64, ll> trie;
    rep(i, N) {
        trie.insert(A[i]);
    }

    repd(i, 30) {
        rep(j, trie.A[i].size()) {
            BinaryTrie<ull, 64, ll>::Node* node = trie.A[i][j].get();

            if (node->ch[0] == trie.NIL and node->ch[1] == trie.NIL) continue;
            else if (node->ch[0] == trie.NIL) {
                node->data = node->ch[1]->data;
                continue;
            }
            else if (node->ch[1] == trie.NIL) {
                node->data = node->ch[0]->data;
                continue;
            }

            node->data = min(node->ch[0]->data, node->ch[1]->data) + (1ll << (29 - i));
        }
    }

    ll ans = trie.root->data;
    cout << ans << endl;

    return 0;
}