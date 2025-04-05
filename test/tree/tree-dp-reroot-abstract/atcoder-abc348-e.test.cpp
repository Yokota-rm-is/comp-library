#define PROBLEM "https://atcoder.jp/contests/abc348/tasks/abc348_e"

#include "../../../tree/tree-dp-reroot-abstract.cpp"

int main() {
    ll N;
    cin >> N;

    struct S {
        ll prod;
        ll sum_c;

        S(ll prod = 0, ll sum_c = 0) : prod(prod), sum_c(sum_c) {}
    };

    auto merge = [](S x, S y) -> S {
        return S(x.prod + y.prod, x.sum_c + y.sum_c);
    };
    auto e = []() -> S {
        return S(0, 0);
    };

    using w_edge = ll;
    auto put_edge = [](S x, w_edge y) -> S {
        return S(x.prod + y * x.sum_c, x.sum_c);
    };
    auto id_edge = []() -> w_edge {
        return 0;
    };

    using w_vertex = ll;
    auto put_vertex = [](S x, w_vertex y) -> S {
        return S(x.prod, x.sum_c + y);
    };
    auto id_vertex = []() -> w_vertex {
        return 0;
    };

    TreeDP<S, merge, e, w_edge, put_edge, id_edge, w_vertex, put_vertex, id_vertex> tree(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        --a; --b;

        tree.connect(a, b, 1);
    }

    rep(i, N) {
        ll c;
        cin >> c;
        tree.set_vertex_weight(i, c);
    }

    tree.build(0);
    auto dp = tree.reroot();

    ll ans = inf64;
    rep(i, N) chmin(ans, dp[i].prod);

    cout << ans << endl;

    return 0;
}