#pragma once
#include "../base.cpp"

// verify
// RUQ: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=8936932#1
// RAQ: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=8936951#1
// RMQ and RUQ: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=8936958#1
// RSQ and RAQ: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=8936963#1
// RMQ and RAQ: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=8936971#1
// RSQ and RUQ: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=8936978#1

template<typename T>
struct Node {
    T value;
    long long index;
    long long size;
    long long coeff;

    Node(T v, long long i = -1, long long s = 0, long long c = 1) : value(v), index(i), size(s), coeff(c) {};

    bool operator< (const Node &other) const {
        return value < other.value;
    }

    bool operator== (const T other) const {
        return value == other;
    }

    bool operator!= (const T other) const {
        return value != other;
    }

    operator T() const {
        return value;
    }

    friend ostream& operator << (ostream &os, const Node<T>& node) {
        return os << node.value;
    }
};

template<typename T>
struct Operation {
    using S = Node<T>;

    Operation() {};

    virtual T e() = 0;

    virtual S operator() (const S& x, const S& y) = 0;
};

template<typename T = long long>
struct NoOperation : Operation<T> {
    using S = Node<T>;

    NoOperation(): _e(T()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        if (x == e()) return y;
        else if (y == e()) return x;

        T value = x.value;
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T>
struct Max : Operation<T> {
    using S = Node<T>;

    Max(): _e(numeric_limits<T>::min()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = max(x.value, y.value);
        long long index = (y.value > x.value ? y.index : x.index);
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T>
struct Min: Operation<T> {
    using S = Node<T>;

    Min(): _e(numeric_limits<T>::max()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = min(x.value, y.value);
        long long index = (y.value < x.value ? y.index : x.index);
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T>
struct Sum: Operation<T> {
    using S = Node<T>;

    Sum(): _e(T()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = x.value + y.value;
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = size;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T>
struct Mul: Operation<T> {
    using S = Node<T>;

    Mul(): _e(T(1)) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = x.value * y.value;
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T = long long>
struct GCD : Operation<T> {
    using S = Node<T>;

    GCD(): _e(T(0)) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = gcd(x.value, y.value);
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T = long long>
struct LCM : Operation<T> {
    using S = Node<T>;

    LCM(): _e(T(1)) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = lcm(x.value, y.value);
        long long index = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, index, size, coeff);

        return ret;
    }

private:
    T _e;
};

template<typename T, typename F>
struct Mapping {
    using S = Node<T>;

    Mapping() {};

    virtual F id() = 0;

    void operator() (S &x, const F f) {
        if (f == id()) return;

        map(x, f);
    }

    void composition(F &f, const F s) {
        if (f == id()) {
            f = s;
            return;
        };
        if (s == id()) return;

        com(f, s);
    }

    virtual void map(S &x, const F f) = 0;
    virtual void com(F &f, const F s) = 0;
};

template<typename T, typename F>
struct Add: Mapping<T, F> {
    using S = Node<T>;

    Add(): _id(F(0)) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        x.value += f * x.coeff;
    }

    void com(F &f, const F s) override {
        f += s;
    }

private:
    F _id;
};

template<typename T, typename F>
struct Multiply: Mapping<T, F> {
    using S = Node<T>;

    Multiply(): _id(F(1)) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        x.value *= f;
    }

    void com(F &f, const F s) override {
        f *= s;
    }

private:
    F _id;
};

template<typename T, typename G>
struct Affine: Mapping<T, pair<G, G>> {
    using S = Node<T>;
    using F = pair<G, G>;

    Affine(): _id(F(1, 0)) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        x.value = f.first * x.value + f.second * x.coeff;
    }

    void com(F &f, const F s) override {
        f.first *= s.first;
        f.second *= s.first;
        f.second += s.second;
    }

private:
    F _id;
};

template<typename T, typename F>
struct Set: Mapping<T, F> {
    using S = Node<T>;

    Set(): _id(numeric_limits<F>::min()) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        x.value = T(f) * x.coeff;
    }

    void com(F &f, const F s) override {
        f = s;
    }

private:
    F _id;
};

template<typename T>
struct Set<T, string>: Mapping<T, string> {
    using S = Node<T>;
    using F = string;

    Set(): _id(F()) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        x.value = T(f);
    }

    void com(F &f, const F s) override {
        f = s;
    }

private:
    F _id;
};

template<typename T, typename F>
struct Flip: Mapping<T, F> {
    using S = Node<T>;

    Flip(): _id(F()) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        if (f) {
            x.value ^= 1;
        }
    }

    void com(F &f, const F s) override {
        f ^= s;
    }

private:
    F _id;
};

template<typename T, 
    typename F,
    template<class, class> class _mapping, 
    template<class> class _op>
struct LazySegmentTree {
    using S = Node<T>;

    long long N, _N, height;

    vector<S> node;
    vector<F> lazy;
    _op<T> op;
    _mapping<T, F> mapping;

    LazySegmentTree(long long n) : _N(n), op(), mapping() {
        vector<T> v(n, op.e());
        init(v);
    }

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
            if (i < _N) node[i + N] = S(v[i], i, 1, 1);
            else node[i + N] = S(op.e());
        }
        repd(i, 1, N) update(i);
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply(long long p, F f) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        repd(i, 1, height) push(k >> i);
        mapping(node[k], f);
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
            if (seg.node[i].value == seg.op.e()) os << "e ";
            else os << seg.node[i] << " ";

            if (i == (1 << h) - 1) {
                os << endl;
                h++;
            }
        }
        os << endl;

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

template<typename T = long long, typename F = long long> using RangeAddRangeSum = LazySegmentTree<T, F, Add, Sum>;
template<typename T = long long, typename F = long long> using RangeAddRangeMin = LazySegmentTree<T, F, Add, Min>;
template<typename T = long long, typename F = long long> using RangeAddRangeMax = LazySegmentTree<T, F, Add, Max>;

template<typename T = long long, typename F = long long> using RangeSetRangeSum = LazySegmentTree<T, F, Set, Sum>;
template<typename T = long long, typename F = long long> using RangeSetRangeMin = LazySegmentTree<T, F, Set, Min>;
template<typename T = long long, typename F = long long> using RangeSetRangeMax = LazySegmentTree<T, F, Set, Max>;