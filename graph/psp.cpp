#pragma once
#include "../base.cpp"
#include <cassert>

/**
 * @brief PSP(Project Selection Problem)
*/

template<typename Cap>
struct PSP {
    struct Edge {
        long long from;
        long long to;
        Cap cap, flow;
        long long idx;
        long long rev;
        
        Edge(long long u = -1, long long v = -1, Cap cap = 0, long long i = 0, long long rev = 0) : from(u), to(v), cap(cap), flow(0), idx(i), rev(rev) {};

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
    vector<vector<Edge>> G;
    long long coeff = 1;

    long long start, goal;
    Cap offset;

    long long edge_index = 0;
    vector<Edge> edges;

    // maxflow用
    vector<long long> level;

    PSP(long long N) : V(N + 2), G(V), start(N), goal(N + 1), offset(0) {
        init();
    };
    
    void init() {}

    void connect(long long from, long long to, Cap cap) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        if (from >= (long long)G.size()) G.resize(from + 1);
        if (to >= (long long)G.size()) G.resize(to + 1);

        long long from_id = G[from].size();
        long long to_id = G[to].size();

        edges.emplace_back(from, to, cap, edge_index);

        G[from].emplace_back(from, to, cap, edge_index, to_id);
        G[to].emplace_back(to, from, 0, edge_index, from_id);

        ++edge_index;
    }

    void set_cost_if_false(long long i, Cap cost) {
        if (cost >= 0) connect(start, i, cost);
        else {
            cost *= -1;
            offset -= cost;
            connect(i, goal, cost);
        }
    }

    void set_cost_if_true(long long i, Cap cost) {
        set_gain_if_true(i, -cost);
    }

    void set_gain_if_false(long long i, Cap gain) {
        set_cost_if_false(i, -gain);
    }

    void set_gain_if_true(long long i, Cap gain) {
        if (gain >= 0) {
            offset -= gain;
            connect(start, i, gain);
        }
        else connect(i, goal, -gain);
    }

    void set_cost_if_true_false(long long t, long long f, Cap cost) {
        assert(cost >= 0);
        connect(t, f, cost);
    }

    void set_inf_cost_if_true_false(long long t, long long f) {
        connect(t, f, inf64);
    }

    void set_cost_if_different(long long i, long long j, Cap cost) {
        assert(cost >= 0);
        connect(i, j, cost);
        connect(j, i, cost);
    }

    void set_inf_cost_if_different(long long i, long long j) {
        connect(i, j, inf64);
        connect(j, i, inf64);
    }

    void set_gain_if_both_false(long long i, long long j, Cap gain) {
        assert(gain >= 0);

        offset -= gain;
        long long k = V;
        ++V;
        connect(i, k, inf64);
        connect(j, k, inf64);
        connect(k, goal, gain);
    }

    void set_gain_if_both_true(long long i, long long j, Cap gain) {
        assert(gain >= 0);

        offset -= gain;
        long long k = V;
        ++V;
        connect(start, k, gain);
        connect(k, i, inf64);
        connect(k, j, inf64);
    }

    void set_gain_if_same(long long i, long long j, Cap gain) {
        set_gain_if_both_false(i, j, gain);
        set_gain_if_both_true(i, j, gain);
    }

    void set_gain_if_all_false(const set<long long>& st, Cap gain) {
        assert(gain >= 0);

        offset -= gain;
        long long k = V;
        ++V;
        fore(i, st) connect(i, k, inf64);
        connect(k, goal, gain);
    }

    void set_gain_if_all_true(const set<long long>& st, Cap gain) {
        assert(gain >= 0);

        offset -= gain;
        long long k = V;
        ++V;
        connect(start, k, gain);
        fore(i, st) connect(k, i, inf64);
    }

    void set_gain_if_all_false(const vector<long long>& v, Cap gain) {
        assert(gain >= 0);

        offset -= gain;
        long long k = V;
        ++V;
        fore(i, v) connect(i, k, inf64);
        connect(k, goal, gain);
    }

    void set_gain_if_all_true(const vector<long long>& v, Cap gain) {
        assert(gain >= 0);

        offset -= gain;
        long long k = V;
        ++V;
        connect(start, k, gain);
        fore(i, v) connect(k, i, inf64);
    }

    Cap dfs(long long v, long long s, long long t, Cap flow) {
        if (v == s) return flow;

        Cap res = 0;
        long long level_v = level[v];
        vector<long long> iter(V, 0);

        for (long long& i = iter[v]; i < (long long)(G[v].size()); ++i) {
            Edge& e = G[v][i];
            long long next = e.to;

            if (level_v <= level[next] || G[next][e.rev].cap == 0) continue;

            Cap d = dfs(next, s, t, min(flow - res, G[next][e.rev].cap));

            if (d <= 0) continue;

            G[v][i].cap += d;
            G[next][e.rev].cap -= d;
            res += d;

            if (res == flow) return res;
        }

        level[v] = V;
        return res;
    }

    void bfs(long long s, long long t) {
        assert(0 <= s and s < V);
        assert(0 <= t and t < V);

        queue<long long> que;

        // 初期条件 (頂点 start を初期ノードとする)
        level[s] = 0;
        que.push(s); // noq を橙色頂点にする

        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            long long now = que.front(); // キューから先頭頂点を取り出す
            que.pop();

            // v から辿れる頂点をすべて調べる
            fore(edge, G[now]) {
                long long next = edge.to;
                if (edge.cap == 0 or level[next] >= 0) continue; // すでに発見済みの頂点は探索しない

                // 新たな白色頂点 nv について距離情報を更新してキューに追加する
                level[next] = level[now] + 1;
                
                if (next == t) return;
                que.push(next);
            }
        }
    }

    Cap operator() () {
        return solve();
    }

    Cap solve() {
        return max_flow(start, goal, numeric_limits<Cap>::max());
    }

    Cap max_flow(long long s, long long t, Cap flow_limit) {
        assert(0 <= s && s < V);
        assert(0 <= t && t < V);
        assert(s != t);

        Cap flow = 0;
        while (flow < flow_limit) {
            level.assign(V, -1);
            bfs(s, t);

            if (level[s] == -1) break;

            Cap f = dfs(t, s, t, flow_limit - flow);

            if (!f) break;
            flow += f;
        }

        return flow + offset;
    }

    void change_edge(long long i, Cap new_cap, Cap new_flow) {
        long long m = edges.size();

        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);

        Edge edge = edges[i];

        auto& _e = G[edge.from][edge.rev];
        auto& _re = G[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    // max_flow(s, t)後に使用することでs,t間の最小カットを返す
    vector<bool> min_cut(long long s) {
        vector<bool> visited(V);

        queue<long long> que;
        que.push(s);
        
        while (!que.empty()) {
            long long p = que.front();
            que.pop();
            visited[p] = true;

            fore(e, G[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
};
