#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&"

#include "../../../structure/lazy-segment-tree-abstract.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = ll;
    auto op = [](S a, S b) { return min(a, b); };
    auto e = []() { return inf64; };
    using F = ll;
    auto mapping = [](S a, F b) { return (b != inf64) ? b : a; };
    auto composition = [](F& a, F b) { if (b != inf64) a = b; };
    auto id = []() { return inf64; };
    LazySegmentTree<S, op, e, F, mapping, composition, id> tree(n, (1ll << 31) - 1);

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
            cout << tree.prod(s, t + 1) << endl;
        }
    }

    return 0;
}