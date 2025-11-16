#pragma once
#include "../base.cpp"

template<typename T>
struct Imos {
    long long N;
    vector<T> A, table;
    bool built = false;
    
    Imos(long long n, T a) : N(n), A(n, a), table(n + 1, 0) {}
    Imos(vector<T> v) : N(v.size()), A(v), table(N + 1, 0) {}

    void add(long long p, T a) {
        assert(0 <= p and p < N);
        assert(!built);
        add(p, p + 1, a);
    }

    void add(long long l, long long r, T value) {
        assert(0 <= l and l <= r and r <= N);
        assert(!built);
        table[l] += value;
        table[r] -= value;
    }

    void build() {
        assert(!built);
        built = true;
        rep(i, N) {
            table[i + 1] += table[i];
        }
    }

    T get(long long p) {
        assert(built);
        assert(0 <= p and p < N);
        return A[p] + table[p];
    }
};