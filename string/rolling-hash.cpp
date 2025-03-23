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

struct RollingHash {
    long long N;
    vector<Hash61> hashed;

    RollingHash(const string &S) : N(S.size()) {
        construct(S);
    }

    void construct(const string &S) {
        Hash61 hash;

        hashed.push_back(hash);

        rep(i, N) {
            hash += S[i];
            hashed.push_back(hash);
        }
    }

    Hash61 get() {
        return hashed[N];
    }

    Hash61 get(long long r) {
        return hashed[r];
    }

    // [l, r)のハッシュ値を取得
    Hash61 get(long long l, long long r) {
        if (l == 0) return hashed[r];

        Hash61 ret;
        ret.hash = _hash61::calc_mod(hashed[r].hash + _hash61::MOD - _hash61::calc_mod(_hash61::calc_mul(hashed[l].hash, hashed[r - l].pow)));
        ret.hash_rev = _hash61::calc_mod(_hash61::calc_mul(_hash61::calc_mod(hashed[r].hash_rev + _hash61::MOD - hashed[l].hash_rev), hashed[l].pow_inv));
        ret.N = r - l;
        ret.pow = hashed[r - l].pow;
        ret.pow_inv = hashed[r - l].pow_inv;
        return ret;
    }

    Hash61 insert(long long pos, char c) {
        return get(pos) + Hash61(c) + get(pos + 1, N);
    }

    Hash61 insert(long long pos, string &S) {
        return get(pos) + Hash61(S) + get(pos + S.size(), N);
    }

    Hash61 erase(long long pos) {
        return get(pos) + get(pos + 1, N);
    }

    Hash61 erase(long long l, long long r) {
        return get(l) + get(r, N);
    }

    Hash61 replace(long long pos, char c) {
        return get(pos) + Hash61(c) + get(pos + 1, N);
    }

    Hash61 replace(long long l, long long r, string &S) {
        return get(l) + Hash61(S) + get(r, N);
    }

    Hash61 reverse() {
        return hashed[N].hash_rev;
    }

    Hash61 reverse(long long l, long long r) {
        return get(l) + get(l, r).reverse() + get(r, N);
    }

    bool is_palindrome(long long l, long long r) {
        return get(l, r).is_palindrome();
    }

    // 区間[l1, r1)と区間[l2, r2)の最長共通接頭辞の長さを返す
    // 計算量O(logn)
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
        return lcp(l1, N, l2, N);
    }

    long long lcp(RollingHash &rhs, long long l1, long long r1, long long l2, long long r2) {
        long long low = 0;
        long long high = min(r1 - l1, r2 - l2);
        if (get(l1, l1 + high) == rhs.get(l2, l2 + high)) return high;

        while (high - low > 1) {
            long long mid = (high + low) / 2;

            if (get(l1, l1 + mid) == rhs.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }

        return low;
    }

    long long lcp(RollingHash &rhs, long long l1, long long l2) {
        return lcp(rhs, l1, N, l2, rhs.N);
    }

    long long lcp(RollingHash &rhs) {
        return lcp(rhs, 0, N, 0, rhs.N);
    }

    // 区間[l1, r1)と区間[l2, r2)の最長共通接尾辞の長さを返す
    long long lcs(RollingHash &rhs, long long l1, long long r1, long long l2, long long r2) {
        long long low = 0;
        long long high = min(r1 - l1, r2 - l2);
        if (get(r1 - high, r1) == rhs.get(r2 - high, r2)) return high;

        while (high - low > 1) {
            long long mid = (high + low) / 2;

            if (get(r1 - mid, r1) == rhs.get(r2 - mid, r2)) low = mid;
            else high = mid;
        }

        return low;
    }

    long long lcs(RollingHash &rhs, long long l1, long long l2) {
        return lcs(rhs, l1, N, l2, rhs.N);
    }

    long long lcs(RollingHash &rhs) {
        return lcs(rhs, 0, N, 0, rhs.N);
    }

    friend long long lcp(RollingHash &lhs, RollingHash &rhs, long long l1, long long r1, long long l2, long long r2) {
        return lhs.lcp(rhs, l1, r1, l2, r2);
    }

    friend long long lcp(RollingHash &lhs, RollingHash &rhs, long long l1, long long l2) {
        return lhs.lcp(rhs, l1, l2);
    }

    friend long long lcp(RollingHash &lhs, RollingHash &rhs) {
        return lhs.lcp(rhs, 0, lhs.N, 0, rhs.N);
    }

    friend long long lcs(RollingHash &lhs, RollingHash &rhs, long long l1, long long r1, long long l2, long long r2) {
        return lhs.lcs(rhs, l1, r1, l2, r2);
    }

    friend long long lcs(RollingHash &lhs, RollingHash &rhs, long long l1, long long l2) {
        return lhs.lcs(rhs, l1, l2);
    }

    friend long long lcs(RollingHash &lhs, RollingHash &rhs) {
        return lhs.lcs(rhs, 0, lhs.N, 0, rhs.N);
    }

    operator Hash61() {
        return get();
    }

    operator unsigned long long() {
        return get();
    }

    bool operator== (RollingHash &rhs) {
        return N == rhs.N and hashed == rhs.hashed;
    }

    friend ostream& operator<<(ostream &os, const RollingHash& h) {
        rep(i, h.N + 1) os << h.hashed[i] << " ";
        return os;
    }
};