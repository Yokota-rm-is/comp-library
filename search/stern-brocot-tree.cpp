#pragma once
#include "../base.cpp"

// 参考: https://miscalc.hatenablog.com/entry/2023/12/22/213007
template <typename T = long long>
struct SternBrocotTree {
    tuple<T, T, T, T> child(T d, T p, T q, T r, T s, bool isleft) {
        if (isleft) return {p, q, r + d * p, s + d * q};
        else return {p + d * r, q + d * s, r, s};
    }

    tuple<T, T, T, T> parent(T p, T q, T r, T s) {
        if (p == 0 and q == 1 and r == 1 and s == 0) return {0, 0, 0, 0};
        
        if (p < r or q < s) return {p, q, r - p, s - q};
        else return {p - r, q - s, r, s};
    }

    vector<T> encode_path(T p, T q) {
        vector<T> a;
        if (p < q) {
            a.emplace_back(0);
            swap(p, q);
        }

        while (p != 1) {
            a.emplace_back(p / q);
            p %= q;
            swap(p, q);
        }

        if (!a.empty()) {
            if (a.back() == 1) a.pop_back();
            else a.back()--;
        }

        return a;
    }

    tuple<T, T, T, T> decode_path(const vector<T>& a) {
        T p = 0, q = 1, r = 1, s = 0;

        rep(i, a.size()) {
            tie(p, q, r, s) = child(a[i], p, q, r, s, i & 1);
        }

        return {p, q, r, s};
    }

    tuple<T, T, T, T> lca(T p, T q, T r, T s) {
        vector<T> a = encode_path(p, q), b = encode_path(r, s);
        int n = min(a.size(), b.size());
        T f = 0, g = 1, h = 1, k = 0;

        rep(i, n) {
            T c = min(a[i], b[i]);
            
            tie(f, g, h, k) = child(c, f, g, h, k, i & 1);
            if (a[i] != b[i]) break;
        }

        return {f, g, h, k};
    }

    tuple<T, T, T, T> ancestor(T d, T p, T q) {
        vector<T> a = encode_path(p, q);
        T f = 0, g = 1, h = 1, k = 0;

        rep(i, a.size()) {
            T c = min(d, a[i]);
            tie(f, g, h, k) = child(c, f, g, h, k, i & 1);

            d -= c;
            if (d == 0) break;
        }

        if (d == 0) return {f, g, h, k};
        else return {0, 0, 0, 0};
    }

    tuple<T, T, T, T> range(T p, T q) {
        return decode_path(encode_path(p, q));
    }

    bool is_all_true(const function<bool(T, T)> &is_ok, const T max_value) {
        return is_ok(0, 1) and is_ok(max_value, 1);
    }

    bool is_all_false(const function<bool(T, T)> &is_ok, const T max_value) {
        return !is_ok(0, 1) and !is_ok(max_value, 1);
    }

    // 条件を満たす分数を二分探索で探す
    // is_ok: 条件判定関数 (オーバーフローに注意，必要に応じて__int128_tやint_256_tを使う)
    // max_value: 探索範囲の最大値 (is_ok内の計算でオーバーフローしないように注意)
    // 戻り値: {ok_p, ok_q, ng_p, ng_q} (ok_p/ok_q: 条件を満たす分数，ng_p/ng_q: 条件を満たさない分数)
    tuple<T, T, T, T> search(const function<bool(T, T)> &is_ok, const T max_value) {
        const bool judge_01 = is_ok(0, 1);    // 左端の判定結果
        const bool judge_10 = is_ok(max_value, 1);   // 右端の判定結果
        assert(judge_01 != judge_10);
        
        T p = 0, q = 1, r = 1, s = 0;
        // 探索開始
        while (p + r <= max_value && q + s <= max_value) {
            // 中間点を計算: 新しい候補 (mid_p/mid_q)
            T mid_p = p + r;
            T mid_q = q + s;

            // 中間点の条件判定
            const bool judge_now = is_ok(mid_p, mid_q);
            const bool isleft = judge_now ^ judge_01;

            // 最大ステップ数を計算
            // 分子・分母が max_value を超えない範囲で進む
            T maxd;
            if (isleft) {
                if (p == 0) maxd = (max_value - s) / q;
                else maxd = min((max_value - r) / p, (max_value - s) / q);
            }
            else {
                if (s == 0) maxd = (max_value - p) / r;
                else maxd = min((max_value - q) / s, (max_value - p) / r);
            }

            // 倍倍探索 + 二分探索で進む距離を決定
            T dl = 1, dr = 2;
            while (dr <= maxd) {
                // 候補ノードを計算
                auto [np, nq, nr, ns] = child(dr, p, q, r, s, isleft);
                if (is_ok(np + nr, nq + ns) != judge_now) break;    // 条件が変わる場合、探索終了

                dl = dr;
                dr = min(2 * dr, maxd + 1); // 探索範囲を広げる
            }

            while (dr - dl > 1) {
                // 二分探索で正確な距離を決定
                T dm = dl + (dr - dl) / 2;
                auto [np, nq, nr, ns] = child(dm, p, q, r, s, isleft);

                if (is_ok(np + nr, nq + ns) == judge_now) dl = dm;
                else dr = dm;
            }

            // 子ノードに進む
            tie(p, q, r, s) = child(dl, p, q, r, s, isleft);
        }

        // 最終的な分数ペアを返す
        // p/q: 条件を満たす分数，r/s: 条件を満たさない分数
        if (is_ok(r, s)) {
            swap(p, r);
            swap(q, s);
        }

        return {p, q, r, s};
    }
};
