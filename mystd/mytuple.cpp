#pragma once
#include "../base.cpp"

template <typename T>
struct Tuple : public pair<pair<T, T>, pair<T, T>> {
    using pp = pair<pair<T, T>, pair<T, T>>;

    Tuple(T a, T b, T c) : pp({a, b}, {c, 0}) {};
    Tuple(T a, T b, T c, T d) : pp({a, b}, {c, d}) {};

    T& operator[] (size_t i) {
        assert(i < 4);

        if (i == 0) return pp::first.first;
        if (i == 1) return pp::first.second;
        if (i == 2) return pp::second.first;
        return pp::second.second;
    }

    T& first() { return pp::first.first;}
    T& second() { return pp::first.second;}
    T& third() { return pp::second.first;}
    T& fourth() { return pp::second.second;}
};