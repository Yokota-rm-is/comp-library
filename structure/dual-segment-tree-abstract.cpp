#pragma once
#include "../base.cpp"


#if __cplusplus >= 201703L
template<class S,
    class F,
    auto mapping,
    auto composition,
    auto id>
#else
template<class S,
    class F,
    void (*mapping)(S&, F),
    void (*composition)(F&, F),
    F (*id)()>
#endif
struct DualSegmentTree {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(mapping), function<S(S, F)>>, "mapping must be function<S(S, F)>");
    static_assert(is_convertible_v<decltype(composition), function<void(F&, F)>>, "composition must be function<F(F, F)>");
    static_assert(is_convertible_v<decltype(id), function<F()>>, "id must be function<F()>");
#endif
    long long N, _N, height;

    vector<S> value;
    vector<F> node;

    DualSegmentTree(ll n) : _N(n) {
        value(n, id());
        init();
    }

    DualSegmentTree(ll n, S a) : _N(n), value(n, a) {
        init();
    }

    DualSegmentTree(vector<S> &A) : _N(A.size()), value(A) {
        init();
    }

    void init() {
        _N = value.size();
        height = 1;
        N = 1;

        while (N < _N) {
            N *= 2;
            height++;
        }
        
        node.resize(N * 2, F(id()));
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply(long long p, F f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        composition(node[k], f);
    }

    // 半開区間[l, r)の配列の値に対して，fでmapping
    // l, rともに0-indexed
    void apply(long long l, long long r, F f) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        while (l < r) {
            if (l & 1) composition(node[l++], f);
            if (r & 1) composition(node[--r], f);
            l >>= 1;
            r >>= 1;
        }
    }

    S get(long long p) {
        assert(0 <= p and p < _N);

        long long k = p + N;

        S ret = value[p];
        repd(i, height) ret = mapping(ret, node[k >> i]);
        return ret;
    }

    S get(long long p, auto mapping_i) {
#if __cplusplus >= 201703L
        static_assert(is_convertible_v<decltype(mapping_i), function<S(S, F)>>, "mapping must be function<S(S, F)>");
#endif

        assert(0 <= p and p < _N);

        long long k = p + N;

        S ret = value[p];
        repd(i, height) ret = mapping_i(ret, node[k >> i]);
        return ret;
    }

    friend ostream& operator << (ostream& os, DualSegmentTree& seg) {
        os << "values" << endl;
        rep(i, seg._N) {
            os << seg.value[i] << " ";
        }
        os << endl;

        os << "node" << endl;
        ll h = 1;
        rep(i, 1, seg.node.size()) {
            if (seg.node[i].value == seg.mapping.id()) os << "id ";
            else os << seg.node[i] << " ";

            if (i == (1 << h) - 1) {
                os << endl;
                h++;
            }
        }
        os << endl;

        os << "value" << endl;
        rep(i, seg._N) {
            os << seg.get(i) << " ";
        }
        os << endl;

        return os;
    }
};