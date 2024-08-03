#pragma once
#include "../base.cpp"

template <typename T>
struct LIS {
    long long N;
    vector<T> A, dp;
    vector<long long> pos;

    LIS(vector<T> &a) : N(a.size()), A(a), pos(N) {}

    ll solve() {
        rep(i, A.size()) {
            auto p = find_greater_than_or_equal(dp, A[i]);
            ll idx = distance(dp.begin(), p);

            if (p == dp.end()) dp.emplace_back(A[i]);
            else dp[idx] = A[i];
            pos[i] = idx;
        }

        return dp.size();
    }

    vector<T> restore() {
        vector<T> ret;
        ll idx = dp.size() - 1;
        
        repd(i, N) {
            if (pos[i] == idx) {
                ret.emplace_back(A[i]);
                idx--;
            }
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }

    vector<T> restore_indices() {
        vector<T> ret;
        ll idx = dp.size() - 1;
        
        repd(i, N) {
            if (pos[i] == idx) {
                ret.emplace_back(i);
                idx--;
            }
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};