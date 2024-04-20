#pragma once
#include "../base.cpp"

template <typename Weight = long long, typename DP = long long>
struct TreeDP {
    struct Edge {
        long long from;
        long long to;
        Weight weight;
        long long rev;
        
        explicit Edge(long long u = -1, long long v = -1, Weight w = 1, long long r = -1) : from(u), to(v), weight(w), rev(r) {};

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
    vector<vector<Edge>> G;
    vector<bool> seen;

    // 全方位木dp用
    vector<vector<DP>> dp;
    vector<DP> prod_all;
    long long root;

    TreeDP(long long N) : V(N), G(V){
        init();
    };

    DP id() {
        return 0;
    }

    DP merge(DP x, DP y) {
        return max(x, y);
    }

    DP put_edge(DP x, Edge& edge) {
        return x + (DP)edge.weight;
    }

    DP put_vertex(DP x, long long v) {
        return x;
    }
    
    void init() {
        seen.assign(V, false);

        dp.resize(V);
        prod_all.assign(V, id());
    }
    
    void connect(long long from, long long to, Weight weight = 1) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        long long from_id = G[from].size();
        long long to_id = G[to].size();

        G[from].emplace_back(from, to, weight, to_id);
        G[to].emplace_back(to, from, weight, from_id);

        dp[from].push_back(id());
        dp[to].push_back(id());
    }

    DP build(long long root_) {
        root = root_;
        return dfs(root);
    }

    vector<DP> reroot() {
        prod(root, id());

        return prod_all;
    }

    DP dfs(long long now) {
        assert(0 <= now and now < V);

        DP ret = id();

        seen[now] = true;

        rep(i, G[now].size()) {
            Edge edge = G[now][i];
            long long next = edge.to;

            if (seen[next]) continue;

            dp[now][i] = dfs(next);
            ret = merge(ret, put_edge(dp[now][i], edge));
        }

        return put_vertex(ret, now);
    }

    void prod(long long now, const DP& dp_p, Edge e = Edge()) {
        long long deg = G[now].size();

        if (e.rev != -1) dp[now][e.rev] = dp_p;

        vector<DP> prod_l(deg + 1, id()), prod_r(deg + 1, id());

        rep(i, deg) {
            Edge edge = G[now][i];
            prod_l[i + 1] = merge(prod_l[i], put_edge(dp[now][i], edge));
        }

        repd(i, deg) {
            Edge edge = G[now][i];
            prod_r[i] = merge(prod_r[i + 1], put_edge(dp[now][i], edge));
        }

        prod_all[now] = put_vertex(prod_l.back(), now);

        rep(i, deg) {
            if (i == e.rev) continue;

            Edge edge = G[now][i];
            long long child = edge.to;
            prod(child, put_vertex(merge(prod_l[i], prod_r[i + 1]), now), edge);
        }
    }
};