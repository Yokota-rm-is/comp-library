#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../../math/binary-trie.cpp"

int main() {
    ll Q;
    cin >> Q;

    BinaryTrie<> trie;

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ull x;
            cin >> x;

            if (trie.contains(x)) continue;
            trie.insert(x);
        }
        else if (t == 1) {
            ull x;
            cin >> x;

            if (!trie.contains(x)) continue;
            trie.erase(x);
        }
        else {
            ull x;
            cin >> x;

            trie.apply_xor(x);
            cout << trie.min_element() << endl;
            trie.apply_xor(x);
        }
    }

    return 0;
}