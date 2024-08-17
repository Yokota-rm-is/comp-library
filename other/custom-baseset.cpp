#pragma once
#include "../base.cpp"

struct CustomBaseset {
    const vector<long long> bases;
    long long N;
    vector<long long> powers;

    long long x;

    CustomBaseset(long long base, long long n, long long x = 0) : bases(n, base), N(n), powers(n + 1, 1), x(x) {
        init();
    }
    
    CustomBaseset(vector<long long> bases, long long x = 0) : bases(bases), N(bases.size()), powers(N + 1, 1), x(x) {
        init();
    }

    void init() {
        rep(i, N) powers[i + 1] = powers[i] * bases[i];
    }

    void set(long long pos, long long val) {
        x += (val - get(pos)) * powers[pos];
    }

    void set(vector<long long>& v) {
        rep(i, v.size()) set(i, v[i]);
    }

    void add(long long pos, long long val) {
        long long val_pos = get(pos); 
        val = clamp(val, -val_pos, bases[pos] - 1 - val_pos);
        x += val * powers[pos];
    }

    void add(vector<long long>& v) {
        rep(i, v.size()) add(i, v[i]);
    }

    long long get(long long pos) { 
        return (x / powers[pos]) % bases[pos];
    }

    long long operator[](long long pos) { 
        return get(pos);
    }

    long long end() {
        return powers[N];
    }

    operator long long() { 
        return x; 
    }

    operator vector<long long>() {
        vector<long long> ret(N);
        rep(i, N) ret[i] = get(i);
        return ret;
    }
    
    CustomBaseset& operator++() { 
        ++x;
        return *this;
    }

    CustomBaseset& operator--() { 
        --x;
        return *this;
    }

    bool operator==(CustomBaseset other) { return x == other.x; }
    bool operator!=(CustomBaseset other) { return x != other.x; }
    bool operator<(CustomBaseset other) { return x < other.x; }
    bool operator>(CustomBaseset other) { return x > other.x; }
    bool operator<=(CustomBaseset other) { return x <= other.x; }
    bool operator>=(CustomBaseset other) { return x >= other.x; }
    bool operator==(long long other) { return x == other; }
    bool operator!=(long long other) { return x != other; }
    bool operator<(long long other) { return x < other; }
    bool operator>(long long other) { return x > other; }
    bool operator<=(long long other) { return x <= other; }
    bool operator>=(long long other) { return x >= other; }

    friend istream& operator>>(istream& is, CustomBaseset& x) { return is >> x.x; }
    friend ostream& operator<<(ostream& os, CustomBaseset& x) { 
        rep(i, x.N) {
            os << x.get(i);
            if (i < x.N - 1) os << " ";
        }
        return os; 
    }
};