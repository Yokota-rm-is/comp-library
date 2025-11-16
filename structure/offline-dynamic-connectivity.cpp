#pragma once
#include "../base.cpp"

// 参考: https://trap.jp/post/2251/
// OfflineDynamicConnectivity
// 計算量: O((MlogQ + Q) * logN)
template <class S,
    auto op,
    auto inv>
struct UndoUnionFind {
    struct data {
        int u, v;
        S x;
        data(){}
        data(int a, int b, S c) : u(a), v(b), x(c) {}
    };
   
    vector<int> par, sz;
    vector<S> val;
    stack<data> his;
    int cc_size;

    UndoUnionFind(int n, S a = S()) : par(n), sz(n, 1), val(n, a), cc_size(n) {
        iota(par.begin(), par.end(), 0);
    }

    UndoUnionFind(int n, vector<S> v) : par(n), sz(n, 1), val(v), cc_size(n) {
        iota(par.begin(), par.end(), 0);
    }
  
    int leader(int u) {
        while (par[u] != u) {
            u = par[u];
        }
        return u;
    }
    
    bool same(int a, int b) {
        return leader(a) == leader(b);
    }
    
    bool merge(int a, int b) {
        a = leader(a), b = leader(b);
        if (sz[a] < sz[b]) swap(a, b);
        his.push(data(a, b, val[a]));

        if (a == b) {
            return false;
        }
        else {
            par[b] = a;
            sz[a] += sz[b];
            val[a] = op(val[a] , val[b]);
            cc_size--;
            return true;
        }
    }

    bool undo() {
        if (his.empty()) return false;
        data p = his.top();
        his.pop();
        if (p.u != p.v) {
            par[p.v] = p.v;
            sz[p.u] -= sz[p.v];
            val[p.u] = op(val[p.u], inv(val[p.v]));
            cc_size++;
        }
        return true;
    }

    void apply(int v, S f) {
        while (true) {
            val[v] = op(val[v], f);
            if (v == par[v]) break;
            v = par[v];
        }
    }

    S prod(int u) {
        return val[leader(u)];
    }

    int size(int u) {
        return sz[leader(u)];
    }

};

template<bool Multi, 
    typename S,
    auto op,
    auto inv>
struct OfflineDynamicConnectivity {
    using pii = pair<int, int>;
    using edge = array<int, 4>;

    int n, t, sz, qi, li;
    UndoUnionFind<S, op, inv> uf;
    vector<vector<pii>> data;
    vector<multiset<pii>> edges;
    vector<edge> lrs;
    vector<pii> queries;
    vector<tuple<ll, ll, S>> lazy;
    vector<S> res;

    OfflineDynamicConnectivity(int N) : n(N), t(0), sz(1), qi(0), li(0), uf(N), edges(N) {}
    OfflineDynamicConnectivity(int N, S a) : n(N), t(0), sz(1), qi(0), li(0), uf(N, a), edges(N) {}
    OfflineDynamicConnectivity(int N, vector<S> v) : n(N), t(0), sz(1), qi(0), li(0), uf(N, v), edges(N) {}

    void build() {
        rep(u, n) {
            for (auto [v, l] : edges[u]) {
                lrs.push_back(edge{l, t, int(u), v});
            }
        }
        t += 1;

        while (sz < t) sz <<= 1;
        data.resize(2 * sz);

        for (auto [l, r, u, v] : lrs) {
            l += sz;
            r += sz;
            while (l < r) {
                if (l & 1) data[l++].emplace_back(u, v);
                if (r & 1) data[--r].emplace_back(u, v);
                l >>= 1, r >>= 1;
            }
        }
    }

    void dfs(auto f, int v) {
        for (auto [a, b] : data[v]) uf.merge(a, b);
        if (v >= sz) {
            while (li < lazy.size() && get<0>(lazy[li]) == v - sz) uf.apply(get<1>(lazy[li]), get<2>(lazy[li])), li++;
            if (qi < queries.size() && queries[qi].first == v - sz) res.push_back(f(uf, queries[qi++].second));
        }
        else {
            dfs(f, v * 2);
            dfs(f, v * 2 + 1);
        }
        rep(i, data[v].size()) uf.undo();
    }
    
    vector<S> run(auto f) {
        dfs(f, 1);
        return res;
    }

    void link(int u, int v) {
        if (u > v) swap(u, v);
        if (Multi) edges[u].insert(pii(v, t));
        else {
            auto it = edges[u].lower_bound(pii(v, -1));
            if (it != edges[u].end() && (*it).first == v) return;
            edges[u].insert(pii(v, t));
        }
    }

    void cut(int u, int v) {
        if (u > v) swap(u, v);
        auto it = edges[u].lower_bound(pii(v, -1));
        if (it == edges[u].end()) return;
        auto [tar, l] = *it;
        if (tar != v) return;
        edges[u].erase(it);
        lrs.push_back(edge{l, t, u, v});
        
    }

    void query(int q) {
        queries.emplace_back(t++, q);
    }

    // f(UndoUnionFind<S, op, inv>& uf, int v) -> S
    void apply(int v, S f) {
        lazy.push_back({t, v, f});
    }
};