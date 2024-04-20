#pragma once
#include "../base.cpp"

template<typename T = long long>
struct WarshallFloyd {
    long long V;
    vector<vector<T>> cost{};
    vector<vector<long long>> prev{};
    bool directed_;

    WarshallFloyd(long long V, bool directed) : V(V), directed_(directed) { //最初は全てが根であるとして初期化
        cost.assign(V, vector<T>(V, inf64));
        prev.assign(V, vector<long long>(V, -1));

        rep(i, V) cost[i][i] = 0;
        rep(i, V) rep(j, V) prev[i][j] = i;
    }

    WarshallFloyd(vector<vector<long long>> A) : V(A.size()), cost(A), directed_(true)  {
        prev.assign(A.size(), vector<long long>(A.size(), -1));
        rep(i, V) rep(j, V) prev[i][j] = i;
    }

    void connect(long long u, long long v, T w) {
        cost[u][v] = w;
        if (!directed_) cost[v][u] = w;
    }

    void operator() () {
        warshall_floyd();
    }

    void warshall_floyd() {
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

    T dist(long long from, long long to) {
        return cost[from][to];
    }

    vector<T> dist_from(long long from) {
        vector<T> ans;

        rep(i, V) ans.push_back(cost[from][i]);

        return ans;
    }

    vector<long long> path(long long from, long long to) {
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