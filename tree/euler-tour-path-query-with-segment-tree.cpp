#pragma once
#include "../base.cpp"

#if __cplusplus >= 201703L
template<class S, 
        auto op,
        auto e,
        class F,
        auto mapping>
#else
    template<class S,
        S (*op)(S, S),
        S (*e)(),
        class F,
        S (*mapping)(S, F)>
#endif
struct SegmentTree {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>, "op must be function<S(S, S)>");
    static_assert(is_convertible_v<decltype(e), function<S()>>, "e must be function<S()>");
    static_assert(is_convertible_v<decltype(mapping), function<S(S, F)>>, "mapping must be function<S(S, F)>");
#endif
    long long N, _N, height;
    vector<S> node;

    SegmentTree(ll _N) : _N(_N) {
        height = 1;
        N = 1;

        while (N < _N) {
            N *= 2;
            height++;
        }

        node.resize(2 * N, e());
        repd(i, 1, N) update(i);
    }

    void build() {
        repd(i, 1, N) update(i);
    }

    void apply(long long p, S f, bool no_update=false) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        node[k] = mapping(node[k], f);
        if (!no_update) rep(i, 1, height) update(k >> i);
    }

    S get(long long p) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        return node[k];
    }

    S prod(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, node[l++]);
            if (r & 1) smr = op(node[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S prod_all() {
        return node[1];
    }

private:
    void update(long long k) {
        assert(1 <= k and k <= N - 1);

        node[k] = op(node[k * 2], node[k * 2 + 1]);
    }
};

// オイラーツアー
// 2頂点間のパスに対して，逆元を持つ演算(sum, xorなど)が可能
#if __cplusplus >= 201703L
template<class S, 
        auto op,
        auto inv,
        auto e,
        class F,
        auto mapping>
#else
    template<class S,
        S (*op)(S, S),
        S (*inv)(S),
        S (*e)(),
        class F,
        S (*mapping)(S, F)>
#endif
struct EulerTourPath {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>, "op must be function<S(S, S)>");
    static_assert(is_convertible_v<decltype(inv), function<S(S)>>, "inv must be function<S(S)>");
    static_assert(is_convertible_v<decltype(e), function<S()>>, "e must be function<S()>");
    static_assert(is_convertible_v<decltype(mapping), function<S(S, F)>>, "mapping must be function<S(S, F)>");
#endif

    struct Edge {
        long long from;
        long long to;
        long long idx;
        
        explicit Edge(long long u = -1, long long v = -1, long long i = -1) : from(u), to(v), idx(i) {};

        bool operator < (const Edge& other) const {
            if (from == other.from) return to < other.to;
            else return from < other.from;
        }

        friend ostream& operator << (ostream& os, const Edge& edge) {
            return os << edge.to;
        }
    };

    using pll = pair<long long, long long>;

    long long V;
    vector<vector<Edge>> G;
    vector<bool> seen;

    vector<S> weights;

    long long time;
    vector<long long> pre_order, post_order;
    vector<long long> visited_order;
    vector<pll> visited_depth;

    long long edge_index;
    bool built = false;

    SegmentTree<S, op, e, F, mapping> seg;
    SegmentTree<pll, [](pll x, pll y){return (x.first < y.first ? x : y);}, [](){return pll(inf64, -1);}, pll, [](pll x, pll f){return f;}> seg_depth;

    EulerTourPath(long long N) : V(N), G(V), seg(4 * N - 2), seg_depth(4 * N - 2) {
        init();
    };

    void init() {
        time = 0;
        seen.assign(V, false);

        weights.resize(2 * V - 1, e());
        pre_order.assign(2 * V - 1, -1);
        post_order.assign(2 * V - 1, -1);

        edge_index = 0;
    }

    void connect(long long from, long long to) {
        connect(from, to, e());
    }

    void connect(long long from, long long to, S weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);
        assert(!built);

        G[from].emplace_back(from, to, edge_index);
        G[to].emplace_back(to, from, edge_index);

        weights[V + edge_index] = weight;

        edge_index++;
    }

    void set_vertex_weight(long long v, S w) {
        assert(0 <= v and v < V);
        assert(!built);

        weights[v] = w;
    }

    void build(long long root) {
        assert(0 <= root and root < V);

        dfs(root, 0);

        rep(i, visited_order.size()) {
            if (visited_order[i] >= 0) {
                long long v = visited_order[i];
                seg.node[seg.N + i] = weights[v];
                seg_depth.node[seg_depth.N + i] = visited_depth[i];
            }
            else {
                long long v = ~visited_order[i];
                seg.node[seg.N + i] = inv(weights[v]);
                seg_depth.node[seg_depth.N + i] = visited_depth[i];
            }
        }

        seg.build();
        seg_depth.build();

        built = true;
    }

    void apply_vertex(long long v, S f) {
        assert(0 <= v and v < V);
        assert(built);

        weights[v] = mapping(weights[v], f);

        long long pre = pre_order[v];
        seg.apply(pre, f);

        long long post = post_order[v];
        seg.apply(post, inv(f));
    }

    void apply_edge(long long i, S f) {
        assert(0 <= i and i < edge_index);
        assert(built);

        weights[V + i] = mapping(weights[V + i], f);

        long long pre = pre_order[V + i];
        seg.apply(pre, f);

        long long post = post_order[V + i];
        seg.apply(post, inv(f));
    }

    long long lca(long long u, long long v) {
        assert(0 <= min(u, v) and max(u, v) < V);
        assert(built);

        long long l = pre_order[u];
        long long r = pre_order[v];
        if (l > r) swap(l, r);
        return seg_depth.prod(l, r + 1).second;
    }

    S prod(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        ll r = post_order[v];
        return seg.prod(0, r);
    }

    S prod(long long u, long long v) {
        assert(0 <= min(u, v) and max(u, v) < V);
        assert(built);

        ll pu = post_order[u];
        ll pv = post_order[v];
        ll a = lca(u, v);
        ll pa = post_order[a];
        return seg.prod(0, pu) + seg.prod(0, pv) - 2 * seg.prod(0, pa) + seg.get(pre_order[a]);
    }

    S get_vertex(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        return weights[v];
    }

    S get_edge(long long i) {
        assert(0 <= i and i < edge_index);
        assert(built);

        return weights[V + i];
    }

private:
    void dfs(long long v, long long d) {
        seen[v] = true;

        visited_order.push_back(v);
        visited_depth.push_back({d, v});
        pre_order[v] = time++;

        for (auto& edge : G[v]) {
            if (seen[edge.to]) continue;

            visited_order.push_back(V + edge.idx);
            visited_depth.push_back({d + 1, edge.to});
            pre_order[V + edge.idx] = time++;

            dfs(edge.to, d + 1);

            visited_order.push_back(~(V + edge.idx));
            visited_depth.push_back({d, v});
            post_order[V + edge.idx] = time++;
        }

        visited_order.push_back(~v);
        visited_depth.push_back({d, v});
        post_order[v] = time++;
    }
};
