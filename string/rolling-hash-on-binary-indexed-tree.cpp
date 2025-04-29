#pragma once
#include "../base.cpp"

namespace _hash61 {
    const unsigned long long MOD = (1ULL << 61) - 1;
    const unsigned long long MASK30 = (1ULL << 30) - 1;
    const unsigned long long MASK31 = (1ULL << 31) - 1;
    const unsigned long long MASK61 = MOD;

    unsigned long long set_base(unsigned long long Max = 127, unsigned long long MOD = (1ULL << 61) - 1, unsigned long long root = 37) {
        random_device rd;
        mt19937_64 gen(rd());
        uniform_int_distribution<unsigned long long> dist(1, numeric_limits<unsigned long long>::max());
        unsigned long long ret;

        while (true) {
            unsigned long long k = dist(gen);
            ret = binpow(root, k, MOD);
            if (ret > Max) break;
        }

        return ret;
    }

    unsigned long long calc_mul(unsigned long long a, unsigned long long b) {
        unsigned long long au = a >> 31;
        unsigned long long ad = a & MASK31;
        unsigned long long bu = b >> 31;
        unsigned long long bd = b & MASK31;
        unsigned long long mid = ad * bu + au * bd;
        unsigned long long midu = mid >> 30;
        unsigned long long midd = mid & MASK30;

        return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }

    unsigned long long calc_mod(unsigned long long x) {
        unsigned long long xu = x >> 61;
        unsigned long long xd = x & MASK61;
        unsigned long long res = xu + xd;
        if (res >= MOD) res -= MOD;
        return res;
    }

    unsigned long long binpow(unsigned long long x, unsigned long long n) {
        unsigned long long ret = 1;
        while (n > 0) {
            if (n & 1) ret = calc_mod(calc_mul(ret, x));
            x = calc_mod(calc_mul(x, x));
            n >>= 1;
        }
        return ret;
    }
    
    unsigned long long modinv(unsigned long long a) { return binpow(a, MOD - 2);}

    static const unsigned long long base = set_base();
    const unsigned long long base_inv = modinv(base);
}

struct Hash61 {
    unsigned long long hash, hash_rev;
    unsigned long long pow, pow_inv;
    long long N;

    Hash61() {
        init();
    }

    Hash61(string& S) {
        if (S.size() > 0) set(S);
    }

    Hash61(char c) {
        string S(1, c);
        set(S);
    }

    void init() {
        N = 0;
        hash = 0;
        hash_rev = 0;
        pow = 1;
        pow_inv = 1;
    }

    void set(char c) {
        string S = string(1, c);
        set(S);
    }

    void set(string& S) {
        init();

        N = S.size();
        
        rep(i, S.size()) {
            unsigned long long c = S[i];
            hash = _hash61::calc_mod(_hash61::calc_mul(hash, _hash61::base) + c);
            pow = _hash61::calc_mod(_hash61::calc_mul(pow, _hash61::base));
            pow_inv = _hash61::calc_mod(_hash61::calc_mul(pow_inv, _hash61::base_inv));
        }
        repd(i, S.size()) {
            unsigned long long c = S[i];
            hash_rev = _hash61::calc_mod(_hash61::calc_mul(hash_rev, _hash61::base) + c);
        }
    }

    bool is_palindrome() {
        return hash == hash_rev;
    }

    Hash61 reverse() {
        Hash61 ret;
        ret.hash = hash_rev;
        ret.hash_rev = hash;
        ret.pow = pow;
        ret.pow_inv = pow_inv;
        ret.N = N;
        return ret;
    }

    operator unsigned long long() const {
        return hash;
    }

    friend Hash61 operator+ (const Hash61 &lhs, const Hash61 &rhs) {
        return Hash61(lhs) += rhs;
    }

