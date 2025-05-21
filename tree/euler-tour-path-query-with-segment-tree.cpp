#pragma once
#include "../base.cpp"

template<typename T>
struct EulerTourPath {
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

#if __cplusplus >= 201703L
    template<class S, 
        auto op,
        auto e>
#else
    template<class S,
        S (*op)(S, S),
        S (*e)()>
#endif
    struct SegmentTree {
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
    
        void add(long long p, S f, bool no_update=false) {
            assert(0 <= p and p < _N);
    
            long long k = p + N;
            node[k] += f;
            if (!no_update) rep(i, 1, height) update(k >> i);
        }

        void set(long long p, S f, bool no_update=false) {
            assert(0 <= p and p < _N);
    
            long long k = p + N;
            node[k] = f;
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

    using pll = pair<long long, long long>;

    long long V;
    vector<vector<Edge>> G;
    vector<bool> seen;

    vector<T> weights;

    long long time;
    vector<long long> pre_order, post_order;
    vector<long long> visited_order;
    vector<pll> visited_depth;

    long long edge_index;
    bool built = false;

    SegmentTree<T, [](T x, T y){return x + y;}, [](){return 0;}> seg_sum;
    SegmentTree<T, [](T x, T y){return max(x, y);}, [](){return -inf64;}> seg_max;
    SegmentTree<T, [](T x, T y){return min(x, y);}, [](){return inf64;}> seg_min;
    SegmentTree<pll, [](pll x, pll y){return (x.first < y.first ? x : y);}, [](){return pll(inf64, -1);}> seg_depth;

    long long e = inf64;

    EulerTourPath(long long N) : V(N), G(V), seg_sum(4 * V - 2), seg_max(4 * V - 2), seg_min(4 * V - 2), seg_depth(4 * V - 2) {
        init();
    };

    void init() {
        time = 0;
        seen.assign(V, false);

        weights.resize(2 * V - 1, e);
        pre_order.assign(2 * V - 1, -1);
        post_order.assign(2 * V - 1, -1);

        edge_index = 0;
    }

    void connect(long long from, long long to) {
        connect(from, to, e);
    }

    void connect(long long from, long long to, T weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);
        assert(!built);

        G[from].emplace_back(from, to, edge_index);
        G[to].emplace_back(to, from, edge_index);

        weights[V + edge_index] = weight;

        edge_index++;
    }

    void set_vertex_weight(long long v, T w) {
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
                if (weights[v] != e) {
                    seg_sum.set(i, weights[v], true);
                    seg_max.set(i, weights[v], true);
                    seg_min.set(i, weights[v], true);
                }
                seg_depth.set(i, visited_depth[i], true);
            }
            else {
                long long v = ~visited_order[i];
                if (weights[~visited_order[i]] != e) {
                    seg_sum.set(i, -weights[v], true);
                    seg_max.set(i, weights[v], true);
                    seg_min.set(i, weights[v], true);
                }
                seg_depth.set(i, visited_depth[i], true);
            }
        }

        seg_sum.build();
        seg_max.build();
        seg_min.build();
        seg_depth.build();

        built = true;
    }

    void add_vertex(long long v, T f) {
        assert(0 <= v and v < V);
        assert(built);

        weights[v] += f;

        long long pre = pre_order[v];
        seg_sum.add(pre, f);
        seg_max.add(pre, f);
        seg_min.add(pre, f);

        long long post = post_order[v];
        seg_sum.add(post, -f);
        seg_max.add(post, f);
        seg_min.add(post, f);
    }

    void set_vertex(long long v, T f) {
        assert(0 <= v and v < V);
        assert(built);

        weights[v] = f;

        long long pre = pre_order[v];
        seg_sum.set(pre, f);
        seg_max.set(pre, f);
        seg_min.set(pre, f);

        long long post = post_order[v];
        seg_sum.set(post, -f);
        seg_max.set(post, f);
        seg_min.set(post, f);
    }

    void add_edge(long long i, T f) {
        assert(0 <= i and i < edge_index);
        assert(built);

        long long pre = pre_order[V + i];
        seg_sum.add(pre, f);
        seg_max.add(pre, f);
        seg_min.add(pre, f);

        long long post = post_order[V + i];
        seg_sum.add(post, -f);
        seg_max.add(post, f);
        seg_min.add(post, f);
    }

    void set_edge(long long i, T f) {
        assert(0 <= i and i < edge_index);
        assert(built);

        long long pre = pre_order[V + i];
        seg_sum.set(pre, f);
        seg_max.set(pre, f);
        seg_min.set(pre, f);

        long long post = post_order[V + i];
        seg_sum.set(post, -f);
        seg_max.set(post, f);
        seg_min.set(post, f);
    }

    long long lca(long long u, long long v) {
        assert(0 <= min(u, v) and max(u, v) < V);
        assert(built);

        long long l = pre_order[u];
        long long r = pre_order[v];
        if (l > r) swap(l, r);
        return seg_depth.prod(l, r + 1).second;
    }

    T prod_sum(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        ll r = post_order[v];
        return seg_sum.prod(0, r);
    }

    T prod_max(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        ll r = post_order[v];
        return seg_max.prod(0, r);
    }

    T prod_min(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        ll r = post_order[v];
        return seg_min.prod(0, r);
    }

    T prod_sum(long long u, long long v) {
        assert(0 <= min(u, v) and max(u, v) < V);
        assert(built);

        ll pu = post_order[u];
        ll pv = post_order[v];
        ll a = lca(u, v);
        ll pa = post_order[a];
        return seg_sum.prod(0, pu) + seg_sum.prod(0, pv) - 2 * seg_sum.prod(0, pa) + seg_sum.get(pre_order[a]);
    }

    T get_vertex(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        return weights[v];
    }

    T get_edge(long long i) {
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
