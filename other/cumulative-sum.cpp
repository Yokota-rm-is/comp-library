#pragma once
#include "../base.cpp"

template<typename T>
struct CumulativeSum : vector<T> {
    CumulativeSum(vector<T>& A) {
        (*this).assign(A.size(), 0);
        init(A);
    };

    void init(vector<T>& A) {
        assert(A.size() > 0);

        (*this)[0] = A[0];
        rep(i, 1, A.size()) {
            (*this)[i] = A[i] + (*this)[i - 1];
        }
    }

    // [l, r)の範囲の区間和を求める
    T sum(long long l, long long r) {
        if (l > r) swap(l, r);

        if (l == 0) return (*this)[r - 1];
        else return (*this)[r - 1] - (*this)[l - 1];
    }

    friend ostream& operator<<(ostream& os, const CumulativeSum<T>& A) {
        rep(i, A.size()) os << A[i] << (i < A.size() - 1 ? " " : "");
        return os;
    }
};