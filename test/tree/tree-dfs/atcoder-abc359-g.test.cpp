#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc359/tasks/abc359_g"

#include "../../../tree/tree-dfs.cpp"
#include "../../../tree/tree-dp-reroot-abstract.cpp"


int main() {
    ll N;
    cin >> N;

    vll U(N - 1), V(N - 1);
    rep(i, N - 1) cin >> U[i] >> V[i];
    --U; --V;

    vll A(N);
    rep(i, N) cin >> A[i];

    TreeDFS<ll> tree(N);
    rep(i, N - 1) {
        tree.connect(U[i], V[i], 1);
    }
    tree.build(0);

    map<ll, vll> mp;
    rep(i, N) {
        mp[A[i]].push_back(i);
    }

    ll ans = 0;

    fore(p, mp) {
        if (p.second.size() == 1) continue;

        auto [nodes, edges] = tree.get_auxilary_tree(p.second);

        map<ll, ll> remap;
        rep(i, nodes.size()) {
            remap[nodes[i]] = i;
        }

        vll B(nodes.size());
        rep(i, nodes.size()) {
            B[i] = A[nodes[i]];
        }
        
        using S = pll;
        auto merge = [](S a, S b) -> S {
            return {a.first + b.first, a.second + b.second};
        };
        auto e = []() -> S {
            return {0, 0};
        };
        using w_edge = ll;
        auto put_edge = [](S x, w_edge y) -> S {
            return {x.first + y * x.second, x.second};
        };
        auto id_edge = []() -> w_edge {
            return 0;
        };
        using w_vertex = ll;
        auto put_vertex = [](S x, w_vertex y) -> S {
            return {x.first, x.second + y};
        };
        auto id_vertex = []() -> w_vertex {
            return 0;
        };
        TreeDP<S, merge, e, w_edge, put_edge, id_edge, w_vertex, put_vertex, id_vertex> tree_dp(nodes.size());
        rep(i, edges.size()) {
            auto [u, v, w] = edges[i];
            u = remap[u];
            v = remap[v];
            tree_dp.connect(u, v, w);
        }
        rep(i, nodes.size()) {
            tree_dp.set_vertex_weight(i, B[i] == p.first ? 1 : 0);
        }
        tree_dp.build(0);
        auto prod = tree_dp.reroot();
        rep(i, prod.size()) {
            if (B[i] != p.first) continue;
            ans += prod[i].first;
        }
    }

    cout << ans / 2 << endl;

    return 0;
} 
