#define PROBLEM "https://atcoder.jp/contests/abc220/tasks/abc220_f"

#include "../../../tree/tree-dp-abstract.cpp"


int main() {
    ll N;
    cin >> N;

    struct S {
        ll prod;
        ll n_vertex;

        S(ll prod = 0, ll n_vertex = 0) : prod(prod), n_vertex(n_vertex) {}
        operator ll() const { return prod; }
    };
    
    auto merge = [](S x, S y) -> S {
        return S(x.prod + y.prod, x.n_vertex + y.n_vertex);
    };
    auto e = []() -> S {
        return S(0, 0);
    };

    using w_edge = ll;
    auto put_edge = [](S x, w_edge y) -> S {
        return S(x.prod + y * x.n_vertex, x.n_vertex);
    };
    auto id_edge = []() -> w_edge {
        return 1;
    };

    using w_vertex = ll;
    auto put_vertex = [](S x, w_vertex y) -> S {
        return S(x.prod, x.n_vertex + y);
    };
    auto id_vertex = []() -> w_vertex {
        return 0;
    };

    TreeDP<S, merge, e, w_edge, put_edge, id_edge, w_vertex, put_vertex, id_vertex> tree(N);
    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;
        --u; --v;

        tree.connect(u, v, 1);
    }

    rep(i, N) tree.set_vertex_weight(i, 1);

    tree.build(0);
    auto ans = tree.reroot();

    rep(i, N) {
        cout << ans[i] << endl;
    }

    return 0;
}