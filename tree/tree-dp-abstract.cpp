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
    S (*merge)(vector<S>),
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
    static_assert(is_convertible_v<decltype(merge), function<S(vector<S>)>>, "merge must be function<S(vector<S>)>");
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
    vector<S> dp;

    TreeDP(long long N) : V(N), G(V) {
        init();
    };
    
    void init() {
        seen.assign(V, false);

        v_weights.resize(V, id_vertex());
        dp.resize(V);
    }
    
    void connect(long long from, long long to, w_edge weight = id_edge()) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        long long from_id = G[from].size();
        long long to_id = G[to].size();

        G[from].emplace_back(from, to, weight, to_id);
        G[to].emplace_back(to, from, weight, from_id);
    }

    void set_vertex_weight(long long v, w_vertex weight) {
        assert(0 <= v and v < V);

        v_weights[v] = weight;
    }

    S build(long long r) {
        return dfs(r);
    }

    S dfs(long long now) {
        assert(0 <= now and now < V);

        seen[now] = true;

        vector<S> prods(1, e());

        rep(i, G[now].size()) {
            Edge edge = G[now][i];
            long long next = edge.to;

            if (seen[next]) continue;

            prods.push_back(put_edge(dfs(next), edge.weight));
        }

        S ret = put_vertex(merge(prods), v_weights[now]);
        dp[now] = ret;

        return ret;
    }
};

template <class S, auto merge, auto e, class F, auto put_edge, auto id>
using TreeDPEdge = TreeDP<S, merge, e, F, put_edge, id, ll, [](S x, ll y) -> S { return x; }, []() -> ll { return 0; }>;
template <class S, auto merge, auto e, class F, auto put_vertex, auto id>
using TreeDPVertex = TreeDP<S, merge, e, ll, [](S x, ll y) -> S { return x; }, []() -> ll { return 0; }, F, put_vertex, id>;