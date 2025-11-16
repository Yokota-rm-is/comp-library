#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include "../../../structure/implicit-treap.cpp"

int main() {
    ll n, q;
    cin >> n >> q;

    vll a(n);
    rep(i, n) cin >> a[i];

    using S = ll;
    using F = ll;
    auto op = [](S a, S b) { return min(a, b); };
    auto e = []() { return inf64; };
    auto mapping = [](S x, F f) { 
        if (f == inf64) return x;
        return f; 
    };
    auto composition = [](F &f, F s) { 
        if (s == inf64) return;
        f = s; 
    };
    auto id = []() { return inf64; };

    ImplicitTreap<S, F, op, e, mapping, composition, id> tree(a);

    while (q--) {
        ll x, y, z;
        cin >> x >> y >> z;

        if (x == 0) {
            tree.rotate(y, z, z + 1);
        }
        else if (x == 1) {
            cout << tree.prod(y, z + 1) << endl;
        }
        else {
            tree.apply(y, z);
        }
    }

    return 0;
} 
