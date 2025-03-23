#pragma once
#include "../base.cpp"

struct BFS {
    struct Edge {
        long long from;
        long long to;
        bool different;
        
        explicit Edge(long long u = -1, long long v = -1, bool d = true) : from(u), to(v), different(d) {};

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

    vector<pair<long long, long long>> colors;
    bool is_bipartite;
    vector<vector<vector<ll>>> cc;

    BFS(long long N, bool directed) : V(N), directed_(directed), G(V) {
        init();
    };
    
    void init() {
        colors.assign(V, {-1, -1});
    }
    
    void connect(long long from, long long to, bool different_color = true) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        if (directed_) {
            G[from].emplace_back(from, to, different_color);
        }
        else {
            G[from].emplace_back(from, to, different_color);
            G[to].emplace_back(to, from, different_color);
        }
    }

    bool operator() () {
        return solve();
    }

    bool solve() {
        rep(i, V) {
            if (colors[i].first != -1) continue;

            cc.push_back(vector<vector<ll>>(2));
            cc.back()[0].push_back(i);
            colors[i] = {0, cc.size() - 1};

            queue<long long> que;
            que.push(i);

            while (!que.empty()) {
                ll now = que.front();
                que.pop();

                ll color = colors[now].first;

                fore(edge, G[now]) {
                    long long next = edge.to;
                    long long next_color = color ^ edge.different;

                    if (colors[next].first != -1) {
                        if (colors[next].first != colors[i].first + next_color) return is_bipartite = false;
                        continue;
                    }

                    colors[next] = {colors[i].first + next_color, colors[i].second};
                    cc.back()[next_color].push_back(next);

                    que.push(next);
                }
            }
        }

        return is_bipartite = true;
    }
};