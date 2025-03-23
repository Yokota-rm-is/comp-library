#pragma once
#include "../base.cpp"

/**
 * @brief ワーシャルフロイド法
 * @docs docs/graph/warshall-floyd.md
*/
template<typename T = long long>
struct WarshallFloyd {
    long long V;
    vector<vector<T>> cost;
    vector<vector<long long>> prev;
    bool directed_;
    bool built = false;

    WarshallFloyd(long long V, bool directed) : V(V), directed_(directed) {
        cost.assign(V, vector<T>(V, inf64));
        prev.assign(V, vector<long long>(V, -1));

        rep(i, V) cost[i][i] = 0;
        rep(i, V) rep(j, V) prev[i][j] = i;
    }

    WarshallFloyd(vector<vector<long long>> A, bool directed) : V(A.size()), cost(A), directed_(directed) {
        prev.assign(V, vector<long long>(V, -1));
        rep(i, V) rep(j, V) prev[i][j] = i;
    }

    void connect(long long from, long long to, T weight) {
        if (!built) connect_before_built(from, to, weight);
        else connect_after_built(from, to, weight);
    }

    void connect_before_built(long long from, long long to, T weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        chmin(cost[from][to], weight);
        if (!directed_) chmin(cost[to][from], weight);
    }

    // build後に実行
    // fromからtoへの辺を追加
    bool connect_after_built(long long from, long long to, T weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        if (cost[from][to] <= weight) return false;

        if (chmin(cost[from][to], weight)) prev[from][to] = to;
        if (!directed_ and chmin(cost[to][from], weight)) prev[to][from] = from;

        rep(i, V) {
            rep(j, V) {
                if (chmin(cost[i][j], cost[i][from] + cost[from][to] + cost[to][j])) {
                    prev[i][j] = prev[to][j];
                }

                if (!directed_ and chmin(cost[i][j], cost[i][to] + cost[to][from] + cost[from][j])) {
                    prev[i][j] = prev[from][j];
                }
            }
        }

        return true;
    }

    void operator() () {
        build();
    }

    void build() {
        built = true;

        rep(k, V) {
            rep(i, V) {
                if (cost[i][k] >= inf64) continue;

                rep(j, V) {
                    if (cost[k][j] >= inf64) continue;

                    if(chmin(cost[i][j], cost[i][k] + cost[k][j])) {
                        prev[i][j] = prev[k][j];
                    }
                }
            }
        }
    }

    bool can_reach(long long from, long long to) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        return cost[from][to] < inf64;
    }

    T get_dist(long long from, long long to) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        return cost[from][to];
    }

    vector<T> get_dist_from(long long from) {
        assert(0 <= from and from < V);

        vector<T> ret;

        rep(i, V) ret.push_back(cost[from][i]);

        return ret;
    }

    vector<long long> get_path(long long from, long long to) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        if (!can_reach(from, to)) return {};

        vector<long long> p;
        p.push_back(to);

        while (p.back() != from) {
            p.push_back(prev[from][p.back()]);
        }

        reverse(p.begin(), p.end());

        return p;
    }

    bool has_negative_cycle() {
        rep(i, V) if (cost[i][i] < 0) return true;

        return false;
    }
};