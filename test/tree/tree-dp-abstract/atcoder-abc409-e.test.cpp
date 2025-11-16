#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc409/tasks/abc409_e"

#include "../../../tree/tree-dp-abstract.cpp"

int main() {
    ll N;
    cin >> N;

    vll x(N);
    rep(i, N) cin >> x[i];

    using S = pll;
    auto merge = [](vector<S> prods) {
        S ret = {0, 0};
        fore(prod, prods) {
            ret.first += prod.first;
            ret.second += prod.second;
        }
        return ret;
    };
    auto e = []() -> S { return {0, 0}; };
    using w_edge = ll;
    auto put_edge = [](S prod, w_edge weight) -> S {
        S ret = prod;
        ret.second += abs(prod.first) * weight;
        return ret;
    };
    auto id_edge = []() -> w_edge { return 0; };
    using w_vertex = ll;
    auto put_vertex = [](S prod, w_vertex weight) -> S {
        S ret = prod;
        ret.first += weight;
        return ret;
    };
    auto id_vertex = []() -> w_vertex { return 0; };

    TreeDP<S, merge, e, w_edge, put_edge, id_edge, w_vertex, put_vertex, id_vertex> tree(N);
    
    rep(i, N - 1) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        tree.connect(u, v, w);
    }

    rep(i, N) tree.set_vertex_weight(i, x[i]);

    auto result = tree.build(0);

    cout << result.second << endl;

    return 0;
}