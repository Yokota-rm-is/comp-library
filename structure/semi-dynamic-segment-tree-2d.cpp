#pragma once
#include "../base.cpp"
#include <algorithm>

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
struct SemiDynamicSegmentTree2D {
    using S = Node<T>;
    using Point = pair<long long, long long>;

    long long H, _H, _W;
    vector<long long> Ws;
    vector<vector<S>> node;

    vector<vector<long long>> indices;
    _op<T> op;
    _mapping<T, F> mapping;

    T e;

    SemiDynamicSegmentTree2D(long long h, long long w) : _H(h), _W(w), op(), mapping(), e(op.e()) {
        init();
    }

    SemiDynamicSegmentTree2D(long long h, long long w, T a) : _H(h), _W(w), op(), mapping(), e(a) {
        init();
    }

    void init() {
        H = 1;
        while (H < _H) H <<= 1;

        Ws.resize(2 * H);
        node.resize(2 * H);
        indices.resize(2 * H);
    }

    void add_point(long long y, long long x) {
        assert(0 <= y and y < _H and 0 <= x and x < _W);

        indices[y + H].push_back(x);
    }

    void build() {
        build(op.e());
    }

    void build(T a) {
        e = a;

        repd(i, 1, 2 * H) {
            if (indices[i].empty()) continue;

            sort(indices[i].begin(), indices[i].end());
            indices[i].erase(unique(indices[i].begin(), indices[i].end()), indices[i].end());

            Ws[i] = 1;
            while (Ws[i] < indices[i].size()) Ws[i] <<= 1;

            node[i].resize(2 * Ws[i], S(e));

            fore(x, indices[i]) {
                indices[i / 2].push_back(x);
            }
        }

        rep(y, _H) {
            rep(xi, Ws[y + H]) {
                node[y + H][xi + Ws[y + H]] = S(a, y, indices[y + H][xi], 1, 1);
            }
        }

        repd(y, 1, H) {
            repd(xi, 1, Ws[y]) {
                update_x(y, xi);
            }
        }
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply(long long y, long long x, F f) {
        assert(0 <= y and y < _H and 0 <= x and x < _W);

        y += H;

        long long xi = lower_bound(indices[y].begin(), indices[y].end(), x) - indices[y].begin();
        xi += Ws[y];

        mapping(node[y][xi], f);
        xi >>= 1;

        for (; xi > 0; xi >>= 1) update_x(y, xi);
        y >>= 1;

        while (y > 0) {
            long long xi = lower_bound(indices[y].begin(), indices[y].end(), x) - indices[y].begin();
            xi += Ws[y];

            auto l = find(indices[y * 2].begin(), indices[y * 2].end(), x);
            auto r = find(indices[y * 2 + 1].begin(), indices[y * 2 + 1].end(), x);

            S s(op.e());
            if (l != indices[y * 2].end()) {
                long long xi_l = l - indices[y * 2].begin();
                s = op(s, node[y * 2][xi_l + Ws[y * 2]]);
            }
            if (r != indices[y * 2 + 1].end()) {
                long long xi_r = r - indices[y * 2 + 1].begin();
                s = op(s, node[y * 2 + 1][xi_r + Ws[y * 2 + 1]]);
            }

            node[y][xi] = s;
            xi >>= 1;

            for (; xi > 0; xi >>= 1) update_x(y, xi);
            
            y >>= 1;
        }
    }

    S get(long long y, long long x) {
        assert(0 <= y and y < _H and 0 <= x and x < _W);

        y += H;

        long long xi = lower_bound(indices[y].begin(), indices[y].end(), x) - indices[y].begin();
        xi += Ws[y];

        return node[y][xi];
    }

    // 半開区間[h1, h2) x [w1, w2)の配列の値を返す
    // l, rともに0-indexed
    S prod(long long h1, long long h2, long long w1, long long w2) {
        assert(0 <= h1 and h1 <= h2 and h2 <= _H and 0 <= w1 and w1 <= w2 and w2 <= _W);

        ll u = h1 + H, d = h2 + H;
        S smu(e), smd(e);
        for (; u < d; u >>= 1, d >>= 1) {
            if (u & 1) {
                long long l = lower_bound(indices[u].begin(), indices[u].end(), w1) - indices[u].begin();
                long long r = lower_bound(indices[u].begin(), indices[u].end(), w2) - indices[u].begin();
                smu = op(smu, prod_x(u++, l, r));
            }
            if (d & 1) {
                --d;
                long long l = lower_bound(indices[d].begin(), indices[d].end(), w1) - indices[d].begin();
                long long r = lower_bound(indices[d].begin(), indices[d].end(), w2) - indices[d].begin();
                smd = op(prod_x(d, l, r), smd);
            }
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

    friend ostream& operator << (ostream& os, SemiDynamicSegmentTree2D& seg) {
        rep(i, seg._H) {
            rep(j, seg._W) {
                os << seg.get(i, j) << " ";
            }
            os << endl;
        }

        return os;
    }

private:
    void update_x(long long y, long long xi) {
        node[y][xi] = op(node[y][xi * 2], node[y][xi * 2 + 1]);
    }

    S prod_x(long long y, long long xi_l, long long xi_r) {
        S sml(e), smr(e);
        ll l = xi_l + Ws[y], r = xi_r + Ws[y];

        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sml = op(sml, node[y][l++]);
            if (r & 1) smr = op(node[y][--r], smr);
        }

        return op(sml, smr);
    }
};
