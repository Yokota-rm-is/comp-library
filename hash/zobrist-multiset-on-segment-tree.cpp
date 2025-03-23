#pragma once
#include "../base.cpp"

// 整数値 x にハッシュ値を割り当てる関数
struct CustomHash {
    using ull = unsigned long long;

    static ull splitmix64(ull x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    ull operator() (ull x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
} rng;

struct ZobristMultisetonSegmentTree {
    long long N, _N, height;
    vector<unsigned long long> node, values;

    ZobristMultisetonSegmentTree() {}
    ZobristMultisetonSegmentTree(long long n) { 
        init(n);
    }
    ZobristMultisetonSegmentTree(vector<long long> A) { 
        init(A);
    }
    ZobristMultisetonSegmentTree(vector<unsigned long long> A) { 
        init(A);
    }

    void init(long long n) {
        _N = n;
        N = 1;
        height = 1;
        while (N < (_N + 1)) {
            N *= 2;
            ++height;
        }
        
        node.assign(2 * N, 0);
        values.assign(N, 0);
    }

    void init(vector<long long> A) {
        init(A.size());

        rep(i, _N) {
            node[i + N] = rng(A[i]);
            values[i] = A[i];
        }
        repd(i, 1, N) update(i);
    }

    void init(vector<unsigned long long> A) {
        init(A.size());

        rep(i, _N) {
            node[i + N] = rng(A[i]);
            values[i] = A[i];
        }
        repd(i, 1, N) update(i);
    }

    // 位置p (0-indexed)の値をxにする
    void set(long long p, unsigned long long x) {
        assert(0 <= p and p <= _N);

        long long k = p + N;
        node[k] = rng(x);
        values[p] = x;
        rep(i, 1, height) update(k >> i);
    }

    void add(long long p, unsigned long long x) {
        assert(0 <= p and p <= _N);

        long long k = p + N;
        values[p] += x;
        node[k] = rng(values[p]);
        rep(i, 1, height) update(k >> i);
    }

    // 半開区間[l, r) (0-indexed)の総和を求める
    unsigned long long prod(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        unsigned long long prod_l = 0, prod_r = 0;
        while (l < r) {
            if (l & 1) prod_l = prod_l + node[l++];
            if (r & 1) prod_r = node[--r] + prod_r;
            l >>= 1;
            r >>= 1;
        }

        return prod_l + prod_r;
    }

private:
    void update(long long k) {
        assert(1 <= k and k <= N - 1);

        node[k] = node[k * 2] + node[k * 2 + 1];
    }
};