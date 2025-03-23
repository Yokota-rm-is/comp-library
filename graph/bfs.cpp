#pragma once
#include "../base.cpp"

/**
 * @brief BFS(幅優先探索)
 * @docs docs/graph/bfs.md
*/
struct BFS {
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

    long long V;
    bool directed_;
    vector<vector<Edge>> G;
    vector<bool> seen;
    vector<long long> prev;
    vector<long long> depth;
    long long group;

    BFS(long long N, bool directed) : V(N), directed_(directed), G(V){
        init();
    };
    
    void init() {
        group = 0;
        seen.assign(V, false);
        prev.assign(V, -1);
        depth.assign(V, inf64);
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

    void operator() (vector<long long> starts) {
        solve(starts);
    }

    void operator() (long long start) {
        solve(start);
    }

    void solve_all() {
        rep(i, V) {
            if (seen[i]) continue;
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

        queue<long long> que;

        fore(start, starts) {
            seen[start] = true;
            depth[start] = 0;
            que.push(start);
        }

        while (!que.empty()) {
            long long now = que.front();
            que.pop();

            fore(edge, G[now]) {
                long long next = edge.to;
                if (seen[next]) continue;
                seen[next] = true;

                depth[next] = depth[now] + 1;
                prev[next] = now;
                que.push(next);
            }
        }
    }

    long long count_cc() {
        return group;
    }

    long long find_diameter() {
        long long ret = 0;
        vector<bool> done(V, false);

        rep(i, V) {
            if (done[i]) continue;
            solve(i);
            long long u = distance(depth.begin(), max_element(depth.begin(), depth.end()));

            init();
            solve(u);
            long long v = distance(depth.begin(), max_element(depth.begin(), depth.end()));
            
            chmax(ret, depth[v]);
            rep(i, V) {
                if (seen[i]) done[i] = true;
            }
            init();
        }

        return ret;
    }

    bool can_reach(long long to) {
        assert(0 <= to and to < V);

        return seen[to];
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