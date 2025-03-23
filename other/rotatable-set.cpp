#pragma once
#include "../base.cpp"

template <typename T>
struct RotatableSet {
    set<T> original;
    long long N;
    T offset, offset_key;

    RotatableSet() : N(0), offset(0), offset_key(0) {}
    RotatableSet(long long n) : N(n), offset(0), offset_key(0) {}
    RotatableSet(set<T> st, long long n = 0) : original(st), N(n), offset(0), offset_key(0) {}

    // 参照する際のkeyの値をx減らす
    // 例: rotate_left(1) で mp[0]がoriginal[1]を指す
    // (original[1]をmp[0]に移動(左回転))
    T rotate_left(T x) {
        offset += x;
        if (N > 0) offset %= N;
        return offset;
    }

    // 参照する際のkeyの値をx増やす
    // 例: rotate_right(1) で mp[1]がoriginal[0]を指す
    // (original[0]をmp[1]に移動(右回転))
    T rotate_right(T x) {
        if (N > 0) x %= N;
        offset += N - x;
        if (N > 0) offset %= N;
        return offset;
    }

    void insert(T key) {
        key += offset;
        if (N > 0) key %= N;
        original.insert(key);
    }

    void erase(T key) {
        key += offset;
        if (N > 0) key %= N;
        original.erase(key);
    }

    bool contains(T key) const {
        key += offset;
        if (N > 0) key %= N;
        return original.contains(key);
    }

    void dump() {
        cerr << "offset: " << offset << endl;
        cerr << "original: ";
        fore(p, original) cerr << p << " ";
        cerr << endl;

        cerr << "rotated: ";
        
        T first_key = N - (offset_key % N);
        if (N > 0) first_key %= N;
        auto first = original.lower_bound(first_key);
        for (auto it = first; it != original.end(); ++it) {
            T key = it + N - offset_key;
            cerr << key << (it != --original.end() ? " " : "");   
        }
        for (auto it = original.begin(); it != first; ++it) {
            T key = it + N - offset_key;
            cerr << key << (it != --original.end() ? " " : "");   
        }
        cerr << endl;
    }

    friend ostream& operator<<(ostream& os, const RotatableSet<T>& st) {
        T first_key = st.N - (st.offset_key % st.N);
        if (st.N > 0) first_key %= st.N;
        auto first = st.original.lower_bound(first_key);
        for (auto it = first; it != st.original.end(); ++it) {
            T key = it + st.N - st.offset_key;
            os << key << (it != --st.original.end() ? " " : "");
        }
        for (auto it = st.original.begin(); it != first; ++it) {
            T key = it + st.N - st.offset_key;
            os << key << (it != --st.original.end() ? " " : "");
        }
        return os;
    }
};