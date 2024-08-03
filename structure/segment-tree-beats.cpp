#pragma once
#include "../base.cpp"

// Segment Tree Beats (下記URLの実装を一部改変)
// https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_2.html
// - l<=i<r について、 A_i の値を min(A_i, x) に更新
// - l<=i<r について、 A_i の値を max(A_i, x) に更新
// - l<=i<r の中の A_i の最大値を求める
// - l<=i<r の中の A_i の最小値を求める
// - l<=i<r の A_i の和を求める
// - l<=i<r について、 A_i の値に x を加える
// - l<=i<r について、 A_i の値を x に更新

template<typename T>
class SegmentTreeBeats {
    const T inf = 1e18;
    int n, n0;

    vector<T> max_v, smax_v, max_c;
    vector<T> min_v, smin_v, min_c;
    vector<T> sum;
    vll len;
    vector<T> ladd, lval;

    void update_node_max(int k, T x) {
        sum[k] += (x - max_v[k]) * max_c[k];

        if (max_v[k] == min_v[k]) { 
            max_v[k] = min_v[k] = x;
        } 
        else if (max_v[k] == smin_v[k]) {
            max_v[k] = smin_v[k] = x;
        } 
        else {
            max_v[k] = x;
        }

        if (lval[k] != inf && x < lval[k]) {
            lval[k] = x;
        }
    }

    void update_node_min(int k, T x) {
        sum[k] += (x - min_v[k]) * min_c[k];

        if (max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } 
        else if (smax_v[k] == min_v[k]) {
            min_v[k] = smax_v[k] = x;
        } 
        else {
            min_v[k] = x;
        }

        if (lval[k] != inf && lval[k] < x) {
            lval[k] = x;
        }
    }

    void push(int k) {
        if (n0 - 1 <= k) return;

        if (lval[k] != inf) {
            updateall(2 * k + 1, lval[k]);
            updateall(2 * k + 2, lval[k]);
            lval[k] = inf;
            return;
        }

        if (ladd[k] != 0) {
            addall(2 * k + 1, ladd[k]);
            addall(2 * k + 2, ladd[k]);
            ladd[k] = 0;
        }

        if (max_v[k] < max_v[2 * k + 1]) {
            update_node_max(2 * k + 1, max_v[k]);
        }
        if (min_v[2 * k + 1] < min_v[k]) {
            update_node_min(2 * k + 1, min_v[k]);
        }

        if (max_v[k] < max_v[2 * k + 2]) {
            update_node_max(2 * k + 2, max_v[k]);
        }
        if (min_v[2 * k + 2] < min_v[k]) {
            update_node_min(2 * k + 2, min_v[k]);
        }
    }

    void update(int k) {
        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];

