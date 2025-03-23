#pragma once
#include "../base.cpp"

template <typename T>
struct RotatableVector {
    vector<T> original;
    long long N, offset;

    RotatableVector(long long n) : original(n), N(n), offset(0) {}
    RotatableVector(vector<T> v) : original(v), N(v.size()), offset(0) {}

    // 参照する際のindexの値をx減らす
    // 例: rotate_left(1) で vec[0]がoriginal[1]を指す
    // (original[1]をvec[0]に移動(左回転))
    long long rotate_left(long long x = 1) {
        assert(x >= 0);
        offset += x;
        offset %= N;
        return offset;
    }

    // 参照する際のindexの値をx増やす
    // 例: rotate_right(1) で vec[1]がoriginal[0]を指す
    // (original[0]をvec[1]に移動(右回転))
    long long rotate_right(long long x = 1) {
        assert(x >= 0);
        offset += N - (x % N);
        offset %= N;
        return offset;
    }

    T& operator[](long long x) {
        x += offset;
        x %= N;
        return original[x];
    }

    const T& operator[](long long x) const {
        x += offset;
        x %= N;
        return original[x];
    }

    T get(long long x) const {
        return this->operator[](x);
    }

    long long size() const {
        return N;
    }

    void dump() {
        cerr << "offset: " << offset << endl;
        cerr << "original: ";
        rep(i, N) cerr << original[i] << " ";
        cerr << endl;
        cerr << "rotated: ";
        rep(i, N) cerr << get(i) << " ";
        cerr << endl;
    }

    friend ostream& operator<<(ostream& os, const RotatableVector<T>& v) {
        rep(i, v.size()) os << v.get(i) << (i == v.size() - 1 ? "" : " ");
        return os;
    }
};