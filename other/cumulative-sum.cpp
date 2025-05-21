#pragma once
#include "../base.cpp"

template<typename T>
struct CumulativeSum : vector<T> {
    using v = vector<T>;

    CumulativeSum() : vector<T>() {};

    CumulativeSum(vector<T>& A) {
        init(A);
    };

    void init(vector<T>& A) {
        assert(A.size() > 0);

        v::assign(A.size(), 0);
        v::at(0) = A[0];
        rep(i, 1, A.size()) {
            v::at(i) = A[i] + v::at(i - 1);
        }
    }

    void push_back(T x) {
        if (v::size() == 0) v::push_back(x);
        else v::push_back(v::back() + x);
    }

    void pop_back() {
        v::pop_back();
    }

    // [l, r)の範囲の区間和を求める
    T sum(long long l, long long r) {
        assert(0 <= l and l <= r and r <= v::size());
        if (l == r) return T(0);
        if (l > r) swap(l, r);

        if (l == 0) return v::at(r - 1);
        else return v::at(r - 1) - v::at(l - 1);
    }

    T get(long long i) {
        assert(i < v::size());
        if (i == 0) return v::at(0);
        else return v::at(i) - v::at(i - 1);
    }

    friend ostream& operator<<(ostream& os, const CumulativeSum<T>& A) {
        rep(i, A.size()) os << A[i] << (i < A.size() - 1 ? " " : "");
        return os;
    }
};