        if (max_v[2 * k + 1] < max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 2];
            max_c[k] = max_c[2 * k + 2];
            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);
        } 
        else if (max_v[2 * k + 1] > max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1];
            smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);
        } 
        else {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];
            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);
        }

        if (min_v[2 * k + 1] < min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1];
            smin_v[k] = min(smin_v[2 * k + 1], min_v[2 * k + 2]);
        } 
        else if (min_v[2 * k + 1] > min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 2];
            min_c[k] = min_c[2 * k + 2];
            smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);
        } 
        else {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];
            smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);
        }
    }

    void _apply_chmin(T x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a || max_v[k] <= x) {
            return;
        }
        if (a <= l && r <= b && smax_v[k] < x) {
            update_node_max(k, x);
            return;
        }

        push(k);
        _apply_chmin(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _apply_chmin(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

      void _apply_chmax(T x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a || x <= min_v[k]) {
            return;
        }
        if (a <= l && r <= b && x < smin_v[k]) {
            update_node_min(k, x);
            return;
        }

        push(k);
        _apply_chmax(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _apply_chmax(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void addall(int k, T x) {
        max_v[k] += x;
        if (smax_v[k] != -inf) smax_v[k] += x;
        min_v[k] += x;
        if (smin_v[k] != inf) smin_v[k] += x;

        sum[k] += len[k] * x;
        if (lval[k] != inf) {
            lval[k] += x;
        } 
        else {
            ladd[k] += x;
        }
    }

    void updateall(int k, T x) {
        max_v[k] = x;
        smax_v[k] = -inf;
        min_v[k] = x;
        smin_v[k] = inf;
        max_c[k] = min_c[k] = len[k];

        sum[k] = x * len[k];
        lval[k] = x;
        ladd[k] = 0;
    }

    void _apply_add(T x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            addall(k, x);
            return;
        }

        push(k);
        _apply_add(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _apply_add(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _apply_set(T x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            updateall(k, x);
            return;
        }

        push(k);
        _apply_set(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _apply_set(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    T _prod_max(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) {
            return -inf;
        }
        if (a <= l && r <= b) {
            return max_v[k];
        }
        push(k);
        T lv = _prod_max(a, b, 2 * k + 1, l, (l + r) / 2);
        T rv = _prod_max(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(lv, rv);
    }

    T _prod_min(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) {
            return inf;
        }
        if (a <= l && r <= b) {
            return min_v[k];
        }
        push(k);
        T lv = _prod_min(a, b, 2 * k + 1, l, (l + r) / 2);
        T rv = _prod_min(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(lv, rv);
    }

    T _prod_sum(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) {
            return 0;
        }
        if (a <= l && r <= b) {
            return sum[k];
        }
        push(k);
        ll lv = _prod_sum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _prod_sum(a, b, 2 * k + 2, (l + r) / 2, r);
        return lv + rv;
    }

public:
    SegmentTreeBeats(int n) { 
        vector<T> A(n, 0);
        init(n, A);
    }

    SegmentTreeBeats(int n, T a) {
        vector<T> A(n, a);
        init(n, A);
    }

    SegmentTreeBeats(vector<T> &A) : n(A.size()) {
        init(n, A);
    }

    void init(int n, vector<T> &A) {
        max_v.resize(4 * n);
        smax_v.resize(4 * n);
        max_c.resize(4 * n);
        min_v.resize(4 * n);
        smin_v.resize(4 * n);
        min_c.resize(4 * n);
        sum.resize(4 * n);
        len.resize(4 * n);
        ladd.resize(4 * n);
        lval.resize(4 * n);

        n0 = 1;
        while (n0 < n) n0 <<= 1;

        for (int i = 0; i < 2 * n0; ++i) ladd[i] = 0, lval[i] = inf;
        len[0] = n0;
        for (int i = 0; i < n0 - 1; ++i) len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);

        for (int i = 0; i < n; ++i) {
            max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = A[i];
            smax_v[n0 - 1 + i] = -inf;
            smin_v[n0 - 1 + i] = inf;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;
        }

        for (int i = n; i < n0; ++i) {
            max_v[n0 - 1 + i] = smax_v[n0 - 1 + i] = -inf;
            min_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = inf;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;
        }
        for (int i = n0 - 2; i >= 0; i--) {
            update(i);
        }
    }

    // range minimize query
    void apply_chmin(long long l, long long r, T x) {
         _apply_chmin(x, l, r, 0, 0, n0); 
    }

    void apply_chmin(int p, T x) {
        apply_chmin(p, p + 1, x);
    }

    // range maximize query
    void apply_chmax(long long l, long long r, T x) { 
        _apply_chmax(x, l, r, 0, 0, n0); 
    }

    void apply_chmax(int p, T x) {
        apply_chmax(p, p + 1, x);
    }

    // range add query
    void apply_add(long long l, long long r, T x) { 
        _apply_add(x, l, r, 0, 0, n0); 
    }

    void apply_add(int p, T x) {
        apply_add(p, p + 1, x);
    }

    // range update query
    void apply_set(long long l, long long r, T x) {
        _apply_set(x, l, r, 0, 0, n0); 
    }

    void apply_set(int p, T x) {
        apply_set(p, p + 1, x);
    }

    // range maximum query
    T prod_max(long long l, long long r) { 
        return _prod_max(l, r, 0, 0, n0); 
    }

    // range minimum query
    T prod_min(long long l, long long r) { 
        return _prod_min(l, r, 0, 0, n0); 
    }

    // range sum query
    T prod_sum(long long l, long long r) { 
        return _prod_sum(l, r, 0, 0, n0);
    }

    T get(int p) {
        return prod_sum(p, p + 1);
    }
};