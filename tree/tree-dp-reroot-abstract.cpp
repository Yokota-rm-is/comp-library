#pragma once
#include "../base.cpp"

/**
 * @brief tree-dp
 * @docs docs/tree/tree-dp.md
*/

/**
    ... --> par --> edge1 --> child1 --> ...
                --> edge2 --> child2 --> ...
                --> ...
                --> edgeN --> childN --> ...
    という木構造に対して、各頂点に対して以下の処理を行う

    ... --> (prod <- put_vertex(par)) --> (prod <- merge([prod1, ...])) --> (prod <- put_edge(edge1)) --> (prod <- put_vertex(child1)) --> ...
                                                                        --> (prod <- put_edge(edge2)) --> (prod <- put_vertex(child2)) --> ...
                                                                        --> ...
                                                                        --> (prod <- put_edge(edgeN)) --> (prod <- put_vertex(childN)) --> ...

*/
#if __cplusplus >= 201703L
template <class S,
    auto merge,
    auto e,
    class w_edge,
    auto put_edge,
    auto id_edge,
    class w_vertex,
    auto put_vertex,
    auto id_vertex>
#else
template <class S,
    S (*merge)(S, S),
    S (*e)(),
    class w_edge,
    S (*put_edge)(S, w_edge),
    w_edge (*id_edge)(),
    class w_vertex,
    S (*put_vertex)(S, w_vertex),
    w_vertex (*id_vertex)()>
#endif
struct TreeDP {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(merge), function<S(S, S)>>, "merge must be function<S(S, S)>");
    static_assert(is_convertible_v<decltype(e), function<S()>>, "e must be function<S()>");
    static_assert(is_convertible_v<decltype(put_edge), function<S(S, w_edge)>>, "put_edge must be function<S(S, w_edge)>");
    static_assert(is_convertible_v<decltype(id_edge), function<w_edge()>>, "id_edge must be function<w_edge()>");
    static_assert(is_convertible_v<decltype(put_vertex), function<S(S, w_vertex)>>, "put_vertex must be function<S(S, w_vertex)>");
    static_assert(is_convertible_v<decltype(id_vertex), function<w_vertex()>>, "id_vertex must be function<w_vertex()>");
#endif

    struct Edge {
        long long from;
        long long to;
        w_edge weight;
        long long rev;
        
        explicit Edge(long long u = -1, long long v = -1, w_edge w = 1, long long r = -1) : from(u), to(v), weight(w), rev(r) {};

        bool operator < (const Edge& other) const {
            if (from == other.from) {
                if (to == other.to) return weight < other.weight;
                else return to < other.to;
            }
            else return from < other.from;
        }

        friend ostream& operator << (ostream& os, const Edge& edge) {
            return os << edge.to;
        }
    };

    long long V;
    vector<vector<Edge>> G;
    vector<bool> seen;

    vector<w_vertex> v_weights;

    // 全方位木dp用
    vector<vector<S>> dp;
    vector<S> prod_all;
    long long root;
    bool built = false;

    TreeDP(long long N) : V(N), G(V) {
        init();
    };
    
    void init() {
        seen.assign(V, false);

        v_weights.resize(V, id_vertex());
        dp.resize(V);
        prod_all.assign(V, e());
    }
    
    void connect(long long from, long long to, w_edge weight = id_edge()) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        long long from_id = G[from].size();
        long long to_id = G[to].size();

        G[from].emplace_back(from, to, weight, to_id);
        G[to].emplace_back(to, from, weight, from_id);

        dp[from].push_back(e());
        dp[to].push_back(e());
    }

    void set_vertex_weight(long long v, w_vertex weight) {
        assert(0 <= v and v < V);

        v_weights[v] = weight;
    }

    S build(long long r) {
        built = true;
        root = r;
        return dfs(root);
    }

    vector<S> reroot() {
        assert(built);
        prod(root, e());

        return prod_all;
    }

    S dfs(long long now) {
        assert(0 <= now and now < V);

        S ret = e();

        seen[now] = true;

        rep(i, G[now].size()) {
            Edge edge = G[now][i];
            long long next = edge.to;

            if (seen[next]) continue;

            dp[now][i] = dfs(next);
            ret = merge(ret, put_edge(dp[now][i], edge.weight));
        }

        return put_vertex(ret, v_weights[now]);
    }

    void prod(long long now, const S& dp_p, Edge e_p = Edge()) {
        long long deg = G[now].size();

        if (e_p.rev != -1) dp[now][e_p.rev] = dp_p;

        vector<S> prod_l(deg + 1, e()), prod_r(deg + 1, e());

        rep(i, deg) {
            Edge edge = G[now][i];
            prod_l[i + 1] = merge(prod_l[i], put_edge(dp[now][i], edge.weight));
        }

        repd(i, deg) {
            Edge edge = G[now][i];
            prod_r[i] = merge(prod_r[i + 1], put_edge(dp[now][i], edge.weight));
        }

        prod_all[now] = put_vertex(prod_l.back(), v_weights[now]);

        rep(i, deg) {
            if (i == e_p.rev) continue;

            Edge edge = G[now][i];
            long long child = edge.to;
            prod(child, put_vertex(merge(prod_l[i], prod_r[i + 1]), v_weights[now]), edge);
        }
    }
};

template <class S, auto merge, auto e, class F, auto put_edge, auto id>
using TreeDPEdge = TreeDP<S, merge, e, F, put_edge, id, ll, [](S x, ll y) -> S { return x; }, []() -> ll { return 0; }>;
template <class S, auto merge, auto e, class F, auto put_vertex, auto id>
using TreeDPVertex = TreeDP<S, merge, e, ll, [](S x, ll y) -> S { return x; }, []() -> ll { return 0; }, F, put_vertex, id>;