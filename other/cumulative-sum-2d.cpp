#pragma once
#include "../base.cpp"

template <typename T>
struct CumulativeSum2D {
    long long H, W;
    vector<vector<T>> values, sums;
    bool built = false;

    CumulativeSum2D(long long h, long long w) : H(h), W(w), values(H, vector<T>(W, 0)), sums(H + 1, vector<T>(W + 1, 0)) {}
    CumulativeSum2D(long long h, long long w, T a) : H(h), W(w), values(H, vector<T>(W, a)), sums(H + 1, vector<T>(W + 1, 0)) {}

    CumulativeSum2D(const vector<vector<T>>& A) : H(A.size()), W(A.front().size()), values(A), sums(H + 1, vector<T>(W + 1, 0)) {
        build(A);
    };

    void add(long long y, long long x, T a) {
        assert(0 <= y and y < H);
        assert(0 <= x and x < W);
        assert(not built);
        values[y][x] += a;
    }

    void build() {
        assert(not built);
        built = true;
        rep(i, H) rep(j, W) sums[i + 1][j + 1] = sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + values[i][j];
    }

    // [h1, h2) x [w1, w2)の範囲の区間和を求める
    T sum(long long h1, long long h2, long long w1, long long w2) {
        assert(0 <= h1 and h1 <= h2 and h2 <= H);
        assert(0 <= w1 and w1 <= w2 and w2 <= W);
        assert(built);

        return sums[h2][w2] - sums[h1][w2] - sums[h2][w1] + sums[h1][w1];
    }

    friend ostream& operator<<(ostream& os, CumulativeSum2D& cs) {
        os << "values" << endl;
        rep(i, cs.H) {
            rep(j, cs.W) os << cs.values[i][j] << " ";
            os << endl;
        }

        os << "sums" << endl;
        rep(i, cs.H + 1) {
            rep(j, cs.W + 1) os << cs.sums[i][j] << " ";
            os << endl;
        }

        return os;
    }
};