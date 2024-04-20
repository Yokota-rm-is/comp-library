#pragma once
#include "../base.cpp"

/**
 * @brief DFS(深さ優先探索)
 * @docs docs/graph/dfs.md
*/
struct DFS {
    struct Edge {
        long long from;
        long long to;
        
        explicit Edge(long long u = -1, long long v = -1) : from(u), to(v) {};

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

    struct Stamp {
        long long index;
        long long time;
        explicit Stamp(long long i = 0, long long t = -1) : index(i), time(t) {};

        bool operator<(const Stamp& right) const {
            return time < right.time;
        }

        friend ostream& operator << (ostream& os, const Stamp& stamp) {
            return os << "(" << stamp.time << ", " << stamp.index << ")";
        }
    };

    long long V;
    bool directed_;
    vector<vector<Edge>> G;
    vector<bool> seen, done;

    vector<Stamp> pre_order, post_order;
    long long time;
    bool has_cycle;
    vector<long long> descendants;

    vector<long long> colors;

    DFS(long long N, bool directed) : V(N), directed_(directed), G(V) {
        init();
    };
    
    void init() {
        time = 0;
        has_cycle = false;

        seen.assign(V, false);
        done.assign(V, false);
        descendants.assign(V, 0);
        colors.assign(V, -1);
    }
    
    void connect(long long from, long long to) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        if (directed_) {
            G[from].emplace_back(from, to);
        }
        else {
            G[from].emplace_back(from, to);
            G[to].emplace_back(to, from);
        }
    }

    void operator() (long long start) {
        dfs(start);
    }

    void dfs_all() {
        rep(i, V) {
            if (seen[i]) continue;
            dfs(i);
        }
    }

    void dfs(long long now) {
        assert(0 <= now and now < V);

        seen[now] = true;
        pre_order.emplace_back(now, time++);

        fore(edge, G[now]) {
            long long next = edge.to;

            if (seen[next]) {
                if (!done[next]) has_cycle = true;
                continue;
            }

            dfs(next);

            descendants[now] += descendants[next] + 1;
        }

        done[now] = true;
        post_order.emplace_back(now, time++);
    }

    bool reach(long long to) {
        assert(0 <= to and to < V);

        return seen[to] or done[to];
    }

    bool is_bipartite() {
        ll color = 0;

        rep(i, V) {
            if (seen[i]) continue;

            seen[i] = true;
            colors[i] = color;

            stack<long long> st;
            st.push(i);

            while (!st.empty()) {
                ll now = st.top();
                st.pop();

                long long next_color;
                if (colors[now] % 2 == 0) next_color = colors[now] + 1;
                else next_color = colors[now] - 1;

                fore(edge, G[now]) {
                    long long next = edge.to;

                    if (colors[next] == -1) colors[next] = next_color;
                    else if (colors[next] != next_color) return false;

                    if (seen[next]) continue;
                    seen[next] = true;

                    st.push(next);
                }
            }

            color += 2;
        }

        return true;
    }
};