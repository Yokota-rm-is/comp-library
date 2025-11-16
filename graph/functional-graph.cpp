#pragma once
#include "../base.cpp"

// 参考: https://perogram.hateblo.jp/entry/namori
struct NamoriGraph {
    vector<long long> ids;
    unordered_set<long long> cycle_ids, leaves;
    unordered_map<long long, long long> to, depth;
    unordered_map<long long, vector<long long>> prev;
    vector<long long> topo;
    bool built = false;

    void connect(long long u, long long v) {
        assert(!built);
        to[u] = v;
        prev[v].push_back(u);
    }

    void build() {
        assert(!built);
        built = true;

        fore(p, to) {
            ids.push_back(p.first);
            if (prev[p.first].size() == 0) leaves.insert(p.first);
        }

        vector<vector<long long>> table(ids.size());

        unordered_set<long long> seen;
        stack<long long> st;
        long long now = ids.front();
        seen.insert(now);
        st.push(now);

        while (true) {
            now = to[now];
            st.push(now);

            if (seen.contains(now)) break;
            seen.insert(now);
        }

        while (!st.empty()) {
            now = st.top();
            st.pop();

            if (cycle_ids.contains(now)) break;
            cycle_ids.insert(now);
            depth[now] = 0;
            table[0].push_back(now);
        }

        function<long long(long long)> dfs = [&](long long x) {
            if (depth.contains(x)) return depth[x];
            depth[x] = dfs(to[x]) + 1;
            table[depth[x]].push_back(x);
            return depth[x];
        };

        fore(x, ids) {
            if (depth.contains(x)) continue;
            dfs(x);
        }

        repd(i, table.size()) {
            fore(x, table[i]) topo.push_back(x);
        }
    }

    bool is_cycle(long long x) {
        assert(built);
        return cycle_ids.contains(x);
    }

    bool is_leaf(long long x) {
        assert(built);
        return prev[x].size() == 0;
    }

    long long get_depth(long long x) {
        assert(built);
        return depth[x];
    }

    long long get_next(long long x) {
        assert(built);
        return to[x];
    }

    vector<long long> get_prev(long long x) {
        assert(built);
        return prev[x];
    }

    vector<long long> get_prev_cycle() {
        assert(built);
        vector<long long> ret;
        fore(x, cycle_ids) {
            fore(y, prev[x]) {
                if (cycle_ids.contains(y)) continue;
                ret.push_back(y);
            }
        }

        return ret;
    }

    long long get_cycle_length() {
        assert(built);
        return cycle_ids.size();
    }

    unordered_set<long long> get_cycle_ids() {
        assert(built);
        return cycle_ids;
    }

    unordered_set<long long> get_leaves() {
        assert(built);
        return leaves;
    }

    vector<long long> get_topo_from_leaves() {
        assert(built);
        return topo;
    }

    vector<long long> get_topo_from_cycle() {
        assert(built);
        vector<long long> ret = topo;
        reverse(ret);
        return ret;
    }
};

struct FunctionalGraph {
    struct UnionFind {
        long long n;
        vector<long long> par;

        UnionFind(long long n) : n(n), par(n) {
            rep(i, n) {
                par[i] = -1;
            }
        }

        long long find(long long x) {
            if (par[x] < 0) return x;
            return par[x] = find(par[x]);
        }

        void unite(long long u, long long v) {
            u = find(u);
            v = find(v);

            if (u == v) return;
            if (-par[u] < -par[v]) swap(u, v);

            par[u] += par[v];
            par[v] = u;
        }

        unordered_map<long long, unordered_set<long long>> cc() {
            unordered_map<ll, unordered_set<long long>> ret;
            rep(i, n) {
                ret[find(i)].insert(i);
            }

            return ret;
        }
    };

    long long N;
    vector<long long> to;
    vector<NamoriGraph> namoris;
    UnionFind uf;

    FunctionalGraph(long long N) : N(N), to(N, -1), uf(N) {}

    void connect(long long u, long long v) {
        to[u] = v;
        uf.unite(u, v);
    }

    void build() {
        fore(p, uf.cc()) {
            auto [par, cc] = p;

            NamoriGraph namori;

            fore(i, cc) {
                namori.connect(i, to[i]);
            }

            namori.build();
            namoris.push_back(namori);
        }
    }
};