    Hash61& operator+= (const Hash61 &other) noexcept {
        hash = _hash61::calc_mod(_hash61::calc_mul(hash, other.pow) + other.hash);
        hash_rev = _hash61::calc_mod(_hash61::calc_mul(other.hash_rev, pow) + hash_rev);
        pow = _hash61::calc_mod(_hash61::calc_mul(pow, other.pow));
        pow_inv = _hash61::calc_mod(_hash61::calc_mul(pow_inv, other.pow_inv));

        N += other.N;

        return *this;
    }

    bool operator< (const Hash61 &other) const {
        return (N < other.N) && (hash < other.hash);
    }

    bool operator== (const Hash61 &other) const noexcept {
        return (N == other.N) && (hash == other.hash);
    }

    friend ostream& operator<<(ostream &os, const Hash61& h) {
        return os << h.hash;
    }
};

struct RollingHashonBinaryIndexedTree {
    long long N, _N, height;
    string S;
    vector<unsigned long long> bit, bit_rev;
    vector<unsigned long long> pow, pow_inv;

    RollingHashonBinaryIndexedTree(long long n): _N(n), S(n, 0) {
        init();
    }

    RollingHashonBinaryIndexedTree(const string &s): _N(s.size()), S(s.size(), 0) {
        init();

        rep(i, _N) set(i, s[i]);
    }
    
    void init() {
        N = 1;
        height = 1;
        while (N < (_N + 1)) {
            N *= 2;
            ++height;
        }

        bit.assign(N + 1, 0);
        bit_rev.assign(N + 1, 0);
        pow.assign(N + 1, 1);
        pow_inv.assign(N + 1, 1);

        rep(i, N) {
            pow[i + 1] = _hash61::calc_mod(_hash61::calc_mul(pow[i], _hash61::base));
            pow_inv[i + 1] = _hash61::calc_mod(_hash61::calc_mul(pow_inv[i], _hash61::base_inv));
        }
    }

    // 位置p (0-indexed)をxにする
    void set(long long p, char c) {
        assert(0 <= p and p < _N);

        unsigned long long x = _hash61::calc_mod(_hash61::MOD - S[p] + c);
        unsigned long long hash = _hash61::calc_mod(_hash61::calc_mul(x, pow[N - 1 - p]));
        unsigned long long hash_rev = _hash61::calc_mod(_hash61::calc_mul(x, pow[p]));

        S[p] = c;
        add(bit, p, hash);
        add(bit_rev, p, hash_rev);
    }

    // 半開区間[l, r) (0-indexed)の総和を求める
    Hash61 get(long long l, long long r) {
        assert(0 <= l and l <= r and r <= _N);

        if (l == r) return 0;

        Hash61 hash;
        hash.N = r - l;
        hash.hash = _hash61::calc_mod(_hash61::calc_mul(_hash61::calc_mod(sum(bit, r) + _hash61::MOD - sum(bit, l)), pow_inv[N - r]));
        hash.hash_rev = _hash61::calc_mod(_hash61::calc_mul(_hash61::calc_mod(sum(bit_rev, r) + _hash61::MOD - sum(bit_rev, l)), pow_inv[l]));
        hash.pow = pow[r - l];
        hash.pow_inv = pow_inv[r - l];

        return hash;
    }

private:
    // 半開区間[0, r) (0-indexed)の総和を求める
    unsigned long long sum(vector<unsigned long long> &bit, long long r) {
        assert(0 <= r and r <= _N);

        if (r == 0) return 0;
        
        unsigned long long ret = 0;
        for (int idx = r; idx > 0; idx -= (idx & -idx)) {
            ret = _hash61::calc_mod(ret + bit[idx]);
        }
        return ret;
    }

    // 位置p (0-indexed)にxを加える
    void add(vector<unsigned long long> &bit, long long p, unsigned long long x) {
        assert(0 <= p and p <= _N);

        ++p; // 1-indexed

        for (int idx = p; idx < N; idx += (idx & -idx)) {
            bit[idx] = _hash61::calc_mod(bit[idx] + x);
        }
    }
};