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
        init();
        if (S.size() > 0) set(S);
    }

    Hash61(char c) {
        init();
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

struct RollingHashonSegmentTree {
    long long N, _N, height;
    vector<Hash61> node;

    RollingHashonSegmentTree() {}
    RollingHashonSegmentTree(string& S) { 
        init(S);
    }

    void init(string& S) {
        _N = S.size();
        N = 1;
        height = 1;
        while (N < (_N + 1)) {
            N *= 2;
            ++height;
        }
        
        node.assign(2 * N, Hash61());

        rep(i, _N) {
            node[i + N].set(S[i]);
        }
        repd(i, 1, N) update(i);
    }

    // 位置p (0-indexed)の値をcにする
    void set(long long p, char c) {
        assert(0 <= p and p <= _N);

        long long k = p + N;
        node[k].set(c);
        rep(i, 1, height) update(k >> i);
    }

    // 半開区間[l, r) (0-indexed)の総和を求める
    Hash61 prod(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        Hash61 prod_l, prod_r;
        while (l < r) {
            if (l & 1) prod_l = prod_l + node[l++];
            if (r & 1) prod_r = node[--r] + prod_r;
            l >>= 1;
            r >>= 1;
        }

        return prod_l + prod_r;
    }

private:
    void update(long long k) {
        assert(1 <= k and k <= N - 1);

        node[k] = node[k * 2] + node[k * 2 + 1];
    }
};