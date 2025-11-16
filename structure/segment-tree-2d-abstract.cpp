#pragma once
#include "../base.cpp"

#if __cplusplus >= 201703L
template<class S, 
    auto op,
    auto e,
    class F,
    auto mapping>
#else
template<class S,
    S (*op)(S, S),
    S (*e)(),
    class F,
    S (*mapping)(S, F)>
#endif
struct SegmentTree2D {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>, "op must be function<S(S, S)>");
    static_assert(is_convertible_v<decltype(e), function<S()>>, "e must be function<S()>");
    static_assert(is_convertible_v<decltype(mapping), function<S(S, F)>>, "mapping must be function<S(S, F)>");

    static_assert(op(S(), e()) == S(), "op(S(), e()) must be S()");
#endif

    long long H, _H, W, _W;
    vector<S> node;

    SegmentTree2D(long long h, long long w) : _H(h), _W(w) {
        init();
        build(vector<vector<S>>(h, vector<S>(w, e())));
    }

    SegmentTree2D(long long h, long long w, S a) : _H(h), _W(w) {
        init();
        build(vector<vector<S>>(h, vector<S>(w, a)));
    }

    SegmentTree2D(vector<vector<S>>& v) : _H(v.size()), _W(v[0].size()) {
        init();
        build(v);
    }

    void init() {
        H = 1, W = 1;
        while (H < (_H + 1)) {
            H *= 2;
        }

        while (W < (_W + 1)) {
            W *= 2;
        }

        node.assign(4 * H * W, e());
    }

    void build(vector<vector<S>>& v) {
        assert(v.size() == _H and v[0].size() == _W);

        rep(i, _H) {
            rep(j, _W) {
                node[id(H + i, W + j)] = v[i][j];
            }
        }

        rep(j, W, 2 * W) {
            repd(i, H) {
                node[id(i, j)] = op(node[id(i * 2, j)], node[id(i * 2 + 1, j)]);
            }
        }

        rep(i, 2 * H) {
            repd(j, W) {
                node[id(i, j)] = op(node[id(i, j * 2)], node[id(i, j * 2 + 1)]);
            }
        }
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply(long long y, long long x, F f) {
        assert(0 <= y and y < _H and 0 <= x and x < _W);

        mapping(node[id(y + H, x + W)], f);
        update(y, x);
    }

    S get(long long y, long long x) {
        assert(0 <= y and y < _H and 0 <= x and x < _W);

        return node[id(y + H, x + W)];
    }

    // 半開区間[h1, h2) x [w1, w2)の配列の値を返す
    // l, rともに0-indexed
    S prod(long long h1, long long h2, long long w1, long long w2) {
        assert(0 <= h1 and h1 <= h2 and h2 <= _H and 0 <= w1 and w1 <= w2 and w2 <= _W);

        h1 += H, h2 += H, w1 += W, w2 += W;
        S smu = e(), smd = e();
        for (ll u = h1, d = h2; u < d; u >>= 1, d >>= 1) {
            if (u & 1) smu = op(smu, prod(u++, w1, w2));
            if (d & 1) smd = op(prod(--d, w1, w2), smd);
        }

        return op(smu, smd);
    }

    S prod(long long h, long long w) {
        return prod(0, h, 0, w);
    }

    friend ostream& operator << (ostream& os, SegmentTree2D& seg) {
        rep(i, seg._H) {
            rep(j, seg._W) {
                os << seg.get(i, j) << " ";
            }
            os << endl;
        }

        return os;
    }

private:
    long long id(long long y, long long x) {
        return y * 2 * W + x;
    }

    // (y, x)のノードの値を子の値で更新
    void update(long long y, long long x) {
        y += H, x += W;

        for (long long i = y >> 1; i > 0; i >>= 1) {
            node[id(i, x)] = op(node[id(i * 2, x)], node[id(i * 2 + 1, x)]);
        }

        for (long long i = y; i > 0; i >>= 1) {
            for (long long j = x >> 1; j > 0; j >>= 1) {
                node[id(i, j)] = op(node[id(i, j * 2)], node[id(i, j * 2 + 1)]);
            }
        }
    }

    S prod(long long i, long long j1, long long j2) {
        S sml = e(), smr = e();
        for (long long l = j1, r = j2; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sml = op(sml, node[id(i, l++)]);
            if (r & 1) smr = op(node[id(i, --r)], smr);
        }

        return op(sml, smr);
    }
};