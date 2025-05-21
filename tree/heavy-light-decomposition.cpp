#pragma once
#include "../base.cpp"

// 参考: https://nyaannyaan.github.io/library/tree/heavy-light-decomposition.hpp.html
struct HeavyLightDecomposition {
    vector<vector<pair<long long, long long>>> G;
    vector<pair<long long, long long>> edges;
    long long V, root, id;
    vector<long long> size, depth, down, up, nxt, par;

    bool built;
    
    HeavyLightDecomposition(long long N): V(N) {
        G.resize(N);
        size.resize(N, 0);
        depth.resize(N, 0);
        down.resize(N * 2 - 1, -1);
        up.resize(N * 2 - 1, -1);

        built = false;
    }

    void connect(long long u, long long v) {
        assert(!built);
        long long edge_id = edges.size() + V;
        G[u].emplace_back(v, edge_id);
        G[v].emplace_back(u, edge_id);
        
        edges.emplace_back(u, v);
    }

    void build(long long r = 0) {
        assert(!built);
        built = true;

        root = r;
        id = 0;

        nxt.resize(V * 2 - 1, root);
        par.resize(V * 2 - 1, root);

        dfs_sz(root);
        dfs_hld(root);
    }

    long long get_vertex_index(long long vi) const { 
        assert(built);
        return down[vi]; 
    }

    long long get_edge_index(long long ei) const { 
        assert(built);
        return down[V + ei]; 
    }

    template <typename F>
    void path_query(long long u, long long v, const F& f) {
        assert(built);

        long long l = lca(u, v);
        for (auto&& [a, b] : ascend(u, l)) {
            long long s = a + 1, t = b;
            s > t ? f(t, s) : f(s, t);
        }
        f(down[l], down[l] + 1);
        for (auto&& [a, b] : descend(l, v)) {
            long long s = a, t = b + 1;
            s > t ? f(t, s) : f(s, t);
        }
    }

    template <typename F>
    void path_noncommutative_query(long long u, long long v, const F& f) {
        assert(built);

        long long l = lca(u, v);
        for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);
        f(down[l], down[l] + 1);
        for (auto&& [a, b] : descend(l, v)) f(a, b + 1);
    }

    template <typename F>
    void subtree_query(int u, const F& f) {
        assert(built);

        f(down[u], up[u]);
    }

    long long lca(long long u, long long v) {
        assert(built);

        while (nxt[u] != nxt[v]) {
            if (down[u] < down[v]) swap(u, v);
            u = par[nxt[u]];
        }
        return depth[u] < depth[v] ? u : v;
    }

    long long dist(long long u, long long v) { 
        assert(built);
        return depth[u] + depth[v] - depth[lca(u, v)] * 2; 
    }

private:
    void dfs_sz(long long cur) {
        size[cur] = 1;

        fore(e, G[cur]) {
            auto [dst, edge_id] = e;

            if (edge_id == par[cur]) continue;

            depth[dst] = depth[cur] + 1;

            par[edge_id] = cur;
            par[dst] = edge_id;

            dfs_sz(dst);
            
            size[cur] += size[dst];
            if (size[dst] > size[G[cur][0].first]) {
                swap(e, G[cur][0]);
            }
        }
    }

    void dfs_hld(long long cur) {
        down[cur] = id++;

        fore(e, G[cur]) {
            auto [dst, edge_id] = e;

            if (edge_id == par[cur]) continue;

            down[edge_id] = id++;
            nxt[dst] = (dst == G[cur][0].first) ? nxt[cur] : edge_id;
            dfs_hld(dst);
            up[edge_id] = id;
        }

        up[cur] = id;
    }

    // [u, v)
    vector<pair<long long, long long>> ascend(long long u, long long v) const {
        vector<pair<long long, long long>> res;

        while (nxt[u] != nxt[v]) {
            res.emplace_back(down[u], down[nxt[u]]);
            u = par[nxt[u]];
        }
        
        if (u != v) res.emplace_back(down[u], down[v] + 1);
        return res;
    }

    // (u, v]
    vector<pair<long long, long long>> descend(long long u, long long v) const {
        if (u == v) return {};
        if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};
        auto res = descend(u, par[nxt[v]]);
        res.emplace_back(down[nxt[v]], down[v]);
        return res;
    }
};