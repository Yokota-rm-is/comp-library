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

template<bool multi>
struct ZobristHash {
    using ull = unsigned long long;

    ull hash;

    ZobristHash() : hash(0) {}
    ZobristHash(ull hash) : hash(hash) {}

    void insert(ull x) {
        if constexpr (multi) hash += rng(x);
        else hash ^= rng(x); 
    }
    void erase(ull x) { 
        if constexpr (multi) hash -= rng(x);
        else hash ^= rng(x);
    }

    ZobristHash operator+(const ZobristHash& rhs) const { 
        if constexpr (multi) return ZobristHash<multi>(hash + rhs.hash); 
        else return ZobristHash<multi>(hash ^ rhs.hash);
    }
    ZobristHash operator-(const ZobristHash& rhs) const { 
        if constexpr (multi) return ZobristHash<multi>(hash - rhs.hash); 
        else return ZobristHash<multi>(hash ^ rhs.hash);
    }
    ZobristHash operator+(ull h) const { 
        if constexpr (multi) return ZobristHash<multi>(hash + rng(h)); 
        else return ZobristHash<multi>(hash ^ rng(h));
    }
    ZobristHash operator-(ull h) const { 
        if constexpr (multi) return ZobristHash<multi>(hash - rng(h)); 
        else return ZobristHash<multi>(hash ^ rng(h));
    }
    
    bool operator==(const ZobristHash& rhs) const { return hash == rhs.hash; }
    bool operator!=(const ZobristHash& rhs) const { return hash != rhs.hash; }
};