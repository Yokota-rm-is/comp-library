#pragma once
#include "../base.cpp"

template<typename T>
struct Node {
    T value;
    long long y, x;
    long long size;
    long long coeff;

    Node(T v = 0, long long y = 0, long long x = 0, long long s = 0, long long c = 1) : value(v), y(y), x(x), size(s), coeff(c) {};

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
        long long r = -1;
        long long c = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, r, c, size, coeff);

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
        long long r = (y.value > x.value ? y.y : x.y);
        long long c = (y.value > x.value ? y.x : x.x);
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, r, c, size, coeff);

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
        long long r = (y.value < x.value ? y.y : x.y);
        long long c = (y.value < x.value ? y.x : x.x);
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, r, c, size, coeff);

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
        long long r = -1;
        long long c = -1;
        long long size = x.size + y.size;
        long long coeff = size;

        S ret(value, r, c, size, coeff);

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
        long long r = -1;
        long long c = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, r, c, size, coeff);

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
        long long r = -1;
        long long c = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, r, c, size, coeff);

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
    long long r = -1;
        long long c = -1;
        long long size = x.size + y.size;
        long long coeff = 1;

        S ret(value, r, c, size, coeff);

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

    virtual void map(S &x, const F f) = 0;
};

template<typename T, typename F>
struct Add: Mapping<T, F> {
    using S = Node<T>;

    Add(): _id(F(0)) {};

    F id() override {
        return _id;
    }

    void map(S &x, const F f) override {
        x.value += f;
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
        x.value = f.first * x.value + f.second;
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
        x.value = T(f);
    }

private:
    F _id;
};

template<typename T, 
    typename F,
    template<class, class> class _mapping,
    template<class> class _op>
struct DynamicSegmentTree2D {
    using S = Node<T>;

    long long H, _H, W, _W;
    unordered_map<ll, S> node;
    _op<T> op;
    _mapping<T, F> mapping;

    T e;

    DynamicSegmentTree2D(long long h, long long w) : _H(h), _W(w), op(), mapping(), e(op.e()) {
        init();
    }

    DynamicSegmentTree2D(long long h, long long w, T a) : _H(h), _W(w), op(), mapping(), e(a) {
        init();
    }

    void init() {
        H = 1, W = 1;
        while (H < (_H + 1)) {
            H *= 2;
        }

        while (W < (_W + 1)) {
            W *= 2;
        }
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply(long long y, long long x, F f) {
        assert(0 <= y and y < _H and 0 <= x and x < _W);

        auto it = node[id(y + H, x + W)];
        it.y = y;
        it.x = x;
        it.size = 1;
        it.coeff = 1;
        mapping(it, f);
        node[id(y + H, x + W)] = it;

        update(y, x);
    }

    S get(long long y, long long x) {
        assert(0 <= y and y < _H and 0 <= x and x < _W);

        auto it = node.find(id(y + H, x + W));
        if (it == node.end()) return S(e);
        else return it->second;
    }

    // 半開区間[h1, h2) x [w1, w2)の配列の値を返す
    // l, rともに0-indexed
    S prod(long long h1, long long h2, long long w1, long long w2) {
        assert(0 <= h1 and h1 <= h2 and h2 <= _H and 0 <= w1 and w1 <= w2 and w2 <= _W);

        h1 += H, h2 += H, w1 += W, w2 += W;
        S smu(e), smd(e);
        for (ll u = h1, d = h2; u < d; u >>= 1, d >>= 1) {
            if (u & 1) smu = op(smu, prod(u++, w1, w2));
            if (d & 1) smd = op(prod(--d, w1, w2), smd);
        }

        return op(smu, smd);
    }

    S prod(long long h, long long w) {
        return prod(0, h, 0, w);
    }

    // 半開区間[h1, h2) x [w1, w2) (0-indexed)の要素の数を求める
    T count(long long h1, long long h2, long long w1, long long w2) {
        return prod(h1, h2, w1, w2).size;
    }

    T count(long long h, long long w) {
        return count(0, h, 0, w);
    }

    friend ostream& operator << (ostream& os, DynamicSegmentTree2D& seg) {
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
            auto it0 = node.find(id(i * 2, x));
            auto it1 = node.find(id(i * 2 + 1, x));

            if (it0 == node.end() and it1 == node.end()) continue;
            else if (it0 == node.end()) node[id(i, x)] = it1->second;
            else if (it1 == node.end()) node[id(i, x)] = it0->second;
            else node[id(i, x)] = op(it0->second, it1->second);
        }

        for (long long i = y; i > 0; i >>= 1) {
            for (long long j = x >> 1; j > 0; j >>= 1) {
                auto it0 = node.find(id(i, j * 2));
                auto it1 = node.find(id(i, j * 2 + 1));

                if (it0 == node.end() and it1 == node.end()) continue;
                else if (it0 == node.end()) node[id(i, j)] = it1->second;
                else if (it1 == node.end()) node[id(i, j)] = it0->second;
                else node[id(i, j)] = op(it0->second, it1->second);
            }
        }
    }

    S prod(long long i, long long j1, long long j2) {
        S sml(e), smr(e);
        for (long long l = j1, r = j2; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                auto it = node.find(id(i, l++));
                if (it != node.end()) sml = op(sml, it->second);
            }
            if (r & 1) {
                auto it = node.find(id(i, --r));
                if (it != node.end()) smr = op(it->second, smr);
            }
        }

        return op(sml, smr);
    }
};
