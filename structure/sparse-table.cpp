#pragma once
#include "../base.cpp"

template<class T = long long>
struct SparseTable {
    vector<vector<T>> min_table, max_table;
    vector<long long> log_table;
    long long N;

    SparseTable(const vector<T> &A) {
        N = A.size();
        log_table.assign(N + 1, 0);
        rep(i, 2, N + 1) log_table[i] = log_table[i >> 1] + 1;

        min_table.assign(log_table[N] + 1, vector<T>(N));
        min_table[0] = A;
        max_table.assign(log_table[N] + 1, vector<T>(N));
        max_table[0] = A;

        rep(k, 1, log_table[N] + 1) {
            rep(i, N - (1 << k) + 1) {
                min_table[k][i] = min(min_table[k - 1][i], min_table[k - 1][i + (1ll << (k - 1))]);
                max_table[k][i] = max(max_table[k - 1][i], max_table[k - 1][i + (1ll << (k - 1))]);
            }
        }
    }

    // 半開区間[l, r) (0-indexed) の最小値を求める
    T query_min(long long l, long long r) {
        assert(0 <= l and l < r and r <= N);

        long long k = log_table[r - l];
        return min(min_table[k][l], min_table[k][r - (1ll << k)]);
    }

    // 半開区間[l, r) (0-indexed) の最大値を求める
    T query_max(long long l, long long r) {
        assert(0 <= l and l < r and r <= N);

        long long k = log_table[r - l];
        return max(max_table[k][l], max_table[k][r - (1ll << k)]);
    }
};