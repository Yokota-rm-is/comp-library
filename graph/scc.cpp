#pragma once
#include "../base.cpp"

struct SCC {
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
    vector<vector<Edge>> G, rG;
    vector<bool> seen, done;
    vector<long long> roots;

    vector<Stamp> pre_order, post_order;
    long long pre_time, post_time;

    vector<set<long long>> scc;

    SCC(long long N) : V(N), G(V), rG(V) {
        init();
    };
    
    void init() {
        pre_time = 0;
        post_time = 0;

        seen.assign(V, false);
        done.assign(V, false);
        roots.assign(V, -1);
    }
    
    void connect(long long from, long long to) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        G[from].emplace_back(from, to);
        rG[to].emplace_back(to, from);
    }

    long long operator() () {
        return find_scc();
    }

    long long find_scc() {
        rep(i, V) {
            if (seen[i]) continue;
            dfs(i);
        }

        vector<long long> v(V);
        rep(i, V) {
            v[post_order[i].time] = post_order[i].index;
        }
        reverse(v);
        
        fore(index, v) {
            if (roots[index] != -1) continue;
            dfs_reverse(index, index);
        }

        map<long long, set<long long>> m;

        rep(i, roots.size()) {
            m[roots[i]].insert(i);
        }

        fore(p, m) {
            set<long long> s_i = p.second;
            scc.push_back(s_i);
        }

        return (long long)scc.size();
    }

    bool is_same(long long u, long long v) {
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);
        
        return roots[u] == roots[v];
    }

private:
    void dfs(long long now) {
        assert(0 <= now and now < V);

        seen[now] = true;
        pre_order.emplace_back(now, pre_time++);

        fore(edge, G[now]) {
            long long next = edge.to;
            if (seen[next]) continue;
            dfs(next);
        }

        done[now] = true;
        post_order.emplace_back(now, post_time++);
    }

    void dfs_reverse(long long now, long long group) {
        roots[now] = group;

        fore(edge, rG[now]) {
            long long next = edge.to;
            if (roots[next] != -1) continue;
            dfs_reverse(next, group);
        }
    }
};