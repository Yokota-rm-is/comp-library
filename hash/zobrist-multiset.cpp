#pragma once
#include "../base.cpp"

// 整数値 x にハッシュ値を割り当てる関数
struct CustomHash {
    using ull = unsigned long long;

    static ull splitmix64(ull x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    ull operator() (ull x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
} rng;

struct ZobristMultiset {
    using ull = unsigned long long;

    ull hash;

    ZobristMultiset() : hash(0) {}
    ZobristMultiset(ull hash) : hash(hash) {}

    void insert(ull x) { hash += rng(x); }
    void erase(ull x) { hash -= rng(x); }

    ZobristMultiset operator+(const ZobristMultiset& rhs) const { return ZobristMultiset(hash + rhs.hash); }
    ZobristMultiset operator-(const ZobristMultiset& rhs) const { return ZobristMultiset(hash - rhs.hash); }
    ZobristMultiset operator+(ull h) const { return ZobristMultiset(hash + h); }
    ZobristMultiset operator-(ull h) const { return ZobristMultiset(hash - h); }

    bool operator==(const ZobristMultiset& rhs) const { return hash == rhs.hash; }
    bool operator!=(const ZobristMultiset& rhs) const { return hash != rhs.hash; }
};