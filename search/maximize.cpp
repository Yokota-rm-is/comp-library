

#pragma once
#include "../base.cpp"

// mainにfをおく
// auto f = [&](auto x){return A[x];};

// 三分探索による最大化
// 範囲: [left, right]
// 計算量: O(log(right - left))
long long maximize(auto f, long long left, long long right) {
    while (right - left > 2ll) {
        long long m_left = (left * 2 + right) / 3;
        long long m_right = (left + right * 2) / 3;

        if (f(m_left) < f(m_right)) {
            left = m_left;
        } 
        else {
            right = m_right;
        }
    }

    long long ret = (f(left) > f(right)) ? left : right;
    return (f(midpoint(left, right)) > f(ret)) ? midpoint(left, right) : ret;
}

double maximize(auto f, double left, double right) {
    rep(i, 165) {
        double m_left = (left * 2 + right) / 3;
        double m_right = (left + right * 2) / 3;

        if (f(m_left) < f(m_right)) {
            left = m_left;
        } 
        else {
            right = m_right;
        }
    }

    double ret = (f(left) > f(right)) ? left : right;
    return (f(midpoint(left, right)) > f(ret)) ? midpoint(left, right) : ret;
}

long double maximize(auto f, long double left, long double right) {
    rep(i, 165) {
        long double m_left = (left * 2 + right) / 3;
        long double m_right = (left + right * 2) / 3;

        if (f(m_left) < f(m_right)) {
            left = m_left;
        } 
        else {
            right = m_right;
        }
    }

    long double ret = (f(left) > f(right)) ? left : right;
    return (f(midpoint(left, right)) > f(ret)) ? midpoint(left, right) : ret;
}