#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&"

#include "../../../structure/implicit-treap.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = pll;
    using F = ll;
    auto op = [](S a, S b) { return make_pair(a.first + b.first, a.second + b.second); };
    auto e = []() { return make_pair(0ll, 0ll); };
    auto mapping = [](S x, F f) { 
        return make_pair(x.first + f * x.second, x.second);
    };
    auto composition = [](F &f, F s) { 
        f += s; 
    };
    auto id = []() { return 0ll; };
    ImplicitTreap<S, F, op, e, mapping, composition, id> tree(n, make_pair(0ll, 1ll));

    while (q--) {
        ll c;
        cin >> c;

        if (c == 0) {
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