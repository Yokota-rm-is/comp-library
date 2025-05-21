#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I&"

#include "../../../structure/lazy-segment-tree-abstract.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = pll;
    auto op = [](S a, S b) { return S(a.first + b.first, a.second + b.second); };
    auto e = []() { return S(0, 0); };
    using F = ll;
    auto mapping = [](S a, F b) { return (b != inf64) ? S(b * a.second, a.second) : a; };
    auto composition = [](F a, F b) { return (b != inf64) ? b : a; };
    auto id = []() { return inf64; };
    LazySegmentTree<S, op, e, F, mapping, composition, id> tree(n, S(0, 1));

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply(s, t + 1, x);
        }
        else {
            ll s, t;
            cin >> s >> t;
            cout << tree.prod(s, t + 1).first << endl;
        }
    }

    return 0;
}