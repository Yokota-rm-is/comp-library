#pragma once
#include "../base.cpp"

template <typename Key, typename Value>
struct RotatableMap2D {
    map<pair<Key, Key>, Value> original;
    long long H, W;
    pair<Key, Key> offset_key;

    RotatableMap2D() : H(0), W(0), offset_key(0, 0) {}
    RotatableMap2D(long long h, long long w) : H(h), W(w), offset_key(0, 0) {}
    RotatableMap2D(map<pair<Key, Key>, Value> mp, long long h = 0, long long w = 0) : original(mp), H(h), W(w), offset_key(0, 0) {}

    // keyの値をx増やす
    // (key_y, key_x)    : (1, 1), (2, 3), (4, 9), (8, 27), (16, 81), ... -> add_key_x
    // value:            :      3,      1,     4,       1,         5, ...
    //
    // (key_y, key_x + 1): (1, 2), (2, 4), (4, 10), (8, 28), (16, 82), ...
    // value:            :      3,      1,       4,       1,        5, ...
    pair<Key, Key> add_key_x(Key x) {
        offset_key.second += x;
        if (W > 0) offset_key.second %= W;
        return offset_key;
    }

    // keyの値をx減らす
    // (key_y, key_x)    : (1, 1), (2, 3), (4, 9), (8, 27), (16, 81), ... -> subtract_key_x
    // value:            :      3,      1,     4,       1,         5, ...
    //
    // (key_y, key_x - 1): (1, 0), (2, 2), (4, 8), (8, 26), (16, 80), ...
    // value:            :      3,      1,     4,       1,         5, ...
    pair<Key, Key> subtract_key_x(Key x) {
        if (W > 0) x %= W;
        offset_key.second += W - x;
        if (W > 0) offset_key.second %= W;
        return offset_key;
    }

    // keyの値をy増やす
    // (key_y, key_x)    : (1, 1), (2, 3), (4, 9), (8, 27), (16, 81), ... -> add_key_y
    // value:            :      3,      1,     4,       1,         5, ...
    //
    // (key_y + 1, key_x): (2, 1), (3, 3), (5, 9), (9, 27), (17, 81), ...
    // value:            :      3,      1,     4,       1,         5, ...
    pair<Key, Key> add_key_y(Key y) {
        offset_key.first += y;
        if (H > 0) offset_key.first %= H;
        return offset_key;
    }

    // keyの値をy減らす
    // (key_y, key_x)    : (1, 1), (2, 3), (4, 9), (8, 27), (16, 81), ... -> subtract_key_y
    // value:            :      3,      1,     4,       1,         5, ...
    //
    // (key_y - 1, key_x): (0, 1), (1, 3), (3, 9), (7, 27), (15, 81), ...
    // value:            :      3,      1,     4,       1,         5, ...
    pair<Key, Key> subtract_key_y(Key y) {
        if (H > 0) y %= H;
        offset_key.first += H - y;
        if (H > 0) offset_key.first %= H;
        return offset_key;
    }

    Value& operator()(Key y, Key x) {
        y += H - offset_key.first;
        x += W - offset_key.second;
        if (H > 0) y %= H;
        if (W > 0) x %= W;
        return original[{y, x}];
    }

    Value get(Key y, Key x) {
        return this->operator()(y, x);
    }

    bool contains(Key y, Key x) const {
        y += H - offset_key.first;
        x += W - offset_key.second;
        if (H > 0) y %= H;
        if (W > 0) x %= W;
        return original.contains({y, x});
    }
};