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
    bool directed_;
    vector<vector<Edge>> G;
    vector<long long> ord, low;
    vector<vector<Edge>> back_edges, son;
    vector<long long> topo;

    long long edge_id;
    vector<Edge> edges;

    long long time;
    bool has_cycle;
    vector<long long> descendants;

    vector<vector<long long>> bcc, bcc_edges;

    LowLink(long long N, bool directed) : V(N), directed_(directed), G(V) {
        init();
    };
    
    void init() {
        time = 0;
        has_cycle = false;
        edge_id = 0;

        ord.assign(V, -1);
        low.assign(V, -1);
        back_edges.assign(V, vector<Edge>());
        son.assign(V, vector<Edge>());
        descendants.assign(V, 0);

        bcc.assign(V, vector<long long>());
        rep(i, V) bcc[i].emplace_back(i);
    }
    
    void connect(long long from, long long to) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        edges.emplace_back(from, to, edge_id);

        if (directed_) {
            G[from].emplace_back(from, to, edge_id);
        }
        else {
            G[from].emplace_back(from, to, edge_id);
            G[to].emplace_back(to, from, edge_id);
        }

        edge_id++;
    }

    void operator() () {
        dfs(0);
    }

    void dfs(long long start) {
        assert(0 <= start and start < V);

        stack<pair<long long, Edge>> st;
        st.emplace(start, Edge());

        while (!st.empty()) {
            auto [now, edge] = st.top(); 
            st.pop();
            long long par = edge.from;

            if (ord[now] != -1) {
                if (ord[par] < ord[now]) continue;
                chmin(low[par], ord[now]);

                back_edges[par].emplace_back(edge);
                continue;
            }

            if (par != -1) {
                son[par].emplace_back(edge);
            }
            topo.push_back(now);

            ord[now] = low[now] = time++;

            fore(next_edge, G[now]) {
                long long next = next_edge.to;

                if (next == par) continue;

                st.emplace(next, next_edge);
            }
        }

        repd(i, 1, topo.size()) {
            long long now = topo[i];

            for (auto next_edge : son[now]) {
                long long next = next_edge.to;
                chmin(low[now], low[next]);
            }
        }
    }

    // u -> vが橋かどうか
    // 橋: 取り除いたときにグラフが非連結になる辺
    // dfs後に使用
    bool is_bridge(long long u, long long v) {
        if (ord[u] > ord[v]) swap(u, v);

        return ord[u] < low[v];
    }

    // uが関節点かどうか
    // 関節点: 取り除いた後のグラフが非連結になる頂点
    // dfs後に使用
    bool is_articulation(long long u) {
        if (ord[u] == 0) {
            return son[u].size() >= 2;
        }
        else {
            fore(edge, son[u]) {
                long long v = edge.to;
                if (ord[u] <= low[v]) return true;
            }

            return false;
        }
    }

    long long solve_bcc() {
        stack<pair<long long, Edge>> sub_roots;
        sub_roots.emplace(0, Edge());

        while (!sub_roots.empty()) {
            stack<pair<long long, Edge>> st;
            st.emplace(sub_roots.top());
            sub_roots.pop();

            bcc.push_back({});
            bcc_edges.push_back({});

            if (st.top().second.from != -1) {
                bcc.back().emplace_back(st.top().second.from);
            }

            while (!st.empty()) {
                auto [now, edge] = st.top();
                st.pop();

                long long par = edge.from;
                if (par != -1) {
                    bcc_edges.back().emplace_back(edge.id);
                }
                bcc.back().emplace_back(now);

                if (now == 0) {
                    if (is_articulation(now)) {
                        fore(next_edge, son[now]) {
                            long long next = next_edge.to;
                            sub_roots.emplace(next, next_edge);
                        }
                        bcc.pop_back();
                        bcc_edges.pop_back();
                    }
                    else {
                        fore(next_edge, son[now]) {
                            long long next = next_edge.to;
                            st.emplace(next, next_edge);
                        }
                    }
                }
                else {
                    fore(next_edge, son[now]) {
                        long long next = next_edge.to;
                        if (is_articulation(next)) {
                            sub_roots.emplace(next, next_edge);
                        }
                        else {
                            st.emplace(next, next_edge);
                        }
                    }
                }

                if (now == 0 and son[now].size() <= 1) {
                    fore(next_edge, back_edges[now]) {
                        long long next = next_edge.from;
                        bcc.back().emplace_back(next);
                    }
                }
            }
        }

        return bcc.size();
    }
};