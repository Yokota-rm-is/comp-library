#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&"

#include "../../../structure/implicit-treap.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = ll;
    using F = ll;
    auto op = [](S a, S b) { return min(a, b); };
    auto e = []() { return (1ll << 31) - 1; };
    auto mapping = [](S x, F f) { 
        if (f == (1ll << 31) - 1) return x;
        return f; 
    };
    auto composition = [](F &f, F s) { 
        if (s == (1ll << 31) - 1) return;
        f = s; 
    };
    auto id = []() { return (1ll << 31) - 1; };
    ImplicitTreap<S, F, op, e, mapping, composition, id> tree(n, (1ll << 31) - 1);

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y;
            cin >> x >> y;
            tree.apply(x, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << tree.prod(x, y + 1) << endl;
        }
    }

    return 0;
}