#pragma once
#include "../base.cpp"

template<typename T>
struct Node {
    T sum, min, max;
    long long index_min, index_max;
    long long left, right;

    Node(T s, T m, T M, long long i_min = -1, long long i_max = -1, long long l = -1, long long r = -1) : sum(s), min(m), max(M), index_min(i_min), index_max(i_max), left(l), right(r) {
    };

    Node(array<T, 3> a, long long i_min = -1, long long i_max = -1, long long l = -1, long long r = -1) : sum(a[0]), min(a[1]), max(a[2]), index_min(i_min), index_max(i_max), left(l), right(r) {
    };

    bool operator== (array<T, 3> a) {
        return (sum == a[0] and min == a[1] and max == a[2]);
    }

    friend ostream& operator << (ostream &os, const Node<T>& node) {
        return os << "(" << node.sum << ", " << node.min << ", " << node.max << ")";
    }
};

template<typename T>
struct Operation {
    using S = Node<T>;

    Operation(): _e({T(0), numeric_limits<T>::max(), numeric_limits<T>::min()}) {};

    array<T, 3> e() {
        return _e;
    }

    S operator() (const S& x, const S& y) {
        T s = x.sum + y.sum;
        T m = min(x.min, y.min);
        T M = max(x.max, y.max);
        long long index_min = (y.min < x.min ? y.index_min : x.index_min);
        long long index_max = (y.max > x.max ? y.index_max : x.index_max);
        long long left = (x.left != -1 ? x.left : y.left);
        long long right = (y.right != -1 ? y.right : x.right);

        S ret(s, m, M, index_min, index_max, left, right);

        return ret;
    }

private:
    array<T, 3> _e;
};

template<typename T, typename F2>
struct Mapping {
    using S = Node<T>;
    using F = pair<F2, F2>;

    Mapping(): _id(numeric_limits<F2>::max(), numeric_limits<F2>::max()) {};

    F id() {
        return _id;
    }

    void operator() (S &x, const F f) {
        if (f == id()) return;

        x.sum = (f.first * (x.left + x.right - 1) + f.second * 2) * (x.right - x.left) / 2;
        x.min = f.first * x.left + f.second;
        x.max = f.first * (x.right - 1) + f.second;
        x.index_min = x.left;
        x.index_max = x.right - 1;

        if (f.first < 0) {
            swap(x.min, x.max);
            swap(x.index_min, x.index_max);
        }
    }

    void composition(F &f, const F s) {
        if (f == id()) {
            f = s;
            return;
        }
        if (s == id()) return;

        f = s;
    }

private:
    F _id;
};

template<typename T, typename F2>
struct LazySegmentTree {
    using S = Node<T>;
    using F = pair<F2, F2>;

    long long N, _N, height;

    vector<S> node;
    vector<F> lazy;
    Operation<T> op;
    Mapping<T, F2> mapping;

    LazySegmentTree(long long n, T a) : _N(n), op(), mapping() {
        vector<T> v(n, a);
        init(v);
    }

    LazySegmentTree(vector<T> &v) : _N(v.size()), op(), mapping() {
        init(v);
    }

    void init(vector<T> &v) {
        _N = v.size();
        height = 1;
        N = 1;

        while (N < _N) {
            N *= 2;
            height++;
        }
        
        node.resize(2 * N, S(op.e()));
        lazy.resize(N, mapping.id());

        rep(i, N) {
            if (i < _N) node[i + N] = S(v[i], v[i], v[i], i, i, i, i + 1);
            else node[i + N] = S(op.e());
        }
        repd(i, 1, N) update(i);
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply(long long p, F f) {
        assert(0 <= p and p < _N);

        f.second -= f.first * p;

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        mapping(node[k], f);
        rep(i, 1, height) update(k >> i);
    }

    // 半開区間[l, r)の配列の値に対して，fでmapping
    // l, rともに0-indexed
    void apply(long long l, long long r, F f) {
        assert(0 <= l && l <= r && r <= _N);

        f.second -= f.first * l;

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

        S sml(op.e()), smr(op.e());
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
        assert(0 <= l && l <= _N);
        assert(g(S(op.e())));

        if (l == _N) return _N;
        l += N;
        repd(i, 1, height) push(l >> i);
        
        S sm(op.e());
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
        assert(0 <= r && r <= _N);
        assert(g(S(op.e())));

        if (r == 0) return 0;

        r += N;
        
        repd(i, 1, height) push((r - 1) >> i);

        S sm(op.e());

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

    friend ostream& operator << (ostream& os, LazySegmentTree& seg) {
        os << "node" << endl;
        long long h = 1;
        rep(i, 1, seg.node.size()) {
            if (seg.node[i] == seg.op.e()) os << "e ";
            else os << seg.node[i] << " ";

            if (i == (1 << h) - 1) {
                os << endl;
                h++;
            }
        }

        os << "lazy" << endl;
        h = 1;
        rep(i, 1, seg.N) {
            if (seg.lazy[i] == seg.mapping.id()) os << "id ";
            else os << seg.lazy[i] << " ";
            if (i == (1 << h) - 1) {
                os << endl;
                h++;
            }
        }

        os << "value" << endl;
        rep(i, seg._N) {
            os << seg.get(i) << " ";
        }
        os << endl;

        return os;
    }

private:
    // k番目のノードの値を子の値で更新
    void update(long long k) {
        assert(1 <= k and k <= N - 1);

        node[k] = op(node[k * 2], node[k * 2 + 1]);
    }

    void all_apply(long long k, F f) {
        mapping(node[k], f);
        if (k < N) mapping.composition(lazy[k], f);
    }

    // k番目のノードを子に伝搬
    void push(long long k) {
        assert(1 <= k and k <= N * 2 - 1);

        all_apply(2 * k, lazy[k]);
        all_apply(2 * k + 1, lazy[k]);

        lazy[k] = mapping.id();
    }
};