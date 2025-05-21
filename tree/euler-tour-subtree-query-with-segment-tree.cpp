#pragma once
#include "../base.cpp"

#if __cplusplus >= 201703L
    template<class S, 
        auto op,
        auto e,
        class F,
        auto mapping,
        auto id>
#else
    template<class S,
        S (*op)(S, S),
        S (*e)(),
        class F,
        S (*mapping)(S, F),
        F (*id)()>
#endif
struct EulerTourSubtree {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>, "op must be function<S(S, S)>");
    static_assert(is_convertible_v<decltype(e), function<S()>>, "e must be function<S()>");
    static_assert(is_convertible_v<decltype(mapping), function<S(S, F)>>, "mapping must be function<S(S, F)>");
    static_assert(is_convertible_v<decltype(id), function<F()>>, "id must be function<F()>");

    static_assert(op(S(), e()) == S(), "op(S(), e()) must be S()");
    static_assert(mapping(S(), id()) == S(), "mapping(S(), id()) must be S()");
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

    struct SegmentTree {
        long long N, _N, height;
        vector<S> node;

        SegmentTree(ll _N) : _N(_N) {
            init();
        }

        void init() {
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

        void apply(long long p, F f, bool no_update=false) {
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
        // k番目のノードの値を子の値で更新
        void update(long long k) {
            assert(1 <= k and k <= N - 1);

            node[k] = op(node[k * 2], node[k * 2 + 1]);
        }
    };

    using pll = pair<long long, long long>;

    long long V;
    vector<vector<Edge>> G;
    vector<bool> seen;

    vector<S> weights;

    long long time;
    vector<long long> pre_order, post_order;

    long long edge_index;
    bool built = false;

    SegmentTree seg;

    EulerTourSubtree(long long N) : V(N), G(V), seg(2 * V - 1) {
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

        rep(i, pre_order.size()) {
            long long p = pre_order[i];
            seg.apply(p, weights[i], true);
        }

        seg.build();
        built = true;
    }

    void apply_vertex(long long v, S f) {
        assert(0 <= v and v < V);
        assert(built);

        weights[v] += f;

        long long pre = pre_order[v];
        seg.apply(pre, f);
    }

    void apply_edge(long long i, S f) {
        assert(0 <= i and i < edge_index);
        assert(built);

        long long pre = pre_order[V + i];
        seg.add(pre, f);
    }

    S prod(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        ll l = pre_order[v];
        ll r = post_order[v];
        
        return seg.prod(l, r);
    }

    S get_vertex(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        return weights[v];
    }

private:
    void dfs(long long v, long long d) {
        seen[v] = true;

        pre_order[v] = time++;

        for (auto& edge : G[v]) {
            if (seen[edge.to]) continue;

            pre_order[V + edge.idx] = time++;

            dfs(edge.to, d + 1);

            post_order[V + edge.idx] = time;
        }

        post_order[v] = time;
    }
};
