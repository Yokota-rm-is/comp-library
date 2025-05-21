#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_A&"

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
        else {
            ull x;
            cin >> x;

            cout << trie.count(x) << endl;
        }
    }

    return 0;
}