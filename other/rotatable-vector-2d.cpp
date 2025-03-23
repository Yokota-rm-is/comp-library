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
    // 例: rotate_left(1) で vec[0][0]がoriginal[0][1]を指す
    // (original[0][1]をvec[0][0]に移動(左回転))
    pair<long long, long long> rotate_left(long long x = 1) {
        assert(x >= 0);
        offset.second += x;
        offset.second %= W;
        return offset;
    }

    // 参照する際のindexの値をx増やす
    // 例: rotate_right(1) で vec[0][1]がoriginal[0][0]を指す
    // (original[0][0]をvec[0][1]に移動(右回転))
    pair<long long, long long> rotate_right(long long x = 1) {
        assert(x >= 0);
        offset.second += W - (x % W);
        offset.second %= W;
        return offset;
    }

    // 参照する際のindexの値をy減らす
    // 例: rotate_up(1) で vec[0][0]がoriginal[1][0]を指す
    // (original[1][0]をvec[0][0]に移動(上回転))
    pair<long long, long long> rotate_up(long long y = 1) {
        assert(y >= 0);
        offset.first += y;
        offset.first %= H;
        return offset;
    }

    // 参照する際のindexの値をy増やす
    // 例: rotate_down(1) で vec[1][0]がoriginal[0][0]を指す
    // (original[0][0]をvec[1][0]に移動(下回転))
    pair<long long, long long> rotate_down(long long y = 1) {
        assert(y >= 0);
        offset.first += H - (y % H);
        offset.first %= H;
        return offset;
    }

    T& operator()(long long y, long long x) {
        y += offset.first;
        x += offset.second;
        y %= H;
        x %= W;
        return original[y][x];
    }

    const T& operator()(long long y, long long x) const {
        y += offset.first;
        x += offset.second;
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