#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I&"

#include "../../../structure/implicit-treap.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    using S = pll;
    using F = ll;
    auto op = [](S a, S b) { return make_pair(a.first + b.first, a.second + b.second); };
    auto e = []() { return make_pair(0ll, 0ll); };
    auto mapping = [](S x, F f) { 
        if (f == inf64) return x;
        return make_pair(f * x.second, x.second);
    };
    auto composition = [](F &f, F s) { 
        if (s == inf64) return;
        f = s; 
    };
    auto id = []() { return inf64; };
    ImplicitTreap<S, F, op, e, mapping, composition, id> tree(n, {0ll, 1ll});

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