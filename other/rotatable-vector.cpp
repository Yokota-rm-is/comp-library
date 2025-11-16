#pragma once
#include "../base.cpp"

template <typename T>
struct RotatableVector {
    vector<T> original;
    long long N, offset;

    RotatableVector(long long n, T a = T()) : original(n, a), N(n), offset(0) {}
    RotatableVector(vector<T> v) : original(v), N(v.size()), offset(0) {}

    // 参照する際のindexの値をx減らす
    // i  : 0, 1, 2, 3, 4, 5, ...
    // Ai : 3, 1, 4, 1, 5, 9, ... <- rotate left
    // A'i: 1, 4, 1, 5, 9, 2, ...
    long long rotate_left(long long x = 1) {
        assert(x >= 0);
        offset += N - (x % N);
        offset %= N;
        return offset;
    }

    // 参照する際のindexの値をx増やす
    // i  : 0, 1, 2, 3, 4, 5, ...
    // Ai : 3, 1, 4, 1, 5, 9, ... -> rotate right
    // A'i:  , 3, 1, 4, 1, 5, ...
    long long rotate_right(long long x = 1) {
        assert(x >= 0);
        offset += x;
        offset %= N;
        return offset;
    }

    T& operator[](long long x) {
        x += N - offset;
        x %= N;
        return original[x];
    }

    const T& operator[](long long x) const {
        x += N - offset;
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