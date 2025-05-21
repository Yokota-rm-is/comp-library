#pragma once
#include "../base.cpp"

#if __cplusplus >= 201703L
template<class S,
    auto op,
    auto e,
    class F,
    auto mapping,
    auto composition,
    auto id>
#else
template<class S,
    S (*op)(S, S),
    S (*e)(),
    class F,
    S (*mapping)(S, F),
    F (*composition)(F, F),
    F (*id)()>
#endif
struct LazySegmentTree {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>, "op must be function<S(S, S)>");
    static_assert(is_convertible_v<decltype(e), function<S()>>, "e must be function<S()>");
    static_assert(is_convertible_v<decltype(mapping), function<S(S, F)>>, "mapping must be function<S(S, F)>");
    static_assert(is_convertible_v<decltype(composition), function<F(F, F)>>, "composition must be function<F(F, F)>");
    static_assert(is_convertible_v<decltype(id), function<F()>>, "id must be function<F()>");

    static_assert(op(S(), e()) == S(), "op(S(), e()) must be S()");
    static_assert(mapping(S(), id()) == S(), "mapping(S(), id()) must be S()");
    static_assert(composition(F(), id()) == F(), "composition(F(), id()) must be F()");
#endif

    long long N, _N, height;
    vector<S> node;
    vector<F> lazy;

    LazySegmentTree(long long n) : _N(n) {
        vector<S> v(n, e());
        init(v);
    }

    LazySegmentTree(long long n, S a) : _N(n) {
        vector<S> v(n, a);
        init(v);
    }

    LazySegmentTree(vector<S> &v) : _N(v.size()) {
        init(v);
    }

    void init(vector<S> &v) {
        _N = v.size();
        height = 1;
        N = 1;

        while (N < _N) {
            N *= 2;
            height++;
        }
        
        node.resize(2 * N, e());
        lazy.resize(N, id());

        rep(i, N) {
            if (i < _N) node[i + N] = v[i];
            else node[i + N] = e();
        }
        repd(i, 1, N) update(i);
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply(long long p, F f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        node[k] = mapping(node[k], f);
        rep(i, 1, height) update(k >> i);
    }

    // 半開区間[l, r)の配列の値に対して，fでmapping
    // l, rともに0-indexed
    void apply(long long l, long long r, F f) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        long long l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) all_apply(l2++, f);
            if (r2 & 1) all_apply(--r2, f);
            l2 >>= 1;
            r2 >>= 1;
        }

        rep(i, 1, height) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    S get(long long p) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        return node[k];
    }

    // 半開区間[l, r)の配列の値を返す
    // l, rともに0-indexed
    S prod(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        repd(i, 1, height) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, node[l++]);
            if (r & 1) smr = op(node[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S prod_all() {
        return node[1];
    }

    // 左端をlに固定した場合の，g(prod(op(node[l], node[l + 1], ..., node[r - 1]))) = trueとなる最大のrを返す
    // g(node[l]) = falseの場合，lを返す (半開区間[l, l)となり，解はない)
    // l = Nの場合，Nを返す
    template <class G>
    long long max_right(long long l, G g) {
#if __cplusplus >= 201703L
        static_assert(is_convertible_v<decltype(g), function<bool(S)>>, "g must be function<bool(S)>");
#endif

        assert(0 <= l && l <= _N);
        assert(g(e()));

        if (l == _N) return _N;
        l += N;
        repd(i, 1, height) push(l >> i);
        
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;

            if (!g(op(sm, node[l]))) {
                while (l < N) {
                    push(l);

                    l *= 2;
                    if (g(op(sm, node[l]))) {
                        sm = op(sm, node[l]);
                        l++;
                    }
                }
                return l - N;
            }

            sm = op(sm, node[l]);
            l++;

        } while ((l & -l) != l);

        return _N;
    }

    // 右端をr - 1に固定した場合の，g(prod(op(node[l], node[l + 1], ..., node[r - 1]))) = trueとなる最小のlを返す
    // g(node[r - 1]) = falseの場合，rを返す (半開区間[r, r)となり，解はない)
    // r = 0の場合，0を返す
    template <class G>
    long long min_left(long long r, G g) {
#if __cplusplus >= 201703L
        static_assert(is_convertible_v<decltype(g), function<bool(S)>>, "g must be function<bool(S)>");
#endif

        assert(0 <= r && r <= _N);
        assert(g(e()));

        if (r == 0) return 0;

        r += N;
        
        repd(i, 1, height) push((r - 1) >> i);

        S sm = e();

        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            
            if (!g(op(node[r], sm))) {
                while (r < N) {
                    push(r);
                    r = (2 * r + 1);

                    if (g(op(node[r], sm))) {
                        sm = op(node[r], sm);
                        r--;
                    }
                }
                return r + 1 - N;
            }

            sm = op(node[r], sm);

        } while ((r & -r) != r);

        return 0;
    }

private:
    // k番目のノードの値を子の値で更新
    void update(long long k) {
        assert(1 <= k and k <= N - 1);

        node[k] = op(node[k * 2], node[k * 2 + 1]);
    }

    void all_apply(long long k, F f) {
        node[k] = mapping(node[k], f);
        if (k < N) lazy[k] = composition(lazy[k], f);
    }

    // k番目のノードを子に伝搬
    void push(long long k) {
        assert(1 <= k and k <= N * 2 - 1);

        all_apply(2 * k, lazy[k]);
        all_apply(2 * k + 1, lazy[k]);

        lazy[k] = id();
    }
};