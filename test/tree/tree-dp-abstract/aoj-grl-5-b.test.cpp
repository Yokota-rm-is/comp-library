#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B&"

#include "../../../tree/tree-dp-abstract.cpp"

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
    auto id = []() -> F {
        return 0;
    };

    TreeDPEdge<S, merge, e, F, put_edge, id> tree(n);
    rep(i, n - 1) {
        ll s, t, w;
        cin >> s >> t >> w;

        tree.connect(s, t, w);
    }

    tree.build(0);
    auto ans = tree.reroot();

    rep(i, n) {
        cout << ans[i] << endl;
    }

    return 0;
}