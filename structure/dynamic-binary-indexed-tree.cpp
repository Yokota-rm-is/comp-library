#pragma once
#include "../base.cpp"

template<class T = long long>
struct DynamicBinaryIndexedTree {
    long long N, _N;
    map<long long, T> bit;

    DynamicBinaryIndexedTree(long long n): _N(n) {
        init();
    }

    void init() {
        N = _N + 1;
    }

    // 位置p (0-indexed)にxを加える
    void add(long long p, T x) {
        assert(0 <= p and p <= _N);

        ++p; // 1-indexed

        for (int idx = p; idx < N; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }

    // 位置p (0-indexed)をxにする
    void set(long long p, T x) {
        assert(0 <= p and p < _N);

        add(p, x - get(p));
    }

    // 半開区間[0, r) (0-indexed)の総和を求める
    T sum(long long r) {
        assert(0 <= r and r <= _N);

        if (r == 0) return 0;
        
        T ret = 0;
        for (int idx = r; idx > 0; idx -= (idx & -idx)) {
            ret += bit[idx];
        }
        return ret;
    }

    // 半開区間[l, r) (0-indexed)の総和を求める
    T sum(long long l, long long r) {
        assert(0 <= l and l <= r and r <= _N);

        if (l == r) return 0;
        else return sum(r) - sum(l);
    }

    // 半開区間[p, p + 1) (0-indexed)の値を求める
    T get(long long p) {
        assert(0 <= p and p < _N);
        
        return sum(p + 1) - sum(p);
    }

    friend ostream& operator << (ostream& os, DynamicBinaryIndexedTree& bit) {
        // os << "bit" << endl;
        // repd(h, bit.height) {
        //     for (long long i = (1 << h); i < (long long)bit.bit.size(); i += (1 << (h + 1))) {
        //         os << bit.bit[i] << " ";
        //     }
        //     os << endl;
        // }
        // os << endl;

        os << "value" << endl;
        rep(i, bit._N) {
            os << bit.get(i) << " ";
        }
        os << endl;

        return os;
    }
};
