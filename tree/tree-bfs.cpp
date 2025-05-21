#pragma once
#include "../base.cpp"

/**
 * @brief tree-bfs
 * @docs docs/tree/tree-bfs.md
*/
template <typename T = long long>
struct TreeBFS {
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
    vector<vector<Edge>> G;
    vector<bool> seen;
    vector<long long> prev;
    vector<long long> depth;
    vector<T> cost;

    vector<vector<long long>> doubling;
    long long log;
    bool lca_init_done;

    TreeBFS(long long N) : V(N), G(V){
        init();
    };
    
    void init() {
        seen.assign(V, false);
        prev.assign(V, -1);
        depth.assign(V, inf64);
        cost.assign(V, inf64);

        lca_init_done = false;

        log = 1;
        while ((1ll << log) < V) ++log;

        doubling.assign(log, vector<long long>(V, -1));
    }
    
    void connect(long long from, long long to, T weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        G[from].emplace_back(from, to, weight);
        G[to].emplace_back(to, from, weight);
    }

    void bfs(long long start) {
        assert(0 <= start and start < V);

        queue<long long> que;

        // 初期条件 (頂点 start を初期ノードとする)
        seen[start] = true;
        depth[start] = 0;
        cost[start] = 0;
        que.push(start); // noq を橙色頂点にする

        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            long long now = que.front(); // キューから先頭頂点を取り出す
            que.pop();

            // v から辿れる頂点をすべて調べる
            fore(edge, G[now]) {
                long long next = edge.to;
                if (seen[next]) continue; // すでに発見済みの頂点は探索しない
                seen[next] = true;

                // 新たな白色頂点 nv について距離情報を更新してキューに追加する
                depth[next] = depth[now] + 1;
                cost[next] = cost[now] + edge.weight;
                prev[next] = now;
                que.push(next);
            }
        }
    }

    long long find_diameter() {
        long long ret = 0;
        vector<bool> done(V, false);

        rep(i, V) {
            if (done[i]) continue;
            bfs(i);
            long long u = distance(cost.begin(), max_element(cost.begin(), cost.end()));

            init();
            bfs(u);
            long long v = distance(cost.begin(), max_element(cost.begin(), cost.end()));
            
            chmax(ret, cost[v]);
            rep(i, V) {
                if (seen[i]) done[i] = true;
            }
            init();
        }

        return ret;
    }

    void lca_init(long long root) {
        assert(0 <= root and root < V);

        bfs(root);

        rep(i, V) {
            doubling[0][i] = prev[i];
        }

        rep(k, log - 1) {
            rep(v, V) {
                if (doubling[k][v] >= 0) {
                    doubling[k + 1][v] = doubling[k][doubling[k][v]];
                }
            }
        }

        lca_init_done = true;
    }

    // lca_init後に実行
    // uとvの最小共通祖先を返す
    long long lca(long long u, long long v) {
        assert(lca_init_done);
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);

        if (depth[u] < depth[v]) swap(u, v);

        rep(k, log) {
            if ((depth[u] - depth[v]) >> k & 1) {
                u = doubling[k][u];
            }
        }

        if (u == v) return u;
        
        repd(k, log - 1) {
            if (doubling[k][u] != doubling[k][v]) {
                u = doubling[k][u];
                v = doubling[k][v];
            }
        }

        return doubling.front()[u];
    }

    // lca_init後に実行
    // uとvの距離を返す
    long long get_dist(long long u, long long v) {
        assert(lca_init_done);
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);

        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    // lca_init後に実行
    vector<long long> get_path(long long u, long long v) {
        assert(lca_init_done);
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);

        vector<long long> ret;
        long long a = lca(u, v);

        while (u != a) {
            ret.push_back(u);
            u = prev[u];
        }
        ret.push_back(a);
        vector<long long> tmp;
        while (v != a) {
            tmp.push_back(v);
            v = prev[v];
        }
        reverse(tmp.begin(), tmp.end());
        ret.insert(ret.end(), tmp.begin(), tmp.end());

        return ret;
    }

    // lca_init後に実行
    // uとvを結ぶパス上にaがあるか返す
    bool is_on_path(long long u, long long v, long long a) {
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);
        assert(0 <= a and a < V);
        assert(lca_init_done);

        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }


};