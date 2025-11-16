#pragma once
#include "../base.cpp"

/**
 * @brief Flow(最大・最小流)
*/

template<typename Cost, typename Cap>
struct MinCostFlow {
    struct Edge {
        long long from;
        long long to;
        Cost cost;
        Cap cap, flow;
        long long idx;
        long long rev;
        
        explicit Edge(long long u = -1, long long v = -1, Cost cost = 0, Cap cap = 0, long long i = 0, long long rev = 0) : from(u), to(v), cost(cost), cap(cap), flow(0), idx(i), rev(rev) {};

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

    long long edge_index = 0;
    vector<Edge> edges;

    // maxflow用
    vector<long long> level;

    // mincostflow用
    vector<Cost> dual;
    vector<long long> prevv, preve;
    Cap cur_flow;
    Cap cur_cost, pre_cost;
    vector<pair<pair<Cap, Cap>, pair<Cost, Cost>>> min_cost_slope;

    MinCostFlow(long long N) : V(N), G(V) {
        init();
    };
    
    void init() {
        cur_flow = 0;
        cur_cost = 0;
        pre_cost = -1;

        level.assign(V, -1);
        dual.assign(V, 0);
        prevv.assign(V, -1);
        preve.assign(V, -1);
    }

    void connect(long long from, long long to, Cap cap) {
        connect(from, to, 0, cap, 0);
    }

    void connect(long long from, long long to, Cap upper_limit, Cost cost) {
        connect(from, to, 0, upper_limit, cost);
    }

    void connect(long long from, long long to, Cap lower_limit, Cap upper_limit, Cost cost) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        long long from_id = G[from].size();
        long long to_id = G[to].size();

        edges.emplace_back(from, to, cost, upper_limit, edge_index);

        G[from].emplace_back(from, to, cost, upper_limit, edge_index, to_id);
        G[to].emplace_back(to, from, -cost, -lower_limit, edge_index, from_id);

        ++edge_index;
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

    Cap max_flow(long long s, long long t) {
        return max_flow(s, t, numeric_limits<Cap>::max());
    }

    Cap max_flow(long long s, long long t, Cap flow_limit) {
        assert(0 <= s && s < V);
        assert(0 <= t && t < V);
        assert(s != t);

        Cap flow = 0;
        while (flow < flow_limit) {
            fill(level.begin(), level.end(), -1);
            bfs(s, t);

            if (level[s] == -1) break;

            Cap f = dfs(t, s, t, flow_limit - flow);

            if (!f) break;
            flow += f;
        }
        return flow;
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
    // ret[i] = trueならば頂点iはsから到達可能
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

    pair<Cap, Cost> min_cost_flow(long long s, long long t) {
        return min_cost_flow(s, t, numeric_limits<Cap>::max());
    }
    
    pair<Cap, Cost> min_cost_flow(long long s, long long t, Cap flow_limit) {
        Cap f = slope(s, t, flow_limit).back().first.second;
        auto [a, b] = slope(s, t, flow_limit).back().second;
        Cost c = a * f + b;
        return {f, c};
    }

    vector<pair<pair<Cap, Cap>, pair<Cost, Cost>>> slope(long long s, long long t) {
        return slope(s, t, numeric_limits<Cap>::max());
    }

    vector<pair<pair<Cap, Cap>, pair<Cost, Cost>>> slope(long long s, long long t, Cap flow_limit) {
        assert(0 <= s && s < V);
        assert(0 <= t && t < V);
        assert(s != t);
        
        // primal-dual
        while (cur_flow < flow_limit) {
            if (!dual_step(s, t)) break;
            primal_step(s, t, flow_limit);
        }
        return min_cost_slope;
    }

    bool dual_step(long long s, long long t) {
        priority_queue<pair<Cost, long long>, vector<pair<Cost, long long>>, greater<>> que;
        que.emplace(0, s);

        vector<Cost> costs(V, inf64);
        costs[s] = 0;

        while (!que.empty()) {
            auto [cost, now] = que.top();
            que.pop();

            if (costs[now] < cost) continue;

            rep(i, G[now].size()) {
                const Edge &e = G[now][i];
                const long long next = e.to;
                Cost new_cost = e.cost + dual[now] - dual[next];

                if (e.cap > 0 and costs[next] > costs[now] + new_cost) {
                    costs[next] = costs[now] + new_cost;
                    prevv[next] = now;
                    preve[next] = i;
                    que.emplace(costs[next], next);
                }
            }
        }
        
        if (costs[t] == inf64) return false;
        
        rep(v, G.size()) {
            if (costs[t] == inf64) continue;
            dual[v] -= costs[t] - costs[v];
        }
        return true;
    }

    void primal_step(long long s, long long t, Cap flow_limit) {
        Cap flow = flow_limit - cur_flow;
        Cost cost = -dual[s];
        for (long long v = t; v != s; v = prevv[v]) {
            flow = min(flow, G[prevv[v]][preve[v]].cap);
        }

        for (long long v = t; v != s; v = prevv[v]) {
            auto &e = G[prevv[v]][preve[v]];
            auto &re = G[e.to][e.rev];
            e.cap -= flow, e.flow += flow;
            re.cap += flow, re.flow -= flow;
        }

        if (pre_cost == cost) {
            min_cost_slope.back().first.second += flow;
        }
        else {
            min_cost_slope.emplace_back(pair<Cap, Cap>(cur_flow, cur_flow + flow), pair<Cost, Cost>(cost, cur_cost - cur_flow * cost));
        }

        cur_flow += flow;
        cur_cost += flow * cost;
        pre_cost = cost;
    }
};