#pragma once
#include "../base.cpp"

constexpr long long bit_ceil_log(unsigned long long n) {
    long long x = 0;
    while ((1ull << x) < (unsigned long long)(n)) x++;
    return x;
}

// T : 2 * (最大値) * (要素数)^2 が収まる型
template <typename T, auto e, int coeff = 1>
struct LinearAddRangeMin {
    struct Point {
        long long x;
        T y;

        static T cross(const Point &a, const Point &b, const Point &c) {
            return (b.y - a.y) * (c.x - a.x) - (c.y - a.y) * (b.x - a.x);
        }
    };

    struct Node {
        Point lbr, rbr;
        T lza, lzb;
        // 葉
        Node(long long x, T y): lbr{x, y}, rbr{x, y}, lza(0), lzb(0){}
        // 葉以外
        Node(): lza(0), lzb(0){}
    };

    LinearAddRangeMin(long long n) : _N(n) {
        init(vector<T>(_N));
    }

    LinearAddRangeMin(long long n, T a) : _N(n) {
        init(vector<T>(_N, a));
    }

    LinearAddRangeMin(vector<T> v) : _N(v.size()) {
        init(v);
    }

    void init(vector<T> v) {
        N = bit_ceil((unsigned long long)(_N));
        log = bit_ceil_log((unsigned long long)N) + 1;
        node = vector<Node>(2 * N);
        rep(i, N) node[N + i] = Node(i, (i < _N ? coeff * v[i] : coeff * e()));
        repd(i, 1, N) pull(i);
    }

    void set(long long p, T x) {
        assert(0 <= p && p < _N);
        long long P = p;
        p += N;
        x *= coeff;

        repd(i, 1, log) push(p >> i);
        if(node[p].lbr.y == x) return;

        bool is_decrease = node[p].lbr.y > x;
        node[p] = Node(P, x);
        // node[p]の値が増加した場合、元々の橋がpだった場合のみpull
        //           減少した場合、常にpull
        rep(i, 1, log) {
            if (is_decrease or node[p >> i].lbr.x == P or node[p >> i].rbr.x == P) {
                pull(p >> i);
            }
        }
    }

    T get(long long p) const {
        assert(0 <= p && p < _N);
        p += N;

        T a = 0, b = 0;
        repd(i, 1, log) a += node[p >> i].lza, b += node[p >> i].lzb;
        return coeff * (node[p].lbr.y + (p - N) * a + b);
    }

    T prod() {
        return coeff * min_subtree(1);
    }

    // [l, r)のmin
    T prod(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);
        if (l == r) return e();

        l += N;
        r += N;

        repd(i, 1, log) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        T res = coeff * e();
        while (l < r) {
            if (l & 1) res = min(res, min_subtree(l++));
            if (r & 1) res = min(res, min_subtree(--r));
            l >>= 1;
            r >>= 1;
        }

