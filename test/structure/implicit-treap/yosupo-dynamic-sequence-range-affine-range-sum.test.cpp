#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include "../../../structure/implicit-treap.cpp"
#include "../../../math/modint.cpp"

using mint = mint998;

int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ull> a(N);
    rep(i, N) cin >> a[i];

    using S = pair<mint, ll>;
    using F = pair<mint, mint>;
    auto op = [](S a, S b) { return make_pair(a.first + b.first, a.second + b.second); };
    auto e = []() { return make_pair<mint, ll>(0, 0); };
    auto mapping = [](S x, F f) { 
        return make_pair(x.first * f.first + f.second * x.second, x.second); 
    };
    auto composition = [](F &f, F s) { 
        f.second = s.first * f.second + s.second; 
        f.first = f.first * s.first; 
    };
    auto id = []() { return make_pair<mint, mint>(1, 0); };
    ImplicitTreap<S, F, op, e, mapping, composition, id> tree;

    rep(i, N) tree.insert(i, make_pair<mint, ll>(mint(a[i]), 1));

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll i;
            ull x;
            cin >> i >> x;
            tree.insert(i, make_pair<mint, ll>(x, 1));
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
            cout << tree.prod(l, r).first << endl;
        }
    }

    return 0;
}