#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&"

#include "../../../structure/implicit-treap.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = ll;
    using F = ll;
    auto op = [](S a, S b) { return min(a, b); };
    auto e = []() { return inf64; };
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