#pragma once
#include "../base.cpp"

struct BFS01 {
    struct Edge {
        long long from;
        long long to;
        long long weight;
        
        explicit Edge(long long u = -1, long long v = -1, long long w = -1) : from(u), to(v), weight(w) {};

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
    vector<bool> done;
    vector<long long> prev;
    vector<long long> cost;
    long long group;

    BFS01(long long N, bool directed) : V(N), directed_(directed), G(V){
        init();
    };
    
    void init() {
        group = 0;
        done.assign(V, false);
        prev.assign(V, -1);
        cost.assign(V, inf64);
    }
    
    void connect(long long from, long long to, long long weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);
        assert(weight == 0 or weight == 1);

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

    void solve_all() {
        rep(i, V) {
            if (done[i]) continue;
            solve(i);
            ++group;
        }
    }

    void solve(long long start) {
        solve(vector<long long>{start});
    }

    void solve(vector<long long> starts) {
        fore(start, starts) {
            assert(0 <= start and start < V);
        }

        deque<long long> que;

        fore(start, starts) {
            cost[start] = 0;
            que.push_back(start);
        }

        while (!que.empty()) {
            long long now = que.front();
            que.pop_front();

            if (done[now]) continue;
            done[now] = true;

            fore(edge, G[now]) {
                long long next = edge.to;
                if (done[next]) continue;

                if (chmin(cost[next], cost[now] + edge.weight)) {
                    if (edge.weight == 0) que.push_front(next);
                    else que.push_back(next);

                    prev[next] = now;
                }
            }
        }
    }

    long long count_cc() {
        return group;
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