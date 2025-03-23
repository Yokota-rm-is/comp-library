#pragma once
#include "../base.cpp"

template <typename Key, typename Value>
struct RotatableMap2D {
    map<pair<Key, Key>, Value> original;
    long long H, W;
    pair<Key, Key> offset, offset_key;

    RotatableMap2D() : H(0), W(0), offset(0, 0), offset_key(0, 0) {}
    RotatableMap2D(long long h, long long w) : H(h), W(w), offset(0, 0), offset_key(0, 0) {}
    RotatableMap2D(map<pair<Key, Key>, Value> mp, long long h = 0, long long w = 0) : original(mp), H(h), W(w), offset(0, 0), offset_key(0, 0) {}

    // 参照する際のkeyの値をx減らす
    // 例: rotate_left(1) で mp[0][0]がoriginal[0][1]を指す
    // (original[0][1]をmp[0][0]に移動(左回転))
    pair<Key, Key> rotate_left(Key x) {
        offset.second += x;
        if (W > 0) offset.second %= W;
        return offset;
    }

    // 参照する際のkeyの値をx増やす
    // 例: rotate_right(1) で mp[0][1]がoriginal[0][0]を指す
    // (original[0][0]をmp[0][1]に移動(右回転))
    pair<Key, Key> rotate_right(Key x) {
        if (W > 0) x %= W;
        offset.second += W - x;
        if (W > 0) offset.second %= W;
        return offset;
    }

    // 参照する際のkeyの値をy減らす
    // 例: rotate_up(1) で mp[0][0]がoriginal[1][0]を指す
    // (original[1][0]をmp[0][0]に移動(上回転))
    pair<Key, Key> rotate_up(Key y) {
        offset.first += y;
        if (H > 0) offset.first %= H;
        return offset;
    }

    // 参照する際のkeyの値をy増やす
    // 例: rotate_down(1) で mp[1][0]がoriginal[0][0]を指す
    // (original[0][0]をmp[1][0]に移動(下回転))
    pair<Key, Key> rotate_down(Key y) {
        if (H > 0) y %= H;
        offset.first += H - y;
        if (H > 0) offset.first %= H;
        return offset;
    }

    Value& operator()(Key y, Key x) {
        y += offset.first;
        x += offset.second;
        if (H > 0) y %= H;
        if (W > 0) x %= W;
        return original[{y, x}];
    }

    Value get(Key y, Key x) {
        return this->operator()(y, x);
    }

    bool contains(Key y, Key x) const {
        y += offset.first;
        x += offset.second;
        if (H > 0) y %= H;
        if (W > 0) x %= W;
        return original.contains({y, x});
    }
};