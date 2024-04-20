#pragma once
#include "../base.cpp"

template<class T = long long>
struct BellmanFord {
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
    vector<long long> prev;
    vector<T> cost;
    vector<Edge> edges;

    BellmanFord(long long N, bool directed) : V(N), directed_(directed) {
        init();
    };
    
    void init() {
        prev.assign(V, -1);
        cost.assign(V, inf64);
    }
    
    void connect(long long from, long long to, T weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        edges.emplace_back(from, to, weight);
        if (!directed_) edges.emplace_back(to, from, weight);
    }

    void operator() (long long start) {
        bellman_ford(start);
    }

    void bellman_ford(long long start) {
        assert(0 <= start and start < V);

        bool changed = false;
        cost[start] = 0;

        rep(i, V) {
            changed = false;

            fore(e, edges) {
                if (cost[e.from] == inf64) continue;

                T c = cost[e.from] + e.weight;
                if (chmin(cost[e.to], c)) {
                    prev[e.to] = e.from;
                    changed = true;
                }
            }

            if (!changed) break;
        }

        if (changed) {
            rep(i, V) {
                fore(e, edges) {
                    if (cost[e.from] == inf64) continue;

                    T c = cost[e.from] + e.weight;
                    if (c < cost[e.to]) {
                        cost[e.to] = -inf64;
                    }
                }
            }
        }
    }

    bool has_negative_cycle() {
        rep(i, V) {
            if (cost[i] == -inf64) return true;
        }
        return false;
    }

    vector<long long> path_to(long long to) {
        assert(0 <= to and to < V);

        vector<long long> p;
        p.push_back(to);

        while (prev[p.back()] != -1) {
            p.push_back(prev[p.back()]);
        }

        reverse(p.begin(), p.end());

        return p;
    }
};