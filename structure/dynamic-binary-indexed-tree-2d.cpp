#pragma once
#include "../base.cpp"

template<class T = long long>
struct DynamicBinaryIndexedTree2D {
    long long H, W, _H, _W;
    vector<unordered_map<long long, T>> bit;

    DynamicBinaryIndexedTree2D(long long h, long long w): _H(h), _W(w) {
        init();
    }

    void init() {
        H = _H + 1;
        W = _W + 1;

        bit.resize(H);
    }

    // 位置h, w (0-indexed)にxを加える
    void add(long long h, long long w, T x) {
        assert(0 <= h and h < _H and 0 <= w and w < _W);

        ++h; ++w; // 1-indexed

        for (long long i = h; i < H; i += (i & -i)) {
            for (long long j = w; j < W; j += (j & -j)) {
                bit[i][j] += x;
            }
        }
    }

    // 位置h, w (0-indexed)をxにする
    void set(long long h, long long w, T x) {
        assert(0 <= h and h < _H and 0 <= w and w < _W);

        add(h, w, x - get(h, w));
    }

    // 半開区間[0, h) x [0, w) (0-indexed)の総和を求める
    T sum(long long h, long long w) {
        assert(0 <= h and h <= _H and 0 <= w and w <= _W);

        if (h == 0 or w == 0) return 0;

        T ret = 0;
        for (long long i = h; i > 0; i -= (i & -i)) {
            for (long long j = w; j > 0; j -= (j & -j)) {
                auto it = bit[i].find(j);
                if (it == bit[i].end()) continue;
                ret += it->second;
            }
        }

        return ret;
    }

    // 半開区間[h1, h2) x [w1, w2) (0-indexed)の総和を求める
    T sum(long long h1, long long h2, long long w1, long long w2) {
        assert(0 <= h1 and h1 <= h2 and h2 <= _H and 0 <= w1 and w1 <= w2 and w2 <= _W);

        return sum(h2, w2) - sum(h1, w2) - sum(h2, w1) + sum(h1, w1);
    }

    // 位置h, w (0-indexed)の値を求める
    T get(long long h, long long w) {
        assert(0 <= h and h < _H and 0 <= w and w < _W);

        return sum(h, w, h + 1, w + 1);
    }

    friend ostream& operator << (ostream& os, DynamicBinaryIndexedTree2D& bit) {
        os << "bit" << endl;
        rep(h, bit.H) {
            rep(w, bit.W) {
                os << bit.bit[h][w] << " ";
            }
            os << endl;
        }
        os << endl;

        os << "value" << endl;
        rep(i, bit._H) {
            rep(j, bit._W) {
                os << bit.get(i, j) << " ";
            }
            os << endl;
        }

        return os;
    }
};