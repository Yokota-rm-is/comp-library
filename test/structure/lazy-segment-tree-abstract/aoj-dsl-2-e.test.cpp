#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&"

#include "../../../structure/lazy-segment-tree-abstract.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = ll;
    auto op = [](S a, S b) { return a + b; };
    auto e = []() { return 0; };
    using F = ll;
    auto mapping = [](S a, F b) { return a + b; };
    auto composition = [](F a, F b) { return a + b; };
    auto id = []() { return 0; };
    LazySegmentTree<S, op, e, F, mapping, composition, id> tree(n, 0);

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            tree.apply(s - 1, t, x);
        }
        else {
            ll i;
            cin >> i;
            cout << tree.get(i - 1) << endl;
        }
    }

    return 0;
}