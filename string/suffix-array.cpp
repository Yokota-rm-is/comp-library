#pragma once
#include "../base.cpp"

// 計算量
// 構築: O(|S| log|S|)
// 検索: O(|T| log|S|)
// 下記URLをほぼコピペ
// https://ei1333.github.io/algorithm/suffix-array.html
struct SuffixArray {
    vector<long long> sa;
    string S;

    SuffixArray(const string &S) : S(S) {
        build();
    }

    void build() {
        long long N = S.size();
        sa.resize(N);
        rep(i, N) sa[i] = i;

        sort(sa.begin(), sa.end(), [&](long long a, long long b) {
            return S[a] == S[b] ? a > b : S[a] < S[b];
        });

        vector<long long> classes(N);
        rep(i, N) {
            classes[i] = S[i];
        }

        for (long long len = 1; len < N; len <<= 1) {
            vector<long long> c(classes);
            rep(i, N) {
                bool same = i > 0 and sa[i - 1] + len < N and c[sa[i]] == c[sa[i - 1]] and c[sa[i] + len / 2] == c[sa[i - 1] + len / 2];
                classes[sa[i]] = same ? classes[sa[i - 1]] : i;
            }

            vector<long long> cnt(N), s(sa);
            rep(i, N) cnt[i] = i;
            rep(i, N) {
                long long s1 = s[i] - len;
                if (s1 >= 0) {
                    sa[cnt[classes[s1]]++] = s1;
                }
            }
        }
    }

    long long operator[] (long long k) const {
        return sa[k];
    }

    long long size() const {
        return sa.size();
    }

    bool lt_substr(const string &T, long long si = 0, long long ti = 0) {
        long long sn = S.size(), tn = T.size();
        while (si < sn and ti < tn) {
            if (S[si] < T[ti]) return true;
            if (S[si] > T[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn and ti < tn;
    }

    long long lower_bound(const string &T, long long low = -1, long long high = -1) {
        if (high == -1) high = sa.size();
        while (high - low > 1) {
            long long mid = (low + high) >> 1;
            if (lt_substr(T, sa[mid])) low = mid;
            else high = mid;
        }
        return high;
    }

    // 文字列Sの中の部分文字列Tの出現回数を求める
    // [lower_bound, upper_bound)のインデックスがTの出現回数になる
    pair<long long, long long> lower_upper_bound(string &T) {
        long long low = lower_bound(T);
        T.back()++;
        long long high = lower_bound(T, low - 1);
        T.back()--;
        return {low, high};
    }

    long long count(string &T) {
        auto [low, high] = lower_upper_bound(T);
        return high - low;
    }

    bool contains(string &T) {
        return count(T) > 0;
    }

    friend ostream &operator << (ostream &os, const SuffixArray &sa) {
        rep(i, sa.size()) {
            os << i << ": " << sa.S.substr(sa.sa[i]) << endl;
        }
        return os;
    }
};

struct LongestCommonPrefixArray {
    vector<long long> LCP, rank;

    LongestCommonPrefixArray(SuffixArray &SA) {
        build(SA);
    }

    void build(SuffixArray &SA) {
        string &s = SA.S;
        rank.resize(s.size());
        rep(i, s.size()) {
            rank[SA[i]] = i;
        }
        LCP.resize(s.size());
        LCP[0] = 0;
        for (long long i = 0, h = 0; i < (long long)s.size(); i++) {
            if (rank[i] + 1 < (long long)s.size()) {
                for (long long j = SA[rank[i] + 1]; max(i, j) + h < (long long)s.length() and s[i + h] == s[j + h]; ++h);
                LCP[rank[i] + 1] = h;
                if (h > 0) --h;
            }
        }
    }

    long long operator[] (long long k) const {
        return LCP[k];
    }

    long long size() const {
        return LCP.size();
    }

    friend ostream &operator << (ostream &os, const LongestCommonPrefixArray &lcp) {
        rep(i, lcp.size()) {
            os << i << ": " << lcp[i] << endl;
        }
        return os;
    }
};