#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&"

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
            ll x, y;
            cin >> x >> y;
            tree.apply(x - 1, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << tree.prod(x - 1, y) << endl;
        }
    }

    return 0;
}