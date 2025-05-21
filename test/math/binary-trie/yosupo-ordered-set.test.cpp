#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include "../../../math/binary-trie.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ull> a(N);
    rep(i, N) cin >> a[i];

    BinaryTrie<ull> trie;
    rep(i, N) if (!trie.contains(a[i])) trie.insert(a[i]);

    while (Q--) {
        ll t;
        ull x;
        cin >> t >> x;

        if (t == 0) {
            if (!trie.contains(x)) trie.insert(x);
        }
        else if (t == 1) {
            if (trie.contains(x)) trie.erase(x);
        }
        else if (t == 2) {
            if (trie.count() < x) cout << -1 << endl;
            else cout << trie.kth_min(x) << endl;
        }
        else if (t == 3) {
            cout << trie.count_less_than_or_equal(x) << endl;
        }
        else if (t == 4) {
            ull ret = trie.find_less_than_or_equal(x);
            if (ret == numeric_limits<ull>::max()) cout << -1 << endl;
            else cout << ret << endl;
        } 
        else {
            ull ret = trie.find_greater_than_or_equal(x);
            if (ret == numeric_limits<ull>::max()) cout << -1 << endl;
            else cout << ret << endl;
        }
    }
}