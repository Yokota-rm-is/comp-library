#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&"

#include "../../../structure/lazy-segment-tree-abstract.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = pll;
    auto op = [](S a, S b) { return S(a.first + b.first, a.second + b.second); };
    auto e = []() { return S(0, 0); };
    using F = ll;
    auto mapping = [](S a, F b) { return S(a.first + b * a.second, a.second); };
    auto composition = [](F a, F b) { return a + b; };
    auto id = []() { return 0; };
    LazySegmentTree<S, op, e, F, mapping, composition, id> tree(n, S(0, 1));

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply(s - 1, t, x);
        }
        else {
            ll s, t;
            cin >> s >> t;
            cout << tree.prod(s - 1, t).first << endl;
        }
    }

    return 0;
}