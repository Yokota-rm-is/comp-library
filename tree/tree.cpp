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
struct Tree {
    long long V;
    vector<vector<Edge<T>>> G;
    vector<bool> seen;
    vector<long long> prev;
    vector<T> depth;

    vector<vector<long long>> doubling;
    long long log;
    bool lca_init_done;

    Tree(long long N) : V(N), G(V){
        init();
    };
    
    void init() {
        seen.assign(V, false);
        prev.assign(V, -1);
        depth.assign(V, inf64);

        lca_init_done = false;

        log = 1;
        while ((1ll << log) <= V) ++log;

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
                depth[next] = depth[now] + edge.weight;
                prev[next] = now;
                que.push(next);
            }
        }
    }

    void lca_init(long long root) {
        assert(0 <= root and root < V);

        bfs(root);

        rep(k, log - 1) {
            rep(v, V) {
                if (doubling[k][v] >= 0) {
                    doubling[k + 1][v] = doubling[k][doubling[k][v]];
                }
            }
        }

        lca_init_done = true;
    }

    // lca_init後にuとvの最小共通祖先を返す
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

    // lca_init後にuとvの距離を返す
    long long get_dist(long long u, long long v) {
        assert(lca_init_done);
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);

        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    // lca_init後にuとvを結ぶパス上にaがあるか返す
    bool is_on_path(long long u, long long v, long long a) {
        assert(0 <= u and u < V);
        assert(0 <= v and v < V);
        assert(0 <= a and a < V);
        assert(lca_init_done);

        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }

    long long find_diameter() {
        bfs(0);
        long long u = distance(depth.begin(), max_element(depth.begin(), depth.end()));

        init();
        bfs(u);
        long long v = distance(depth.begin(), max_element(depth.begin(), depth.end()));

        return depth[v];
    }
};