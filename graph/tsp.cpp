#include "../base.cpp"

// bitDP (巡回セールスマン問題)
// 計算量: O(N^2 2^N) (N<=19)
template<typename T = long long>
struct TSP {
    struct Edge {
        long long from;
        long long to;
        T weight;
        
        explicit Edge(long long u, long long v, T w = 1) : from(u), to(v), weight(w) {};

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
    bool directed;
    Graph G;
    vector<vector<T>> dp;
    vector<vector<long long>> prev;
    long long max_visit = 0;

    T INF = inf64;

    explicit TSP(long long V, bool directed) : V(V), G(V), directed(directed) {
        init();
    }

    void init() {
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
        bitdp(start);
    }

    void bitdp(long long start) {
        assert(0 <= start and start < V);

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

    bool reach(long long to) {
        assert(0 <= to and to < V);

        return dp[(1 << V)][to] != INF;
    }

    T get_dist(long long start, long long goal, long long bit) {
        if (goal != start) bit ^= (1 << start); 
        return dp[bit][goal];
    }

    T get_travel_dist(long long start, long long goal) {
        long long bit = (1 << V) - 1;
        if (goal != start) bit ^= (1 << start); 
        return dp[bit][goal];
    }

    T dist_to(long long goal) {
        long long start;
        rep(i, V) if (dp[0][i] == 0) start = i;

        long long bit = (1 << V) - 1;

        return get_dist(start, goal, bit);
    }

    vector<long long> path_to(long long goal) {
        long long start;
        rep(i, V) if (dp[0][i] == 0) start = i;

        long long bit = (1 << V) - 1;
        if (start != goal) {
            bit ^= (1 << start);
        }

        vector<long long> p;
        p.push_back(goal);

        long long to = goal;
        while (true) {
            long long from = prev[bit][to];
            if (from == -1) break;

            p.push_back(from);
            bit ^= (1 << to);
            to = from;
        }

        reverse(p.begin(), p.end());

        return p;
    }
};
