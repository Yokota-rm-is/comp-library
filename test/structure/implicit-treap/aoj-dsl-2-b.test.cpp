#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&"

#include "../../../structure/implicit-treap.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = ll;
    using F = ll;
    auto op = [](S a, S b) { return a + b; };
    auto e = []() { return 0ll; };
    auto mapping = [](S x, F f) { 
        return x + f; 
    };
    auto composition = [](F &f, F s) { 
        f += s; 
    };
    auto id = []() { return 0ll; };
    ImplicitTreap<S, F, op, e, mapping, composition, id> tree(n, 0);

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