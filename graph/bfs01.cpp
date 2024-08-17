#pragma once
#include "../base.cpp"

/**
 * @brief BFS(幅優先探索)
 * @docs docs/graph/bfs.md
*/
struct BFS01 {
    struct Edge {
        long long from;
        long long to;
        long long weight;
        
        explicit Edge(long long u = -1, long long v = -1, long long w = -1) : from(u), to(v), weight(w) {};

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
    vector<bool> done;
    vector<long long> prev;
    vector<long long> cost;
    long long group;

    BFS01(long long N, bool directed) : V(N), directed_(directed), G(V){
        init();
    };
    
    void init() {
        group = 0;
        done.assign(V, false);
        prev.assign(V, -1);
        cost.assign(V, inf64);
    }
    
    void connect(long long from, long long to, long long weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);
        assert(weight == 0 or weight == 1);

        if (directed_) {
            G[from].emplace_back(from, to, weight);
        }
        else {
            G[from].emplace_back(from, to, weight);
            G[to].emplace_back(to, from, weight);
        }
    }

    void operator() (long long start) {
        solve(start);
    }

    void solve_all() {
        rep(i, V) {
            if (done[i]) continue;
            solve(i);
            ++group;
        }
    }

    void solve(long long start) {
        assert(0 <= start and start < V);

        deque<long long> que;

        // 初期条件 (頂点 start を初期ノードとする)
        cost[start] = 0;
        que.push_back(start); // noq を橙色頂点にする

        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            long long now = que.front(); // キューから先頭頂点を取り出す
            que.pop_front();

            if (done[now]) continue;
            done[now] = true;

            // v から辿れる頂点をすべて調べる
            fore(edge, G[now]) {
                long long next = edge.to;
                if (done[next]) continue; // すでに発見済みの頂点は探索しない

                if (chmin(cost[next], cost[now] + edge.weight)) {
                    if (edge.weight == 0) que.push_front(next); // 新たな白色頂点 nv について距離情報を更新してキューの先頭に追加する
                    else que.push_back(next); // 新たな白色頂点 nv について距離情報を更新してキューの末尾に追加する

                    prev[next] = now;
                }
            }
        }
    }

    long long count_cc() {
        return group;
    }

    bool can_reach(long long to) {
        assert(0 <= to and to < V);

        return done[to];
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