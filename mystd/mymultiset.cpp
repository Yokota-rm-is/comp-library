#pragma once
#include "../base.cpp"

template <typename T>
struct MultiSet : public map<T, long long> {
    long long N;
    using mp = map<T, long long>;

    explicit MultiSet() : N(0) {};

    long long insert(T x, long long n = 1) {
        N += n;
        return (*this)[x] += n;
    }

    long long erase(T x, long long n = 1) {
        if (n > (*this)[x]) n = (*this)[x];
        N -= n;
        (*this)[x] -= n;

        if ((*this)[x] == 0) {
            mp::erase(x);
            return 0;
        }
        else {
            return (*this)[x];
        }
    }

    void erase_all(T x) {
        N -= (*this)[x];
        mp::erase(x);
    }

    T front() {
        return mp::begin()->first;
    }

    T back() {
        return mp::rbegin()->first;
    }

    void pop() {
        erase(front());
    }

    void pop_back() {
        erase(back());
    }

    long long count_all() {
        return N;
    }

    long long count(T x) {
        if (!mp::contains(x)) return 0;
        return (*this)[x];
    }
};