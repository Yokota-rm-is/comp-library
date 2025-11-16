#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&"

#include "../../../structure/dual-segment-tree-abstract.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = pll;
    using F = pll;
    auto mapping = [](S x, F f) { return (x.first > f.first) ? x : f; };
    auto composition = [](F& f, F s) { if (s.first > f.first) f = s; };
    auto id = []() { return F(-1, 0); };

    DualSegmentTree<S, F, mapping, composition, id> tree(n, S(0, (1ll << 31) - 1));

    rep(i, q) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply(s, t + 1, {i, x});
        }
        else {
            ll i;
            cin >> i;
            cout << tree.get(i).second << endl;
        }
    }

    return 0;
}