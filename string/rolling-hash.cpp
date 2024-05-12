#pragma once
#include "../base.cpp"

unsigned long long set_base(unsigned long long Max = 127, unsigned long long MOD = (1ULL << 61) - 1, unsigned long long root = 37) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<int> dist(1, INF32);
    unsigned long long ret;

    while (true) {
        int k = dist(gen);
        ret = binpow(root, (unsigned long long)k, MOD);
        if (ret > Max) break;
    };

    return ret;
}
static const unsigned long long base = set_base();

struct Hash61 {
    static const unsigned long long MOD = (1ULL << 61) - 1;
    static const unsigned long long MASK30 = (1ULL << 30) - 1;
    static const unsigned long long MASK31 = (1ULL << 31) - 1;
    static const unsigned long long MASK61 = MOD;
    
    unsigned long long hash, hash_rev;
    unsigned long long pow;
    unsigned long long size;

    Hash61() {
        init();
    }

    Hash61(string S) {
        init();
        if (S.size() > 0) set(S);
    }

    Hash61(char c) {
        init();
        set(string(1, c));
    }

    void init() {
        assert(base > 0);
        size = 0;
        hash = 0;
        hash_rev = 0;
        pow = 1;
    }

    void set(char c) {
        set(string(1, c));
    }

    void set(string S) {
        size = S.size();
        
        rep(i, S.size()) {
            unsigned long long c = S[i];
            hash = calc_mod(calc_mul(hash, base) + c);
            pow = calc_mod(calc_mul(pow, base));
        }
        repd(i, S.size()) {
            unsigned long long c = S[i];
            hash_rev = calc_mod(calc_mul(hash_rev, base) + c);
        }
    }

    bool is_palindrome() {
        return hash == hash_rev;
    }

    Hash61& operator+= (const Hash61 &other) noexcept {
        hash = calc_mod(calc_mul(hash, other.pow) + other.hash);
        hash_rev = calc_mod(calc_mul(other.hash_rev, pow) + hash_rev);
        pow = calc_mod(calc_mul(pow, other.pow));

        size += other.size;

        return *this;
    }

    Hash61 operator+ (const Hash61 &other) const noexcept {
        return Hash61(*this) += other;
    }

    bool operator< (const Hash61 &other) const {
        return (size < other.size) and (hash < other.hash);
    }

    bool operator== (const Hash61 &other) const noexcept {
        return (size == other.size) and (hash == other.hash);
    }

    static unsigned long long calc_mul(unsigned long long a, unsigned long long b) {
        unsigned long long au = a >> 31;
        unsigned long long ad = a & MASK31;
        unsigned long long bu = b >> 31;
        unsigned long long bd = b & MASK31;
        unsigned long long mid = ad * bu + au * bd;
        unsigned long long midu = mid >> 30;
        unsigned long long midd = mid & MASK30;

        return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }

    static unsigned long long calc_mod(unsigned long long x) {
        unsigned long long xu = x >> 61;
        unsigned long long xd = x & MASK61;
        unsigned long long res = xu + xd;
        if (res >= MOD) res -= MOD;
        return res;
    }

    friend ostream& operator << (ostream &os, const Hash61& h) {
        return os << h.hash;
    }
};

struct RollingHash {
    long long N;
    vector<Hash61> hashed;

    RollingHash(const string &S) : N(S.size()) {
        construct(S);
    }

    void construct(string S) {
        Hash61 hash;

        hashed.push_back(hash);

        rep(i, N) {
            hash += S[i];
            hashed.push_back(hash);
        }
    }

    unsigned long long get(long long r) {
        return hashed[r].hash;
    }

    // [l, r)のハッシュ値を取得
    unsigned long long get(long long l, long long r) {
        if (l == 0) return hashed[r].hash;
        
        return Hash61::calc_mod(hashed[r].hash + Hash61::MOD - Hash61::calc_mod(Hash61::calc_mul(hashed[l].hash, hashed[r - l].pow)));
    }

    long long lcp(long long l1, long long r1, long long l2, long long r2) {
        long long low = 0;
        long long high = min(r1 - l1, r2 - l2);
        if (get(l1, l1 + high) == get(l2, l2 + high)) return high;

        while (high - low > 1) {
            long long mid = (high + low) / 2;

            if (get(l1, l1 + mid) == get(l2, l2 + mid)) low = mid;
            else high = mid;
        }

        return low;
    }

    long long lcp(long long l1, long long l2) {
        long long low = 0;
        long long high = min(N - l1, N - l2);
        if (get(l1, l1 + high) == get(l2, l2 + high)) return high;

        while (high - low > 1) {
            long long mid = (high + low) / 2;

            if (get(l1, l1 + mid) == get(l2, l2 + mid)) low = mid;
            else high = mid;
        }

        return low;
    }

    friend ostream& operator << (ostream &os, const RollingHash& h) {
        rep(i, h.N) os << h.hashed[i] << " ";
        return os;
    }
};