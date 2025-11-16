#pragma once
#include "../base.cpp"

template <typename T>
struct RotatableVector2D {
    vector<vector<T>> original;
    long long H, W;
    pair<long long, long long> offset;

    RotatableVector2D(long long h, long long w, T a = T()) : original(h, vector<T>(w, a)), H(h), W(w), offset(0, 0) {}
    RotatableVector2D(vector<vector<T>> v) : original(v), H(v.size()), W(v[0].size()), offset(0, 0) {}

    // 参照する際のindexの値をx減らす
    // original
    // i\j 0, 1, 2, 3, 4, 5
    // 0   3, 1, 4, 1, 5, 9
    // 1   2, 7, 1, 8, 2, 8 <- rotate left 
    // 2   1, 4, 1, 4, 2, 1
    // 
    // i\j 0, 1, 2, 3, 4, 5
    // 0   1, 4, 1, 5, 9
    // 1   7, 1, 8, 2, 8
    // 2   4, 1, 4, 2, 1 
    pair<long long, long long> rotate_left(long long x = 1) {
        assert(x >= 0);
        offset.second += W - (x % W);
        offset.second %= W;
        return offset;
    }

    // 参照する際のindexの値をx増やす
    // original
    // i\j 0, 1, 2, 3, 4, 5
    // 0   3, 1, 4, 1, 5, 9
    // 1   2, 7, 1, 8, 2, 8 -> rotate right
    // 2   1, 4, 1, 4, 2, 1
    //
    // i\j 0, 1, 2, 3, 4, 5
    // 0    , 3, 1, 4, 1, 5
    // 1    , 2, 7, 1, 8, 2
    // 2    , 1, 4, 1, 4, 2
    pair<long long, long long> rotate_right(long long x = 1) {
        assert(x >= 0);
        offset.second += x;
        offset.second %= W;
        return offset;
    }

    // 参照する際のindexの値をy減らす
    // original
    // i\j 0, 1, 2, 3, 4, 5
    // 0   3, 1, 4, 1, 5, 9
    // 1   2, 7, 1, 8, 2, 8
    // 2   1, 4, 1, 4, 2, 1,
    //        ^ rotate up
    // 
    // i\j 0, 1, 2, 3, 4, 5
    // 0   2, 7, 1, 8, 2, 8
    // 1   1, 4, 1, 4, 2, 1
    // 2   
    pair<long long, long long> rotate_up(long long y = 1) {
        assert(y >= 0);
        offset.first += H - (y % H);
        offset.first %= H;
        return offset;
    }

    // 参照する際のindexの値をy増やす
    // original
    // i\j 0, 1, 2, 3, 4, 5
    // 0   3, 1, 4, 1, 5, 9
    // 1   2, 7, 1, 8, 2, 8
    // 2   1, 4, 1, 4, 2, 1
    //        v rotate down
    //
    // i\j 0, 1, 2, 3, 4, 5
    // 0   
    // 1   3, 1, 4, 1, 5, 9
    // 2   2, 7, 1, 8, 2, 8
    pair<long long, long long> rotate_down(long long y = 1) {
        assert(y >= 0);
        offset.first += y;
        offset.first %= H;
        return offset;
    }

    T& operator()(long long y, long long x) {
        y += H - offset.first;
        x += W - offset.second;
        y %= H;
        x %= W;
        return original[y][x];
    }

    const T& operator()(long long y, long long x) const {
        y += H - offset.first;
        x += W - offset.second;
        y %= H;
        x %= W;
        return original[y][x];
    }

    T get(long long y, long long x) const {
        return this->operator()(y, x);
    }

    void dump() {
        cerr << "offset: " << offset << endl;
        cerr << "original: ";
        rep(i, H) {
            rep(j, W) cerr << original[i][j] << " ";
            cerr << endl;
        }
        cerr << "rotated: ";
        rep(i, H) {
            rep(j, W) cerr << get(i, j) << " ";
            cerr << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const RotatableVector2D<T>& v) {
        rep(i, v.H) {
            rep(j, v.W) os << v.get(i, j) << (j == v.W - 1 ? "" : " ");
            os << endl;
        }
        return os;
    }
};