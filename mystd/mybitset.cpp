#pragma once
#include "../base.cpp"

struct Bitset {
    long long bit;

    Bitset(long long b = 0) : bit(b) {}

    void set(long long pos, bool val = true) { val? bit |= (1ll << pos): bit &= ~(1ll << pos); }
    void set(vector<long long> pos, bool val = true) { for (auto x : pos) set(x, val);}

    void flip(long long pos) { bit ^= (1ll << pos); }
    void reset(long long pos) { bit &= ~(1ll << pos); }
    void reset(vector<long long> pos) { for (auto x : pos) reset(x);}
    bool test(long long pos) { return (bit >> pos) & 1ll; }
    long long count() { return bit_count(bit); }
    long long to_ll() { return bit; }
    operator long long() { return bit; }

    // bitの次の部分集合を求める(降順)
    // 部分集合を列挙しながらbit全探索する場合の計算量はO(3^N)
    // 使い方
    // Bitset bit;
    // for (Bitset sub = bit;; sub = bit.prev_subset(sub)) {
    // 
    //     if (sub == 0ll) break;
    // }
    Bitset prev_subset(Bitset subset) {
        return Bitset((subset.bit - 1) & bit);
    }

    void foreach_subset(function<void(Bitset)> f) {
        for (Bitset sub = *this;; sub = this->prev_subset(sub)) {
            f(sub);
            if (sub == 0ll) break;
        }
    }

    // 自身がxの部分集合かどうか判定
    bool is_subset_of(Bitset x) { return (bit & x.bit) == bit; }
    // 自身がxの上位集合かどうか判定
    bool is_superset_of(Bitset x) { return (bit & x.bit) == x.bit; }
    // 自身がxの真部分集合かどうか判定
    bool is_proper_subset_of(Bitset x) { return bit != x.bit && (bit & x.bit) == bit; }
    // 自身がxの真上位集合かどうか判定
    bool is_proper_superset_of(Bitset x) { return bit != x.bit && (bit & x.bit) == x.bit; }
    // 自身がxと交差しているかどうか判定
    bool intersects(Bitset x) { return bit & x.bit; }
    
    Bitset& operator++() { bit = bit + 1; return *this; }
    Bitset operator&(Bitset x) { return bit & x.bit; }
    Bitset operator|(Bitset x) { return bit | x.bit; }
    Bitset operator^(Bitset x) { return bit ^ x.bit; }
    Bitset operator~() { return ~bit; }
    Bitset operator<<(long long x) { return bit << x; }
    Bitset operator>>(long long x) { return bit >> x; }
    Bitset& operator&=(Bitset x) { bit &= x.bit; return *this; }
    Bitset& operator|=(Bitset x) { bit |= x.bit; return *this; }
    Bitset& operator^=(Bitset x) { bit ^= x.bit; return *this; }
    Bitset& operator<<=(long long x) { bit <<= x; return *this; }
    Bitset& operator>>=(long long x) { bit >>= x; return *this; }
    bool operator==(Bitset x) { return bit == x.bit; }
    bool operator!=(Bitset x) { return bit != x.bit; }
    bool operator<(Bitset x) { return bit < x.bit; }
    bool operator>(Bitset x) { return bit > x.bit; }
    bool operator<=(Bitset x) { return bit <= x.bit; }
    bool operator>=(Bitset x) { return bit >= x.bit; }
    bool operator==(long long x) { return bit == x; }
    bool operator!=(long long x) { return bit != x; }
    bool operator<(long long x) { return bit < x; }
    bool operator>(long long x) { return bit > x; }
    bool operator<=(long long x) { return bit <= x; }
    bool operator>=(long long x) { return bit >= x; }

    friend istream& operator>>(istream& is, Bitset& x) { return is >> x.bit; }
    friend ostream& operator<<(ostream& os, Bitset& x) { 
        os << (x.bit & 1) << " ";
        x.bit >>= 1;

        while (x.bit) {
            os << (x.bit & 1) << " ";
            x.bit >>= 1;
        }
        return os; 
    }
};

// bitDP
// 計算量: O(2^N)
void bitDP(long long N, function<void(Bitset)> f) {
    for (Bitset bit = 0; bit < (1ll << N); ++bit) {
        f(bit);
    }
}

// 部分集合を列挙するbitDP
// 計算量: O(3^N)
void bitDP_subset(long long N, function<void(Bitset, Bitset, Bitset)> f) {
    for (Bitset bit = 0; bit < (1ll << N); ++bit) {
        for (Bitset sub = bit;; sub = bit.prev_subset(sub)) {
            f(bit, sub, bit ^ sub);
            if (sub == 0ll) break;
        }
    }
}