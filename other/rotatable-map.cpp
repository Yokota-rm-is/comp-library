#pragma once
#include "../base.cpp"

template <typename Key, typename Value>
struct RotatableMap {
    map<Key, Value> original;
    long long N;
    long long offset, offset_key;

    RotatableMap() : N(0), offset(0), offset_key(0) {}
    RotatableMap(map<Key, Value> mp, long long m = 0) : original(mp), N(m), offset(0), offset_key(0) {}

    // 参照する際のkeyの値をx減らす
    // 例: rotate_left(1) で mp[0]がoriginal[1]を指す
    // (original[1]をmp[0]に移動(左回転))
    Key rotate_left(Key x) {
        offset += x;
        if (N > 0) offset %= N;
        return offset;
    }

    // 参照する際のkeyの値をx増やす
    // 例: rotate_right(1) で mp[1]がoriginal[0]を指す
    // (original[0]をmp[1]に移動(右回転))
    Key rotate_right(Key x) {
        if (N > 0) x %= N;
        offset += N - x;
        if (N > 0) offset %= N;
        return offset;
    }

    Value& operator[](Key key) {
        key += offset;
        if (N > 0) key %= N;
        
        return original[key];
    }

    Value get(Key key) {
        return this->operator[](key);
    }

    bool contains(Key key) const {
        key += offset;
        if (N > 0) key %= N;
        return original.contains(key);
    }

    void dump() {
        cerr << "offset: " << offset << endl;
        cerr << "original: ";
        fore(p, original) cerr << p.first << ": " << p.second << endl;

        cerr << "rotated: ";
        
        Key first_key = N - (offset_key % N);
        if (N > 0) first_key %= N;
        auto first = original.lower_bound(first_key);
        for (auto it = first; it != original.end(); ++it) {
            Key key = it->first + N - offset_key;
            cerr << key << ": " << it->second << endl;
        }
        for (auto it = original.begin(); it != first; ++it) {
            Key key = it->first + N - offset_key;
            cerr << key << ": " << it->second << endl;
        }
        cerr << endl;
    }

    friend ostream& operator<<(ostream& os, const RotatableMap<Key, Value>& mp) {
        Key first_key = mp.N - (mp.offset_key % mp.N);
        if (mp.N > 0) first_key %= mp.N;

        auto first = mp.original.lower_bound(first_key);
        for (auto it = first; it != mp.original.end(); ++it) {
            Key key = it->first + mp.N - mp.offset_key;
            os << key << ": " << it->second << endl;
        }
        for (auto it = mp.original.begin(); it != first; ++it) {
            Key key = it->first + mp.N - mp.offset_key;
            os << key << ": " << it->second << endl;
        }
        return os;
    }
};