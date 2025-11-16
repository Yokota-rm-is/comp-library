#pragma once
#include "../base.cpp"

// Sparse Table 2D
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
struct SparseTable2D {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>, "op must be function<S(S, S)>");
#endif
    
    vector<vector<vector<vector<S>>>> table;
    vector<long long> log_table;
    long long H, W;

    SparseTable2D(const vector<vector<S>> &A) {
        H = A.size(), W = A[0].size();
        ll n = max(H, W);
        log_table.assign(n + 1, 0);
        rep(i, 2, n + 1) log_table[i] = log_table[i >> 1] + 1;

        table.resize(log_table[H] + 1);
        rep(i, 0, log_table[H] + 1) {
            table[i].resize(log_table[W] + 1);
            rep(j, 0, log_table[W] + 1) {
                table[i][j].resize(H);
                rep(k, 0, H) {
                    table[i][j][k].resize(W);
                }
            }
        }

        rep(i, H) rep(j, W) {
            table[0][0][i][j] = A[i][j];
        }

        for (long long k = 1; (1ll << k) <= H; ++k) {
            for (long long i = 0; i + (1ll << k) <= H; ++i) {
                for (long long j = 0; j < W; ++j) {
                    table[k][0][i][j] = op(table[k - 1][0][i][j], table[k - 1][0][i + (1ll << (k - 1))][j]);
                }
            }
        }

        for (long long k = 0; (1ll << k) <= H; ++k) {
            for (long long l = 1; (1ll << l) <= W; ++l) {
                for (long long i = 0; i + (1ll << k) <= H; ++i) {
                    for (long long j = 0; j + (1ll << l) <= W; ++j) {
                        table[k][l][i][j] = op(table[k][l - 1][i][j], table[k][l - 1][i][j + (1ll << (l - 1))]);
                    }
                }
            }
        }
    }

    // 半開区間[h1, h2) x [w1, w2) (0-indexed) の値を求める
    S prod(long long h1, long long h2, long long w1, long long w2) {
        assert(0 <= h1 and h1 < h2 and h2 <= H);
        assert(0 <= w1 and w1 < w2 and w2 <= W);
        long long k = log_table[h2 - h1];
        long long l = log_table[w2 - w1];

        S sml = op(table[k][l][y1][w1], table[k][l][h2 - (1ll << k)][w1]);
        S smr = op(table[k][l][y1][w2 - (1ll << l)], table[k][l][h2 - (1ll << k)][w2 - (1ll << l)]);

        return op(sml, smr);
    }
};