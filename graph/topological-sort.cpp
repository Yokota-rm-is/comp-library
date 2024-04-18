#pragma once
#include "../base.cpp"

template<class Weight = long long, class Cap = long long>
struct Edge {
    long long from;
    long long to;
    Weight weight;
    Cap cap;
    long long id;
    long long rev;
    Cap flow;
    
    explicit Edge(long long u = -1, long long v = -1, Weight w = 1, long long i = -1, Cap c = 0, long long r = -1) : from(u), to(v), weight(w), cap(c), id(i), rev(r), flow(0) {};

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

template <typename T = long long>
struct TopologicalSort {
    long long V;
    vector<vector<Edge<T>>> G, rG;
    vector<bool> seen;
    vector<long long> prev;
    vector<T> maximum_cost;

    TopologicalSort(long long N) : V(N), G(V), rG(V) {
        init();
    };
    
    void init() {
        seen.assign(V, false);
        prev.assign(V, -1);
        maximum_cost.assign(V, -1);
    }
    
    void connect(long long from, long long to, T weight = 1) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        G[from].emplace_back(from, to, weight);
        rG[to].emplace_back(to, from, weight);
    }

    vector<long long> operator() () {
        return topological_sort();
    }

    vector<long long> topological_sort() {
        std::vector<long long> indegrees(V);

        rep(i, V) {
            indegrees[i] = rG[i].size();
        }

        priority_queue<ll, vector<ll>, greater<>> que;

        rep(i, V) {
            if (indegrees[i] == 0) {
                que.push(i);
                maximum_cost[i] = 0;
            }
        }

        vector<long long> ret;

        while (!que.empty()) {
            long long now = que.top(); 
            que.pop();

            ret.push_back(now);

            fore(edge, G[now]) {
                long long next = edge.to;

                if (--indegrees[next] == 0) {
                    que.push(next);
                }

                if (chmax(maximum_cost[next], maximum_cost[now] + edge.weight)) {
                    prev[next] = now;
                }
            }
        }

        if ((long long)ret.size() != V) return {};

        return ret;
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

    vector<long long> get_longest_path() {
        vector<long long> ret;

        ll goal = distance(maximum_cost.begin(), max_element(maximum_cost.begin(), maximum_cost.end()));

        return path_to(goal);
    }
};