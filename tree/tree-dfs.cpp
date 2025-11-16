#pragma once
#include "../base.cpp"

// 木上のDFS
// 0 <= pre, post < 4 * V - 2
// 部分木クエリ
// - 頂点・辺更新: apply(pre, x)
// - 部分木クエリ: prod(pre, post)
// パスクエリ
// - 頂点・辺更新: apply(pre, x), apply(post, inv(x))
// - u-vパスクエリ: prod(pre, post)
template <typename T = long long>
struct TreeDFS {
    struct Edge {
        long long from;
        long long to;
        T weight;
        long long idx;
        
        explicit Edge(long long u = -1, long long v = -1, T w = 1, long long i = -1) : from(u), to(v), weight(w), idx(i) {};

        bool operator < (const Edge& other) const {
            if (from == other.from) return to < other.to;
            else return from < other.from;
        }

        friend ostream& operator << (ostream& os, const Edge& edge) {
            return os << edge.to;
        }
    };

    long long V;
    vector<vector<Edge>> G;
    vector<bool> seen;
    vector<T> cost;

    long long time, visit_time;
    vector<long long> pre_order, post_order, visit_order;

    vector<vector<pair<long long, long long>>> min_table;
    vector<long long> log_table;

    long long edge_index;
    bool built = false;

    TreeDFS(long long N) : V(N), G(V) {
        init();
    };

    void init() {
        time = 0;
        visit_time = 0;
        seen.assign(V, false);
        cost.assign(V, 0);

        pre_order.assign(2 * V - 1, -1);
        post_order.assign(2 * V - 1, -1);
        visit_order.assign(V, -1);

        log_table.assign(2 * V, 0);
        rep(i, 2, 2 * V) log_table[i] = log_table[i >> 1] + 1;

        min_table.assign(log_table[2 * V - 1] + 1, vector<pair<long long, long long>>(2 * V - 1, {inf32, -1}));

        edge_index = 0;
    }

    void connect(long long from, long long to, T weight = 1) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);
        assert(!built);

        G[from].emplace_back(from, to, weight, edge_index);
        G[to].emplace_back(to, from, weight, edge_index);

        edge_index++;
    }

    void build(long long root) {
        assert(0 <= root and root < V);
        assert(!built);
        built = true;

        visit_order[root] = visit_time;
        min_table[0][visit_time++] = {0, root};
        dfs(root, 0);

        rep(k, 1, log_table[2 * V - 1] + 1) {
            rep(i, 2 * V - 1 - (1 << k) + 1) {
                if (min_table[k - 1][i].first < min_table[k - 1][i + (1ll << (k - 1))].first) {
                    min_table[k][i] = min_table[k - 1][i];
                }
                else {
                    min_table[k][i] = min_table[k - 1][i + (1ll << (k - 1))];
                }
            }
        }
    }

    void dfs(long long v, long long d) {
        seen[v] = true;
        pre_order[v] = time++;

        for (auto& edge : G[v]) {
            if (seen[edge.to]) continue;

            cost[edge.to] = edge.weight + cost[v];

            visit_order[edge.to] = visit_time;
            min_table[0][visit_time++] = {d + 1, edge.to};
            pre_order[V + edge.idx] = time++;

            dfs(edge.to, d + 1);

            min_table[0][visit_time++] = {d, v};
            post_order[V + edge.idx] = time++;
        }

        post_order[v] = time++;
    }

    long long depth(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        long long pre = pre_order[v];

        return min_table[0][pre].first;
    }

    long long lca(long long u, long long v) {
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);
        assert(built);

        if (visit_order[u] > visit_order[v]) swap(u, v);

        long long l = visit_order[u];
        long long r = visit_order[v] + 1;

        long long k = log_table[r - l];
        if (min_table[k][l].first < min_table[k][r - (1ll << k)].first) {
            return min_table[k][l].second;
        }
        else {
            return min_table[k][r - (1ll << k)].second;
        }
    }

    T get_dist(long long u, long long v) {
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);
        assert(built);

        long long a = lca(u, v);

        return cost[u] + cost[v] - 2 * cost[a];
    }

    pair<long long, long long> get_vertex_index(long long v) {
        assert(0 <= v and v < V);
        assert(built);

        long long pre = pre_order[v];
        long long post = post_order[v];

        return {pre, post};
    }

    pair<long long, long long> get_edge_index(long long i) {
        assert(0 <= i and i < edge_index);
        assert(built);

        long long pre = pre_order[V + i];
        long long post = post_order[V + i];

        return {pre, post};
    }

    pair<long long, long long> get_range(long long u, long long v) {
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);
        assert(built);

        if (pre_order[u] > pre_order[v]) swap(u, v);

        long long l = pre_order[u];
        long long r = post_order[v];

        return {l, r};
    }

    pair<vector<long long>, vector<tuple<long long, long long, T>>> get_auxilary_tree(vector<long long> A) {
        assert(built);

        auto comp = [&](long long u, long long v) {
            return pre_order[u] < pre_order[v];
        };
        sort(A.begin(), A.end(), comp);

        ll k = A.size();
        rep(i, k - 1) {
            A.push_back(lca(A[i], A[i + 1]));
        }

        sort(A.begin(), A.end(), comp);
        A.erase(unique(A.begin(), A.end()), A.end());

        vector<tuple<long long, long long, T>> edges;
        rep(i, A.size() - 1) {
            long long a = lca(A[i], A[i + 1]);
            edges.emplace_back(a, A[i + 1], get_dist(a, A[i + 1]));
        }

        return {A, edges};
    }
};