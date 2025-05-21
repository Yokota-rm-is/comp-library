#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_B&"

#include "../../../math/binary-trie.cpp"

int main() {
    BinaryTrie<> trie;

    ll q;
    cin >> q;

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ull x;
            cin >> x;

            if (!trie.contains(x)) trie.insert(x);
            cout << trie.count() << endl;
        }
        else if (t == 1) {
            ull x;
            cin >> x;

            cout << trie.count(x) << endl;
        }
        else {
            ull x;
            cin >> x;

            if (trie.contains(x)) trie.erase(x);
        }
    }

    return 0;
}