#pragma once
#include "../base.cpp"

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
struct SqrtDecomposition {
    using S = Node<T>;
    long long _N, N, sqrtN, K;
    
    vector<S> node;
    vector<S> bucket;
    vector<F> lazy;

    _op<T> op;
    _mapping<T, F> mapping;

    SqrtDecomposition(long long n) : _N(n) {
        vector<T> v(n, 0);
        init(v);
    }

    SqrtDecomposition(long long n, T a) : _N(n) {
        vector<T> v(n, a);
        init(v);
    }

    SqrtDecomposition(vector<T> &v) : _N(v.size()) {
        init(v);
    }

    void init(vector<T> &a) {
        sqrtN = 1;
        while ((sqrtN + 1) * (sqrtN + 1) < _N) ++sqrtN;

        K = (_N + sqrtN - 1) / sqrtN;
        N = K * sqrtN;
        
        node.assign(N, op.e());
        rep(i, _N) node[i] = S(a[i], i, 1, 1);

        bucket.assign(K, op.e());
        rep(k, K) update(k);

        lazy.assign(K, mapping.id());
    }

    void push(long long k) {
        long long l = k * sqrtN, r = (k + 1) * sqrtN;

        rep(i, l, r) {
            mapping(node[i], lazy[k]);
        }

        lazy[k] = mapping.id();
    }

    void update(long long k) {
        long long l = k * sqrtN, r = (k + 1) * sqrtN;
        
        S sm(op.e());

        rep(i, l, r) {
            sm = op(sm, node[i]);
        }

        bucket[k] = sm;
    }

    void apply(long long p, F f) {
        long long k = p / sqrtN;
        push(k);
        mapping(node[p], f);
        update(k);
    }

    // [l, r)
    void apply(long long l, long long r, F f) {
        rep(k, floor(l, sqrtN), ceil(r, sqrtN)) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                mapping.composition(lazy[k], f);

                mapping(bucket[k], f);
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    mapping(node[i], f);
                }
                update(k);
            }
        }
    }

    S get(long long p) {
        long long k = p / sqrtN;
        push(k);
        update(k);

        return node[p];
    }
    
    // [l, r)
    S prod(long long l, long long r) {
        S sm(op.e());

        rep(k, floor(l, sqrtN), ceil(r, sqrtN)) {
            long long lk = k * sqrtN, rk = (k + 1) * sqrtN;

            if (rk <= l || r <= lk) continue;
            if (l <= lk && rk <= r) {
                sm = op(sm, bucket[k]);
            } 
            else {
                push(k);
                rep(i, max(l, lk), min(r, rk)) {
                    sm = op(sm, node[i]);
                }
                update(k);
            }
        }

        return sm;
    }
};
