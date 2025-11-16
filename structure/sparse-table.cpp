#pragma once
#include "../base.cpp"

// Sparse Table
// 結合性と冪等性を満たす必要がある
// 結合則 (A ⊕　B) ⊕ C = A ⊕ (B ⊕ C)
// 冪等性 (A ⊕ A = A)
// 例: min, max, gcd, lcm, and, or など
// 構築: O(N log N)
// クエリ: O(1)
#if __cplusplus >= 201703L
template<class S, auto op>
#else
template<class S, S (*op)(S, S)>
#endif
struct SparseTable {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>, "op must be function<S(S, S)>");
#endif
    
    vector<vector<S>> table;
    vector<long long> log_table;
    long long N;

    SparseTable(const vector<S> &A) {
        N = A.size();
        log_table.assign(N + 1, 0);
        rep(i, 2, N + 1) log_table[i] = log_table[i >> 1] + 1;

        table.assign(log_table[N] + 1, vector<S>(N));
        table[0] = A;

        rep(k, 1, log_table[N] + 1) {
            rep(i, N - (1 << k) + 1) {
                table[k][i] = op(table[k - 1][i], table[k - 1][i + (1ll << (k - 1))]);
            }
        }
    }

    // 半開区間[l, r) (0-indexed) の値を求める
    S prod(long long l, long long r) {
        assert(0 <= l and l < r and r <= N);

        long long k = log_table[r - l];
        return op(table[k][l], table[k][r - (1ll << k)]);
    }
};