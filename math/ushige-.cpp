#pragma once
#include "../base.cpp"

template<class T = long long>
struct Solver {
    struct BellmanFord {
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
        bool directed_;
        vector<long long> prev;
        vector<T> cost;
        vector<Edge> edges;
    
        BellmanFord(long long N, bool directed) : V(N), directed_(directed) {
            init();
        };
        
        void init() {
            prev.assign(V, -1);
            cost.assign(V, inf64);
        }
        
        void connect(long long from, long long to, T weight) {
            assert(0 <= from and from < V);
            assert(0 <= to and to < V);
    
            edges.emplace_back(from, to, weight);
            if (!directed_) edges.emplace_back(to, from, weight);
        }
    
        void operator() (long long start) {
            solve(start);
        }
    
        void solve(long long start) {
            assert(0 <= start and start < V);
    
            bool changed = false;
            cost[start] = 0;
    
            rep(i, V) {
                changed = false;
    
                fore(e, edges) {
                    if (cost[e.from] == inf64) continue;
    
                    T c = cost[e.from] + e.weight;
                    if (chmin(cost[e.to], c)) {
                        prev[e.to] = e.from;
                        changed = true;
                    }
                }
    
                if (!changed) break;
            }
    
            if (changed) {
                rep(i, V) {
                    fore(e, edges) {
                        if (cost[e.from] == inf64) continue;
    
                        T c = cost[e.from] + e.weight;
                        if (c < cost[e.to]) {
                            cost[e.to] = -inf64;
                        }
                    }
                }
            }
        }
    
        bool can_reach(long long to) {
            assert(0 <= to and to < V);
    
            return cost[to] < inf64;
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
    
        bool has_negative_cycle() {
            rep(i, V) {
                if (cost[i] == -inf64) return true;
            }
            return false;
        }
    };

    BellmanFord bf;
    long long N;

    const long long isUnsolvable = -inf64;
    const long long isIndeterminate = inf64;

    Solver (long long n) : bf(n, true), N(n) {}

    // 差分制約式 x_j - x_i <= w を追加
    void add_less_than_or_equal(long long j, long long i, T w) {
        assert(0 <= i and i < N);
        assert(0 <= j and j < N);
        assert(i != j);

        bf.connect(i, j, w);
    }

    // 差分制約式 x_j - x_i >= w を追加
    void add_greater_than_or_equal(long long j, long long i, T w) {
        assert(0 <= i and i < N);
        assert(0 <= j and j < N);
        assert(i != j);

        bf.connect(j, i, -w);
    }

    // 差分制約式 x_j - x_i = w を追加
    void add_equal(long long j, long long i, T w) {
        assert(0 <= i and i < N);
        assert(0 <= j and j < N);
        assert(i != j);

        bf.connect(i, j, w);
        bf.connect(j, i, -w);
    }

    // maximize x_dst - x_src
    T miximize(long long src = 0, long long dst = -1) {
        T ret = 0;
        bf.solve(src);

        if (dst != -1) {
            return bf.cost[dst];
        }
        else {
            rep(i, N) {
                if (bf.cost[i] == -inf64) return isUnsolvable;
                chmax(ret, bf.cost[i]);
            }
            return ret;
        }
    }

    // minimize x_dst - x_src
    T minimize(long long dst = -1, long long src = -1) {
        if (dst == -1) dst = N - 1;
        T ret = 0;
        bf.solve(dst);

        if (src != -1) {
            if (bf.cost[src] == -inf64) return isUnsolvable;
            if (bf.cost[src] == inf64) return isIndeterminate;
            return -bf.cost[src];
        }
        else {
            rep(i, N) {
                if (bf.cost[i] == -inf64) return isUnsolvable;
                chmax(ret, bf.cost[i]);
            }
            if (ret == inf64) return isIndeterminate;
            return -ret;
        }
    }
};