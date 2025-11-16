#pragma once
#include "../base.cpp"

template <typename T>
struct RotatableSet2D {
    set<pair<T, T>> original;
    long long H, W;
    pair<T, T> offset_key;

    RotatableSet2D() : H(0), W(0), offset_key(0, 0) {}
    RotatableSet2D(long long h, long long w) : H(h), W(w), offset_key(0, 0) {}
    RotatableSet2D(set<pair<T, T>> st, long long h = 0, long long w = 0) : original(st), H(h), W(w), offset_key(0, 0) {}

    // keyの値をx増やす
    // (key_y, key_x)    : (3, 2), (1, 7), (4, 1), (1, 8), (5, 2), (9, 8)
    // (key_y, key_x + 1): (3, 3), (1, 8), (4, 2), (1, 9), (5, 3), (9, 9)
    pair<T, T> add_key_x(T x) {
        offset_key.second += x;
        if (W > 0) offset_key.second %= W;
        return offset_key;
    }

    // keyの値をx減らす
    // (key_y, key_x)    : (3, 2), (1, 7), (4, 1), (1, 8), (5, 2), (9, 8)
    // (key_y, key_x - 1): (3, 1), (1, 6), (4, 0), (1, 7), (5, 1), (9, 7)
    pair<T, T> subtract_key_x(T x) {
        if (W > 0) x %= W;
        offset_key.second += W - x;
        if (W > 0) offset_key.second %= W;
        return offset_key;
    }

    // keyの値をy増やす
    // (key_y, key_x)    : (3, 2), (1, 7), (4, 1), (1, 8), (5, 2), (9, 8)
    // (key_y + 1, key_x): (4, 2), (2, 7), (5, 1), (2, 8), (6, 2), (10, 8)
    pair<T, T> add_key_y(T y) {
        offset_key.first += y;
        if (H > 0) offset_key.first %= H;
        return offset_key;
    }

    // keyの値をy減らす
    // (key_y, key_x)    : (3, 2), (1, 7), (4, 1), (1, 8), (5, 2), (9, 8)
    // (key_y - 1, key_x): (2, 2), (0, 7), (3, 1), (0, 8), (4, 2), (8, 8)
    pair<T, T> subtract_key_y(T y) {
        if (H > 0) y %= H;
        offset_key.first += H - y;
        if (H > 0) offset_key.first %= H;
        return offset_key;
    }

    void insert(pair<T, T> key) {
        key.first += H - offset_key.first;
        key.second += W - offset_key.second;
        if (H > 0) key.first %= H;
        if (W > 0) key.second %= W;
        original.insert(key);
    }

    void insert(T y, T x) {
        insert({y, x});
    }

    void erase(pair<T, T> key) {
        key.first += H - offset_key.first;
        key.second += W - offset_key.second;
        if (H > 0) key.first %= H;
        if (W > 0) key.second %= W;
        original.erase(key);
    }

    void erase(T y, T x) {
        erase({y, x});
    }

    bool contains(pair<T, T> key) const {
        key.first += H - offset_key.first;
        key.second += W - offset_key.second;
        if (H > 0) key.first %= H;
        if (W > 0) key.second %= W;
        return original.contains(key);
    }

    bool contains(T y, T x) const {
        return contains({y, x});
    }
};