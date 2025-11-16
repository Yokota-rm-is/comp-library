#pragma once
#include "../base.cpp"

template <class T, class S>
struct RangeMap {
    map<pair<T, T>, S> mp;
    S default_val;

    RangeMap(S default_val = S()) : default_val(default_val) {
        init();
    }

    void init() {
        mp.clear();
        mp[{-inf64, -inf64}] = default_val;
        mp[{inf64, inf64}] = default_val;
    }

    void set(const T l, const T r, const S val) {
        {
            auto it = prev(mp.upper_bound({l, inf64}));
            pair<T, T> range = it->first;
            S val = it->second;
            if (l < range.second) {
                mp.erase(it);
                mp[{range.first, l}] = val;
            }
        }

        {
            auto it = prev(mp.upper_bound({r, inf64}));
            pair<T, T> range = it->first;
            S val = it->second;
            if (r <= range.first) {
                mp.erase(it);
                mp[{r, range.second}] = val;
            }
        }

        mp[{l, r}] = val;
    }

    S get(const T x) {
        auto it = prev(mp.upper_bound({x, inf64}));
        return it->second;
    }
};