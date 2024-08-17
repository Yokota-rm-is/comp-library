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
        static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
} rng;

struct ZobristSet {
    using ull = unsigned long long;

    ull hash;

    ZobristSet() : hash(0) {}
    ZobristSet(ull hash) : hash(hash) {}

    void insert(ull x) { hash ^= rng(x); }
    void erase(ull x) { hash ^= rng(x); }

    ZobristSet operator+(const ZobristSet& rhs) const { return ZobristSet(hash ^ rhs.hash); }
    ZobristSet operator-(const ZobristSet& rhs) const { return ZobristSet(hash ^ rhs.hash); }
    ZobristSet operator+(ull h) const { return ZobristSet(hash ^ rng(h)); }
    ZobristSet operator-(ull h) const { return ZobristSet(hash ^ rng(h)); }
    
    bool operator==(const ZobristSet& rhs) const { return hash == rhs.hash; }
    bool operator!=(const ZobristSet& rhs) const { return hash != rhs.hash; }
};