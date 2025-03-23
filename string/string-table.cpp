#pragma once
#include "../base.cpp"

template <int char_size = 128, int base = 0>
struct StringTable {
    string S;
    vector<vector<long long>> indices, counts;

    StringTable() : indices(char_size), counts(char_size, vector<long long>(1, 0)) {}

    StringTable(const vector<char>& s) : indices(char_size), counts(char_size, vector<long long>(1, 0)) {
        init(s);
    }

    StringTable(const string& s) : indices(char_size), counts(char_size, vector<long long>(1, 0)) {
        init(s);
    }

    void init(const vector<char>& s) {
        rep(i, s.size()) {
            S += s[i];
            indices[S[i] - base].emplace_back(i);

            rep(j, char_size) {
                counts[j].emplace_back(counts[j].back() + (S[i] == (j + base)));
            }
        }
    }

    void init(const string& s) {
        rep(i, s.size()) {
            S += s[i];
            indices[S[i] - base].emplace_back(i);

            rep(j, char_size) {
                counts[j].emplace_back(counts[j].back() + (S[i] == (j + base)));
            }
        }
    }

    void push_back(char c) {
        indices[c - base].emplace_back(S.size());
        S += c;

        rep(j, char_size) {
            counts[j].emplace_back(counts[j].back() + (c == (j + base)));
        }
    }

    void pop_back() {
        assert(S.size() > 0);

        char c = S.back();
        indices[c - base].pop_back();
        S.pop_back();

        rep(j, char_size) {
            counts[j].pop_back();
        }
    }

    long long count(char c) {
        return counts[c - base].back();
    }

    long long count(char c, long long l, long long r) {
        assert(0 <= l and l <= r and r <= (ll)S.size());
        return counts[c - base][r] - counts[c - base][l];
    }

    // 区間[l, N)で最初に文字cが現れるインデックスを返す
    // 存在しない場合は-1を返す
    long long next_index(char c, long long l) {
        assert(0 <= l and l < (ll)S.size());

        long long k = count(c, 0, l);
        if (indices[c - base].size() <= k) return -1;
        return indices[c - base][k];
    }

    // 区間[l, r)で最初に文字cが現れるインデックスを返す
    // 存在しない場合は-1を返す
    long long next_index(char c, long long l, long long r) {
        assert(0 <= l and l <= r and r <= (ll)S.size());

        long long kl = count(c, 0, l), kr = count(c, 0, r);
        if (kl == kr) return -1;
        return indices[c - base][kl];
    }

    // 区間[0, r)で最後に文字cが現れるインデックスを返す
    // 存在しない場合は-1を返す
    long long prev_index(char c, long long r) {
        assert(0 <= r and r <= (ll)S.size());

        long long k = count(c, 0, r);
        if (k == 0) return -1;
        return indices[c - base][k - 1];
    }

    // 区間[l, r)で最後に文字cが現れるインデックスを返す
    // 存在しない場合は-1を返す
    long long prev_index(char c, long long l, long long r) {
        assert(0 <= l and l <= r and r <= (ll)S.size());

        long long kl = count(c, 0, l), kr = count(c, 0, r);
        if (kl == kr) return -1;
        return indices[c - base][kr - 1];
    }

    // k番目のcのindexを返す (kは1-indexed)
    long long index(char c, long long k) {
        assert(0 < k and k <= (ll)indices[c].size());
        return indices[c - base][k - 1];
    }

    long long index(char c, long long k, long long l, long long r) {
        assert(0 < k and k <= count(c, l, r));
        return indices[c - base][count(c, 0, l) + k - 1];
    }
};