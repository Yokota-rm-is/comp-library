#pragma once
#include "../base.cpp"

// 参考: https://ei1333.github.io/luzhiled/snippets/structure/convex-hull-trick-add-monotone.html
template<typename T, typename T2, bool minimize>
struct ConvexHullTrick {
    struct Line {
        T a, b;
        Line(T a, T b) : a(a), b(b) {}
    };

    deque<Line> H;

    ConvexHullTrick() {};

    bool empty() const { 
        return H.empty(); 
    }

    void clear() { 
        H.clear(); 
    }

    inline int sgn(T x) { 
        return x == 0 ? 0 : (x < 0 ? -1 : 1); 
    }

    inline bool check(const Line &l1, const Line &l2, const Line &l3) {
        if (l2.b == l1.b || l3.b == l2.b) return sgn(l2.a - l1.a) * sgn(l3.b - l2.b) >= sgn(l3.a - l2.a) * sgn(l2.b - l1.b);
        return T2(l2.a - l1.a) * (l3.b - l2.b) >= T2(l2.b - l1.b) * (l3.a - l2.a);
    }

    void add(T a, T b) {
        if (!minimize) a *= -1, b *= -1;
        Line line(a, b);
        if (empty()) {
            H.emplace_front(line);
            return;
        }

        assert(a <= H.back().a || a >= H.front().a);

        if (H.front().a <= a) {
            if (H.front().a == a) {
                if(H.front().b <= b) return;
                H.pop_front();
            }
            while (H.size() >= 2 && check(line, H.front(), H[1])) H.pop_front();
            H.emplace_front(line);
        } 
        else {
            if (H.back().a == a) {
                if(H.back().b <= b) return;
                H.pop_back();
            }
            while (H.size() >= 2 && check(H[H.size() - 2], H.back(), line)) H.pop_back();
            H.emplace_back(line);
        }
    }

    inline T get_y(const Line &line, const T &x) {
        return line.a * x + line.b;
    }

    T query(T x) {
        assert(!empty());
        int l = -1, r = H.size() - 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (get_y(H[m], x) >= get_y(H[m + 1], x)) l = m;
            else r = m;
        }
        if (minimize) return get_y(H[r], x);
        return -get_y(H[r], x);
    }

    T query_monotone_inc(T x) {
        assert(!empty());
        while (H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x)) H.pop_front();
        if (minimize) return get_y(H.front(), x);
        return -get_y(H.front(), x);
    }

    T query_monotone_dec(T x) {
        assert(!empty());
        while (H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x)) H.pop_back();
        if (minimize) return get_y(H.back(), x);
        return -get_y(H.back(), x);
    }
};