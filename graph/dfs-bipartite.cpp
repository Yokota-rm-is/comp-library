#pragma once
#include "../base.cpp"

struct DFS {
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

    vector<long long> colors;
    bool is_bipartite;
    vector<vector<vector<ll>>> cc;

    DFS(long long N, bool directed) : V(N), directed_(directed), G(V) {
        init();
    };
    
    void init() {
        colors.assign(V, -1);
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
            if (colors[i] != -1) continue;

            cc.push_back(vector<vector<ll>>(2));
            cc.back()[0].push_back(i);
            colors[i] = (cc.size() - 1) * 2;

            stack<long long> st;
            st.push(i);

            while (!st.empty()) {
                ll now = st.top();
                st.pop();

                ll color = colors[now] % 2;

                fore(edge, G[now]) {
                    long long next = edge.to;
                    long long next_color = color ^ edge.different;

                    if (colors[next] != -1) {
                        if (colors[next] != colors[i] + next_color) return is_bipartite = false;
                        continue;
                    }

                    colors[next] = colors[i] + next_color;
                    cc.back()[next_color].push_back(next);

                    st.push(next);
                }
            }
        }

        return is_bipartite = true;
    }
};