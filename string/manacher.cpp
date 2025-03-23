#pragma once
#include "../base.cpp"

template <char dummy = '#'>
struct Manacher {
    string S;
    vector<long long> rad;

    long long longest_palindrome_odd_idx, longest_palindrome_even_idx, longest_palindrome_idx, longest_palindrome_len;

    bool built = false;
    
    Manacher(const string& s) : S(2 * s.size() + 1, dummy) {
        rep(i, s.size()) {
            S[2 * i + 1] = s[i];
        }

        build();
    }

    long long build() {
        long long N = S.size();
        rad.assign(N, 0);
        long long c = 0, r = 0;

        while (c < N) {
            while (0 <= c - r and c + r < N and S[c - r] == S[c + r]) r++;
            rad[c] = r;

            long long k = 1;
            while (0 <= c - k and k + rad[c - k] < r) {
                rad[c + k] = rad[c - k];
                k++;
            }

            c += k;
            r -= k;
        }

        rep(i, N) rad[i] /= 2;

        long long longest_palindrome_odd_len = 0, longest_palindrome_even_len = 0;
        rep(i, N) {
            if (i % 2 == 0 and chmax(longest_palindrome_even_len, rad[i])) longest_palindrome_even_idx = i;
            if (i % 2 == 1 and chmax(longest_palindrome_odd_len, rad[i])) longest_palindrome_odd_idx = i;
            if (chmax(longest_palindrome_len, rad[i])) longest_palindrome_idx = i;
        }

        built = true;

        return longest_palindrome_len;
    }

    long long get_longest_palindrome_len() {
        assert(built);
        return longest_palindrome_len;
    }

    string get_longest_palindrome() {
        assert(built);
        long long left = longest_palindrome_idx - rad[longest_palindrome_idx] + 1;
        long long right = longest_palindrome_idx + rad[longest_palindrome_idx];

        string ret;
        rep(i, left, right, 2) ret += S[i];
        return ret;
    }

    // i番目を中心とする奇回文の半径を返す
    long long get_radius_odd(long long i) {
        assert(built);
        assert(0 <= i and i < S.size());
        return rad[i * 2 + 1];
    }

    // i番目を中心とする奇回文の長さを返す
    long long get_palindrome_odd_len(long long i) {
        assert(built);
        assert(0 <= i and i < S.size());
        return rad[i * 2 + 1] * 2 - 1;
    }

    // i, i+1番目を中心とする偶回文の半径を返す
    long long get_radius_even(long long i) {
        assert(built);
        assert(0 <= i and i < S.size());
        return rad[i * 2 + 2];
    }

    // i, i+1番目を中心とする偶回文の長さを返す
    long long get_palindrome_even_len(long long i) {
        assert(built);
        assert(0 <= i and i < S.size());
        return rad[i * 2 + 2] * 2;
    }

    // [l, r)が回文かどうかを返す
    bool is_palindrome(long long l, long long r) {
        assert(built);
        assert(0 <= l and l <= r and r < S.size());
        return rad[l + r] >= (r - l + 1) / 2;
    }
};