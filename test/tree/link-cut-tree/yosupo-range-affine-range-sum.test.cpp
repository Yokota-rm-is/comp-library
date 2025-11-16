#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../../tree/link-cut-tree.cpp"
#include "../../../math/modint.cpp"
using mint = mint998;

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) {
        cin >> a[i];
    }

    using S = pair<mint, mint>;
    auto op = [](S a, S b) { return S(a.first + b.first, a.second + b.second); };
    auto e = []() { return S(0, 0); };
    using F = pair<mint, mint>;
    auto mapping = [](S a, F f) { return S(a.first * f.first + a.second * f.second, a.second); };
    auto composition = [](F f1, F f2) { 
        return F(f2.first * f1.first, f2.first * f1.second + f2.second);
    };
    auto id = []() { return F(1, 0); };
    LinkCutTree<S, op, e, F, mapping, composition, id> tree;

    using Node = LinkCutTree<S, op, e, F, mapping, composition, id>::Node;
    vector<Node*> nodes(N);
    rep(i, N) {
        nodes[i] = tree.make_node(i, S(a[i], 1));
    }

    rep(i, N - 1) {
        tree.link(nodes[i], nodes[i + 1]);
    }

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll l, r, b, c;
            cin >> l >> r >> b >> c;
            tree.apply(nodes[l], nodes[r - 1], F(b, c));
        }
        else {
            ll l, r;
            cin >> l >> r;

            mint ans = tree.prod(nodes[l], nodes[r - 1]).first;

            cout << ans << endl;
        }
    }

    return 0;
}