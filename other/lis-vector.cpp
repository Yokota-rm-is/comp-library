#pragma once
#include "../base.cpp"

template <typename T = long long, bool strict = true>
struct LISVector {
    vector<T> vals, prev, dp;
    deque<deque<T>> table;

    LISVector() {}
    LISVector(const vector<T>& v) {
        for (auto& x : v) push_back(x);
    }

    void push_back(T val) {
        vals.push_back(val);

        if (dp.empty() or dp.back() < val or (not strict and dp.back() == val)) {
            prev.push_back(dp.empty() ? -1 : dp.back());
            dp.push_back(val);
            table.push_back({val});
        } 
        else {
            long long idx = get_index(val);

            dp[idx] = val;
            table[idx].push_back(val);
            prev.push_back(idx == 0 ? -1 : dp[idx - 1]);
        }
    }

    void pop_back() {
        if (vals.empty()) return;

        T val = vals.back();
        vals.pop_back();
        prev.pop_back();

        long long idx = get_index(val);
        if constexpr (!strict) --idx;

        table[idx].pop_back();

        if (idx == table.size() - 1 and table[idx].empty()) {
            dp.pop_back();
            table.pop_back();
        }
        else {
            dp[idx] = table[idx].back();
        }
    }

    long long size() const {
        return vals.size();
    }

    long long size_lis() const {
        return table.size();
    }

    vector<T> get_lis() const {
        vector<T> ret;

        T x = dp.back();
        repd(i, vals.size()) {
            if (vals[i] == x) {
                ret.push_back(vals[i]);
                x = prev[i];
            }
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }

    // 長さkのLISのうち最小の末尾を返す
    // kは1-indexed
    T min_right(long long k) {
        assert(0 < k and k <= vals.size());

        return dp[k - 1];
    }

    // valにより更新されるdpのindexを返す
    // valが末尾になるLISの長さはindex + 1
    long long get_index(T val) {
        if constexpr (strict) {
            auto it = lower_bound(dp.begin(), dp.end(), val);
            return it - dp.begin();
        } 
        else {
            auto it = upper_bound(dp.begin(), dp.end(), val);
            return it - dp.begin();
        }
    }

    // valが末尾になるLISの長さを返す
    long long size_lis_fixed_right(T val) {
        return get_index(val) + 1;
    }
};
