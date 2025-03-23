#pragma once
#include "../base.cpp"

template <typename T>
struct RotatableSet2D {
    set<pair<T, T>> original;
    long long H, W;
    pair<T, T> offset, offset_key;

    RotatableSet2D() : H(0), W(0), offset(0, 0), offset_key(0, 0) {}
    RotatableSet2D(long long h, long long w) : H(h), W(w), offset(0, 0), offset_key(0, 0) {}
    RotatableSet2D(set<pair<T, T>> st, long long h = 0, long long w = 0) : original(st), H(h), W(w), offset(0, 0), offset_key(0, 0) {}

    // 参照する際のkeyの値をx減らす
    // 例: rotate_left(1) で mp[0][0]がoriginal[0][1]を指す
    // (original[0][1]をmp[0][0]に移動(左回転))
    pair<T, T> rotate_left(T x) {
        offset.second += x;
        if (W > 0) offset.second %= W;
        return offset;
    }

    // 参照する際のkeyの値をx増やす
    // 例: rotate_right(1) で mp[0][1]がoriginal[0][0]を指す
    // (original[0][0]をmp[0][1]に移動(右回転))
    pair<T, T> rotate_right(T x) {
        if (W > 0) x %= W;
        offset.second += W - x;
        if (W > 0) offset.second %= W;
        return offset;
    }

    // 参照する際のkeyの値をy減らす
    // 例: rotate_up(1) で mp[0][0]がoriginal[1][0]を指す
    // (original[1][0]をmp[0][0]に移動(上回転))
    pair<T, T> rotate_up(T y) {
        offset.first += y;
        if (H > 0) offset.first %= H;
        return offset;
    }

    // 参照する際のkeyの値をy増やす
    // 例: rotate_down(1) で mp[1][0]がoriginal[0][0]を指す
    // (original[0][0]をmp[1][0]に移動(下回転))
    pair<T, T> rotate_down(T y) {
        if (H > 0) y %= H;
        offset.first += H - y;
        if (H > 0) offset.first %= H;
        return offset;
    }

    void insert(pair<T, T> key) {
        key.first += offset.first;
        key.second += offset.second;
        if (H > 0) key.first %= H;
        if (W > 0) key.second %= W;
        original.insert(key);
    }

    void insert(T y, T x) {
        insert({y, x});
    }

    void erase(pair<T, T> key) {
        key.first += offset.first;
        key.second += offset.second;
        if (H > 0) key.first %= H;
        if (W > 0) key.second %= W;
        original.erase(key);
    }

    void erase(T y, T x) {
        erase({y, x});
    }

    bool contains(pair<T, T> key) const {
        key.first += offset.first;
        key.second += offset.second;
        if (H > 0) key.first %= H;
        if (W > 0) key.second %= W;
        return original.contains(key);
    }

    bool contains(T y, T x) const {
        return contains({y, x});
    }
};