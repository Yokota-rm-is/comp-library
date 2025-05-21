#pragma once
#include "../base.cpp"

template <long long bitsize = 64>
struct BitVector {
    using ull = unsigned long long;
    long long N, L;
    vector<ull> data;

    BitVector(long long n, bool a = 0) : N(n) {
        L = (N + bitsize - 1) / bitsize;
        data.assign(L, a ? ~0ull : 0ull);
    }

    void set(long long x, bool a) {
        assert(0 <= x and x < N);
        
        auto [p, q] = divmod(x);
        if (a) data[p] |= (1ll << q);
        else data[p] &= ~(1ll << q);
    };

    void set(long long l, long long r, bool a) {
        assert(0 <= l and l <= r and r <= N);

        auto [pl, ql] = divmod(l);
        auto [pr, qr] = divmod(r - 1);

        if (pl == pr) {
            ull mask = (~0ull >> (bitsize - 1 - (qr - ql))) << ql;
            data[pl] = a ? (data[pl] | mask) : (data[pl] & ~mask);
        } 
        else {
            ull maskl = ~0ull << ql;
            data[pl] = a ? (data[pl] | maskl) : (data[pl] & ~maskl);

            rep(p, pl + 1, pr) data[p] = a ? ~0ull : 0ull;

            ull maskr = ~0ull >> (bitsize - 1 - qr);
            data[pr] = a ? (data[pr] | maskr) : (data[pr] & ~maskr);
        }
    } 

    bool get(long long x) {
        assert(0 <= x and x < N);

        auto [p, q] = divmod(x);
        return (data[p] >> q) & 1;
    }

    BitVector get(long long l, long long r) {
        assert(0 <= l and l <= r and r <= N);

        auto [pl, ql] = divmod(l);

        BitVector ret(r - l);

        if (l == r) return ret;

        if (ql == 0) {
            rep(i, ret.L) ret.data[i] = data[pl + i];
        } 
        else {
            rep(i, ret.L) {
                ull low  = data[pl + i] >> ql;
                ull high = (pl + i + 1 < L) ? data[pl + i + 1] << (bitsize - ql) : 0;
                
                ret.data[i] = low | high;
            }
        }

        long long q = ret.N % bitsize;
        if (q != 0) ret.data.back() &= (1ull << q) - 1;

        return ret;
    }

    long long bit_count() {
        return bit_count(0, N);
    }

    long long bit_count(long long l, long long r) {
        assert(0 <= l and l <= r and r <= N);

        long long ret = 0;

        auto [pl, ql] = divmod(l);
        auto [pr, qr] = divmod(r - 1);

        if (pl == pr) {
            ull mask = (~0ull >> (bitsize - 1 - (qr - ql))) << ql;
            ret += this->popcount(data[pl] & mask);
        } 
        else {
            ull maskl = ~0ull << ql;
            ret += popcount(data[pl] & maskl);

            rep(p, pl + 1, pr) ret += popcount(data[p]);

            ull maskr = ~0ull >> (bitsize - 1 - qr);
            ret += popcount(data[pr] & maskr);
        }

        return ret;
    }

    BitVector operator& (const BitVector& other) const {
        return BitVector(*this) &= other;
    };

    BitVector operator| (const BitVector& other) const {
        return BitVector(*this) |= other;
    };

    BitVector operator^ (const BitVector& other) const {
        return BitVector(*this) ^= other;
    };

    BitVector& operator&= (const BitVector& other) {
        assert(N == other.N);

        rep(i, L) this->data[i] &= other.data[i];
        return *this;
    }

    BitVector& operator|= (const BitVector& other) {
        assert(N == other.N);

        rep(i, L) this->data[i] |= other.data[i];
        return *this;
    }

    BitVector& operator^= (const BitVector& other) {
        assert(N == other.N);

        rep(i, L) this->data[i] ^= other.data[i];
        return *this;
    }

    void dump() {
        rep(i, N) {
            cerr << get(i);
        }
        cerr << endl;
    }

private:
    pair<long long, long long> divmod(long long x) {
        return {x / bitsize, x % bitsize};
    }

    ull popcount(ull x) {
#if __cplusplus > 201703L
        return std::popcount(x);
#else 
        return __builtin_popcountull(x); 
#endif
    }
};