        return coeff * res;
    }

    T prod_assume_apply(T a, T b) {
        return prod_assume_apply(0, N, a, b);
    }

    // [l, r)にax+bを足したと仮定してのmin
    T prod_assume_apply(long long l, long long r, T a, T b) {
        if (l == r) return coeff * e();

        l += N;
        r += N;
        a *= coeff;
        b *= coeff;

        repd(i, 1, log) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        T res = coeff * e();
        while (l < r) {
            if (l & 1) res = min(res, min_subtree(l++, a, b));
            if (r & 1) res = min(res, min_subtree(--r, a, b));
            l >>= 1;
            r >>= 1;
        }

        return coeff * res;
    }

    // 全体にai+b (i=0, 1, ..., N-1)を加える
    void apply(T a, T b) {
        apply(0, N, a, b);
    }

    // [l, r)にai+b (i=l, l+1, ..., r-1)を加える
    void apply(long long l, long long r, T a, T b) {
        // assert(0 <= l && l <= r && r <= _N);
        if (l == r) return;

        l += N;
        r += N;
        a *= coeff;
        b *= coeff;
        
        long long l2 = l, r2 = r;
        while (l < r) {
            if (l & 1) all_apply(l++, a, b);
            if (r & 1) all_apply(--r, a, b);
            l >>= 1;
            r >>= 1;
        }
        l = l2;
        r = r2;
        
        bool upper_lca = false;
        rep(i, 1, log) {
            upper_lca |= (l >> i) == ((r - 1) >> i);
            if (((l >> i) << i) != l) pull(l >> i);
            if (!upper_lca && ((r >> i) << i) != r) pull((r - 1) >> i);
        }
    }

    // [l, r)に初項al, 公差dの等差数列を足す
    void apply_al(long long l, long long r, T al, T d) {
        T a = d;
        T b = al - d * l;
        apply(l, r, a, b);
    }

    // [l, r)に末項ar, 公差dの等差数列を足す
    void apply_ar(long long l, long long r, T ar, T d) {
        T a = d;
        T b = ar - d * (r - 1);
        apply(l, r, a, b);
    }

    // [l, r)に初項al, 公差dの等差数列を足すと仮定してのmin
    T prod_assume_apply_al(long long l, long long r, T al, T d) {
        T a = d;
        T b = al - d * l;
        return prod_assume_apply(l, r, a, b);
    }

    // [l, r)に末項ar, 公差dの等差数列を足すと仮定してのmin
    T prod_assume_apply_ar(long long l, long long r, T ar, T d) {
        T a = d;
        T b = ar - d * (r - 1);
        return prod_assume_apply(l, r, a, b);
    }

    friend ostream& operator<<(ostream& os, const LinearAddRangeMin& seg) {
        os << "[";
        rep(i, seg._N) {
            if (i) os << ", ";
            os << seg.get(i);
        }
        return os << "]";
    }

private:
    long long _N, N, log;
    vector<Node> node;

    void all_apply(long long k, T a, T b) {
        node[k].lbr.y += a * node[k].lbr.x + b;
        node[k].rbr.y += a * node[k].rbr.x + b;
        if (k < N) node[k].lza += a, node[k].lzb += b;
    }

    void push(long long k) {
        all_apply(2 * k, node[k].lza, node[k].lzb);
        all_apply(2 * k + 1, node[k].lza, node[k].lzb);
        node[k].lza = node[k].lzb = 0;
    }

    long long leftmost(long long k) {
        long long msb = 31 - __builtin_clz(k);
        return (k - (1 << msb)) << (log - 1 - msb);
    }

    void pull(long long k) {
        assert(k < N);
        long long l = k * 2, r = k * 2 + 1;
        long long splitx = leftmost(r);
        push(k);
        T lza = 0, lzb = 0, lzA = 0, lzB = 0;
        Point a = node[l].lbr, b = node[l].rbr, c = node[r].lbr, d = node[r].rbr;

        #define movel(f){\
            lza += node[l].lza, lzb += node[l].lzb;\
            l = l * 2 + f;\
            a = node[l].lbr, b = node[l].rbr;\
            a.y += lza * a.x + lzb;\
            b.y += lza * b.x + lzb;\
        }
        #define mover(f){\
            lzA += node[r].lza, lzB += node[r].lzb;\
            r = r * 2 + f;\
            c = node[r].lbr, d = node[r].rbr;\
            c.y += lzA * c.x + lzB;\
            d.y += lzA * d.x + lzB;\
        }
        while ((l < N) || (r < N)) {
            T s1 = Point::cross(a, b, c);
            if (l < N && s1 > 0) {
                movel(0);
            } 
            else if (r < N && Point::cross(b, c, d) > 0) {
                mover(1);
            } 
            else if (l >= N) {
                mover(0);
            } 
            else if (r >= N) {
                movel(1);
            } 
            else {
                T s2 = Point::cross(b, a, d);
                if (s1 + s2 == 0 || s1 * (d.x - splitx) < s2 * (splitx - c.x)) {
                    movel(1);
                } else {
                    mover(0);
                }
            }
        }
        node[k].lbr = a;
        node[k].rbr = c;
        #undef movel
        #undef mover
    }

    T min_subtree(long long k, T a = 0, T b = 0) {
        while (k < N) {
            bool f = (node[k].lbr.y - node[k].rbr.y) > a * (node[k].rbr.x - node[k].lbr.x);
            a += node[k].lza;
            b += node[k].lzb;
            k = k * 2 + f;
        }
        return node[k].lbr.y + a * node[k].lbr.x + b;
    }
};

template <typename T, auto e>
using LinearAddRangeMax = LinearAddRangeMin<T, e, -1>;