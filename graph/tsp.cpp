#include "../base.cpp"

// bitDP (巡回セールスマン問題)
// 計算量: O(N^2 2^N) (N<=19)
template<typename T = long long>
struct TSP {
    struct Edge {
        long long from, to;
        T weight;
        
        Edge(long long u, long long v, T w = 1) : from(u), to(v), weight(w) {};

        bool operator< (const Edge& other) const {
            if (from == other.from) {
                if (to == other.to) return weight < other.weight;
                else return to < other.to;
            }
            else return from < other.from;
        }
    };

    using Graph = vector<vector<Edge>>;

    long long V;
    Graph G;
    bool directed;
    vector<vector<T>> dp;
    vector<vector<long long>> prev;
    long long max_visit = 0;
    long long _start;

    T INF = inf64;

    explicit TSP(long long v, bool directed) : V(v), G(V), directed(directed) {
        init();
    }

    void init() {
        _start = -1;
        dp.assign((1 << V), vector<T>(V, INF));
        prev.assign((1 << V), vector<long long>(V, -1));
    }

    void connect(long long from, long long to, T weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        G[from].emplace_back(from, to, weight);
        if (!directed) G[to].emplace_back(to, from, weight);
    }

    void operator() (long long start) {
        solve(start);
    }

    void solve(long long start) {
        assert(0 <= start and start < V);
        _start = start;

        dp[0][start] = 0;

        rep(bit, (1 << V)) {
            rep(now, V) {
                if (dp[bit][now] > INF - 1) continue;

                fore(edge, G[now]) {
                    long long next = edge.to;
                    if (bit & (1 << next)) continue;

                    long long next_bit = bit | (1 << next);

                    if (chmin(dp[next_bit][next], dp[bit][now] + edge.weight)) {
                        prev[next_bit][next] = now;
                        chmax(max_visit, bit_count(next_bit));
                    }
                }
            }
        }
    }

    bool can_reach(long long to) {
        assert(0 <= to and to < V);

        return dp[(1 << V)][to] != INF;
    }

    T get_dist(long long goal, long long bit = -1) {
        if (bit < 0) bit = (1 << V) - 1;
        if (_start != goal) bit &= ~(1 << _start);

        return dp[bit][goal];
    }

    T get_cycle_dist(long long bit = -1) {
        if (bit < 0) bit = (1 << V) - 1;

        return dp[bit][_start];
    }

    vector<long long> get_path(long long goal, long long bit = -1) {
        if (bit < 0) bit = (1 << V) - 1;

        if (_start != goal) bit &= ~(1 << _start);

        vector<long long> p;
        p.push_back(goal);

        long long to = goal;
        while (true) {
            long long from = prev[bit][to];
            if (from == -1) break;

            p.push_back(from);
            bit &= ~(1 << to);
            to = from;
        }

        reverse(p.begin(), p.end());

        return p;
    }
};
