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

struct BFS {
    long long V;
    bool directed_;
    vector<vector<Edge<>>> G;
    vector<bool> seen;
    vector<long long> prev;
    vector<long long> depth;

    BFS(long long N, bool directed) : V(N), directed_(directed), G(V){
        init();
    };
    
    void init() {
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

    void operator() (long long start) {
        bfs(start);
    }

    void bfs_all() {
        rep(i, V) {
            if (seen[i]) continue;
            bfs(i);
        }
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
                depth[next] = depth[now] + 1;
                prev[next] = now;
                que.push(next);
            }
        }
    }

    long long find_diameter() {
        long long ret = 0;

        rep(i, V) {
            if (seen[i]) continue;
            bfs(i);
            long long u = distance(depth.begin(), max_element(depth.begin(), depth.end()));

            init();
            bfs(u);
            long long v = distance(depth.begin(), max_element(depth.begin(), depth.end()));
            
            chmax(ret, depth[v]);
            init();
        }

        return ret;
    }

    bool reach_at(long long to) {
        assert(0 <= to and to < V);

        return seen[to];
    }

    vector<long long> path_to(long long to) {
        assert(0 <= to and to < V);

        vector<long long> p;
        p.push_back(to);

        while (prev[p.back()] != -1) {
            p.push_back(prev[p.back()]);
        }

        reverse(p.begin(), p.end());

        return p;
    }
};