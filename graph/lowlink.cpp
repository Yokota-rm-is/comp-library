#pragma once
#include "../base.cpp"

struct LowLink {
    struct Edge {
        long long from, to, id;

        explicit Edge(long long u = -1, long long v = -1, long long i = -1) : from(u), to(v), id(i) {};

        bool operator < (const Edge& other) const {
            if (from == other.from) {
                return to < other.to;
            }
            else return from < other.from;
        }

        friend ostream& operator << (ostream& os, const Edge& edge) {
            return os << edge.to;
        }
    };

    long long V;
    bool built;
    vector<vector<Edge>> G;
    vector<bool> used;
    vector<long long> ord, low, dependency;

    long long edge_id;
    vector<Edge> edges;

    long long time, cc_size;

    LowLink(long long N) : V(N), built(false), G(V) {
        init();
    };
    
    void init() {
        time = 0;
        cc_size = 0;
        edge_id = 0;

        used.assign(V, false);
        ord.assign(V, -1);
        low.assign(V, -1);
        dependency.assign(V, 0);
    }
    
    void connect(long long from, long long to) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);
        assert(!built);

        edges.emplace_back(from, to, edge_id);

        G[from].emplace_back(from, to, edge_id);
        G[to].emplace_back(to, from, edge_id);

        edge_id++;
    }

    void operator() () {
        build();
    }

    void build() {
        assert(!built);

        rep(i, V) {
            if (used[i]) continue; 

            dfs(i, 0, Edge());
            cc_size++;
        }
        built = true;
    }

    int dfs(int now, int k, Edge edge) {
        used[now] = true;
        ord[now] = low[now] = k++;
        bool beet = false;
        long long par = edge.from;

        fore(e, G[now]) {
            ll to = e.to;
            if (to == par and !exchange(beet, true)) continue;

            if (!used[to]) {
                k = dfs(to, k, e);
                chmin(low[now], low[to]);
                dependency[now] += (ord[now] <= low[to]);
            } 
            else {
                chmin(low[now], ord[to]);
            }
        }

        return k;
    }

    // u -> vが橋かどうか
    // 橋: 取り除いたときにグラフが非連結になる(連結成分が1増える)辺
    bool is_bridge(long long u, long long v) {
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);
        assert(built);

        if (ord[u] > ord[v]) swap(u, v);

        return ord[u] < low[v];
    }

    // uが関節点かどうか
    // 関節点: 取り除いた後のグラフが非連結になる頂点
    // dfs後に使用
    bool is_articulation(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        return dependency[v] - (ord[v] == 0) > 0;
    }

    // 辺(u, v)を取り除いた後のグラフの連結成分数を返す
    long long count_cc_if_removed_edge(long long u, long long v) {
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);
        assert(built);

        if (ord[u] > ord[v]) swap(u, v);

        return cc_size + (ord[u] < low[v]);
    }

    // 頂点uを取り除いた後のグラフの連結成分数を返す
    long long count_cc_if_removed_vertex(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        return cc_size + dependency[v] - (ord[v] == 0);
    }
};

// 二重頂点連結成分分解
// 二重頂点連結成分分解: 頂点を1本取り除いても連結成分数が変わらないような連結成分に分解すること
struct BiConnectedComponents {
    LowLink lowlink;
    vector<bool> used;
    stack<LowLink::Edge> st;
    vector<vector<long long>> bcc;

    BiConnectedComponents(long long N) : lowlink(N) {
        used.assign(N, false);
    }

    void connect(long long u, long long v) {
        lowlink.connect(u, v);
    }

    void build() {
        lowlink.build();

        rep(i, lowlink.V) {
            if (used[i]) continue; 

            dfs(i, -1);
        }
    }

    void dfs(long long now, long long par) {
        used[now] = true;
        bool beet = false;

        fore(e, lowlink.G[now]) {
            long long to = e.to;
            if (to == par and !exchange(beet, true)) continue;
            
            if (!used[to] or lowlink.ord[to] < lowlink.ord[now]) {
                st.emplace(e);
            }

            if (!used[to]) {
                dfs(to, now);

                if (lowlink.low[to] >= lowlink.ord[now]) {
                    bcc.emplace_back();
                    while (true) {
                        auto edge = st.top();
                        st.pop();
                        bcc.back().emplace_back(edge.from);
                        if (edge.to == to) break;
                    }
                }
            }
        }
    }
};

// 二重辺連結成分分解
// 二重辺連結成分分解: 辺を1本取り除いても連結成分数が変わらないような連結成分に分解すること
// 二重辺連結成分分解により縮約された頂点と辺(橋)からなるグラフは森となる
struct TwoEdgeConnectedComponents {
    LowLink lowlink;
    vector<long long> comp;
    vector<vector<long long>> tree, group;

    TwoEdgeConnectedComponents(long long N) : lowlink(N) {
        comp.assign(N, -1);
    }

    void connect(long long u, long long v) {
        lowlink.connect(u, v);
    }

    void build() {
        lowlink.build();

        long long k = 0;
        rep(i, lowlink.V) {
            if (comp[i] != -1) continue;

            k = dfs(i, -1, k);
        }

        group.resize(k);
        rep(i, lowlink.V) {
            group[comp[i]].emplace_back(i);
        }

        tree.resize(k);
        rep(now, lowlink.V) {
            for (auto e : lowlink.G[now]) {
                long long to = e.to;
                if (comp[now] == comp[to]) continue;
                tree[comp[now]].emplace_back(comp[to]);
            }
        }
    }

    long long dfs(long long now, long long par, long long k) {
        if (par >= 0 and lowlink.ord[par] >= lowlink.low[now]) comp[now] = comp[par];
        else comp[now] = k++;

        fore(e, lowlink.G[now]) {
            long long to = e.to;
            if (comp[to] != -1) continue;
            
            k = dfs(to, now, k);
        }
        return k;
    }
};