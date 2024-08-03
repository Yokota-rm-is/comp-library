#pragma once
#include "../base.cpp"

struct Bitset {
    long long bit;

    Bitset(long long bit = 0) : bit(bit) {}

    void set(long long pos, bool val = true) { val? bit |= (1ll << pos): bit &= ~(1ll << pos); }
    void set(vector<long long> pos, bool val = true) { for (auto x : pos) set(x, val);}

    void flip(long long pos) { bit ^= (1ll << pos); }
    void reset(long long pos) { bit &= ~(1ll << pos); }
    void reset(vector<long long> pos) { for (auto x : pos) reset(x);}
    bool test(long long pos) { return (bit >> pos) & 1ll; }
    long long count() { return bit_count(bit); }
    long long to_ll() { return bit; }
    operator long long() { return bit; }
    bool any(Bitset x) { return bit & x.bit; }
    bool all(Bitset x) { return (bit & x.bit) == x.bit; }
    bool none(Bitset x) { return !(bit & x.bit); }

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