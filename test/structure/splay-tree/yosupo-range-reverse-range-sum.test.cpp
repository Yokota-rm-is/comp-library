#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../../../structure/splay-tree.cpp"


int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ull> a(N);
    rep(i, N) cin >> a[i];

    SplayTreeByIdx<ll, ll, NoMapping, Sum> tree;

    rep(i, N) tree.insert_at(i, a[i]);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll l, r;
            cin >> l >> r;
            tree.reverse(l, r);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << tree.prod(l, r) << endl;
        }
    }

    return 0;
}