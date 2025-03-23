#pragma once
#include "../base.cpp"

/**
 * @brief ダイクストラ法
 * @docs docs/graph/dijkstra.md
*/
template<class T = long long>
struct Dijkstra {
    struct Edge {
        long long from;
        long long to;
        T weight;
        
        explicit Edge(long long u = -1, long long v = -1, T w = 1) : from(u), to(v), weight(w) {};

        bool operator < (const Edge& other) const {
            if (from == other.from) {
                if (to == other.to) return weight < other.weight;
                else return to < other.to;
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
    vector<bool> done;
    vector<long long> prev;
    vector<T> cost;
    
    Dijkstra(long long N, bool directed) : V(N), directed_(directed), G(V) {
        init();
    };
    
    void init() {
        done.assign(V, false);
        prev.assign(V, -1);
        cost.assign(V, inf64);
    }
    
    void connect(long long from, long long to, T weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        if (directed_) {
            G[from].emplace_back(from, to, weight);
        }
        else {
            G[from].emplace_back(from, to, weight);
            G[to].emplace_back(to, from, weight);
        }
    }

    void operator() (vector<long long> starts) {
        solve(starts);
    }

    void operator() (long long start) {
        solve(start);
    }

    void solve(long long start) {
        solve(vector<long long>{start});
    }

    void solve(vector<long long> starts) {
        fore(start, starts) {
            assert(0 <= start and start < V);
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> que;

        fore(start, starts) {
            cost[start] = 0;
            que.emplace(cost[start], start);
        }
        
        while (!que.empty()) {
            long long now = que.top().second;
            que.pop();

            if (done[now]) continue;
            done[now] = true;

            fore(edge, G[now]) {
                long long next = edge.to;
                if (chmin(cost[next], cost[now] + edge.weight)) {
                    prev[next] = now;
                    que.emplace(cost[next], next);
                }
            }
        }
    }

    bool can_reach(long long to) {
        assert(0 <= to and to < V);

        return done[to];
    }

    vector<long long> get_path(long long to) {
        assert(0 <= to and to < V);
        if (!can_reach(to)) return {};

        vector<long long> p;
        p.push_back(to);

        while (prev[p.back()] != -1) {
            p.push_back(prev[p.back()]);
        }

        reverse(p.begin(), p.end());

        return p;
    }
};