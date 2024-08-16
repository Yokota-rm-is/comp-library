#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include "../../../structure/splay-tree.cpp"
#include "../../../math/modint.cpp"

using mint = mint998;

int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ull> a(N);
    rep(i, N) cin >> a[i];

    SplayTreeByIdx<mint, pair<mint, mint>, Affine, Sum> tree;

    rep(i, N) tree.insert(i, a[i]);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll i;
            ull x;
            cin >> i >> x;
            tree.insert(i, x);
        }
        else if (t == 1) {
            ll i;
            cin >> i;
            tree.erase(i);
        }
        else if (t == 2) {
            ll l, r;
            cin >> l >> r;
            tree.reverse(l, r);
        }
        else if (t == 3) {
            ll l, r;
            ull b, c;
            cin >> l >> r >> b >> c;
            tree.apply(l, r, {b, c});
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << tree.prod(l, r) << endl;
        }
    }

    return 0;
}