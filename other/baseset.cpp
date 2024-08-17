#pragma once
#include "../base.cpp"

vector<long long> powers = {1};

struct Baseset {
    const long long base;
    long long x;

    Baseset(long long base, long long x = 0) : base(base), x(x) {}

    Baseset(long long base, vector<long long> v) : base(base), x(0) {
        rep(i, v.size()) add(i, v[i]);
    }

    void set(long long pos, long long val) {
        x += (val - get(pos)) * pow(pos);
    }

    void set(vector<long long>& v) {
        rep(i, v.size()) set(i, v[i]);
    }

    void add(long long pos, long long val) {
        long long val_pos = get(pos); 
        val = clamp(val, -val_pos, base - 1 - val_pos);
        x += val * pow(pos);
    }

    void add(vector<long long>& v) {
        rep(i, v.size()) add(i, v[i]);
    }

    long long get(long long pos) { 
        return (x / pow(pos)) % base;
    }

    long long operator[](long long pos) { 
        return get(pos);
    }

    long long pow(long long pos) {
        if (pos < (ll)powers.size()) return powers[pos];

        long long ret = powers.back();
        rep(i, pos - powers.size() + 1) {
            ret *= base;
            powers.push_back(ret);
        }
        return ret;
    }

    long long end(long long pos) {
        return pow(pos + 1);
    }

    operator long long() { 
        return x; 
    }
    
    Baseset& operator++() { 
        ++x;
        return *this;
    }

    Baseset& operator--() { 
        --x;
        return *this;
    }

    bool operator==(Baseset other) { return x == other.x; }
    bool operator!=(Baseset other) { return x != other.x; }
    bool operator<(Baseset other) { return x < other.x; }
    bool operator>(Baseset other) { return x > other.x; }
    bool operator<=(Baseset other) { return x <= other.x; }
    bool operator>=(Baseset other) { return x >= other.x; }
    bool operator==(long long other) { return x == other; }
    bool operator!=(long long other) { return x != other; }
    bool operator<(long long other) { return x < other; }
    bool operator>(long long other) { return x > other; }
    bool operator<=(long long other) { return x <= other; }
    bool operator>=(long long other) { return x >= other; }

    friend istream& operator>>(istream& is, Baseset& x) { return is >> x.x; }
    friend ostream& operator<<(ostream& os, Baseset& x) { 
        long long y = x.x;
        long long base = x.base;
        os << y % base;
        y /= base;

        while (y > 0) {
            os << " " << y % base;
            y /= base;
        }
        return os; 
    }
};