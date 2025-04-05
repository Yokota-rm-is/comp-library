#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include "../../../tree/tree-dp-reroot-abstract.cpp"

int main() {
    ll n;
    cin >> n;

    using S = ll;
    auto merge = [](S x, S y) -> S {
        return max(x, y);
    };

    auto e = []() -> S {
        return 0;
    };

    using F = ll;
    auto put_edge = [](S x, F y) -> S {
        return x + y;
    };

    auto id_edge = []() -> F {
        return 0;
    };

    TreeDPEdge<S, merge, e, F, put_edge, id_edge> tree(n);

    // TreeDPEdge
    rep(i, n - 1) {
        ll s, t;
        cin >> s >> t;
        --s; --t;

        tree.connect(s, t, 1);
    }

    tree.build(0);
    auto ans = tree.reroot();

    rep(i, n) {
        cout << 2 * n - 2 - ans[i] << endl;
    }

    return 0;
}