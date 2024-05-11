#pragma once
#include "../base.cpp"

template<typename T>
struct Node {
    T value;
    long long time;

    Node(T v, long long t = -1) : value(v), time(t) {};

    bool operator< (const Node &other) const {
        return value < other.value;
    }

    operator T() const {
        return value;
    }
    
    friend ostream& operator << (ostream &os, const Node<T> &node) {
        return os << node.value;
    }
};

template<typename S, typename T>
struct Mapping {
    using F = Node<T>;

    Mapping() {};

    virtual T id() = 0;

    void operator() (S &x, const F &f) {
        if (f == id()) return;

        map(x, f);
    }

    void composition(F &f, const F &s) {
        if (f == id()) {
            f = s;
            return;
        };
        if (s == id()) return;

        com(f, s);
    }

    virtual void map(S &x, const F &f) = 0;
    virtual void com(F &f, const F &s) = 0;
};

template<typename S, typename T>
struct Add: Mapping<S, T> {
    using F = Node<T>;

    Add(): _id(T(0)) {};

    T id() override {
        return _id;
    }

    void map(S &x, const F &f) override {
        x += f.value;
    }

    void com(F &f, const F &s) override {
        f.value += s.value;
    }

private:
    T _id;
};

template<typename S, typename T>
struct Multiply: Mapping<S, T> {
    using F = Node<T>;

    Multiply(): _id(T(1)) {};

    T id() override {
        return _id;
    }

    void map(S &x, const F &f) override {
        x *= f.value;
    }

    void com(F &f, const F &s) override {
        f.value *= s.value;
    }

private:
    T _id;
};

template<typename S, typename T>
struct Set: Mapping<S, T> {
    using F = Node<T>;

    Set(): _id(numeric_limits<T>::min()) {};

    T id() override {
        return _id;
    }

    void map(S &x, const F &f) override {
        x = S(f.value);
    }

    void com(F &f, const F &s) override {
        if (f.time < s.time) f = s;
    }

private:
    T _id;
};

template<typename S>
struct Set<S, string>: Mapping<S, string> {
    using T = string;
    using F = Node<T>;

    Set(): _id(T()) {};

    T id() override {
        return _id;
    }

    void map(S &x, const F &f) override {
        x = T(f.value);
    }

    void com(F &f, const F &s) override {
        if (f.time < s.time) f = s;
    }

private:
    T _id;
};

template<typename S, typename T>
struct Chmin: Mapping<S, T> {
    using F = Node<T>;

    Chmin(): _id(numeric_limits<T>::max()) {};

    T id() override {
        return _id;
    }

    void map(S &x, const F &f) override {
        if (x > T(f.value)) x = T(f.value);
    }

    void com(F &f, const F &s) override {
        if (f.value > s.value) f = s;
    }

private:
    T _id;
};

template<typename S, typename T>
struct Chmax: Mapping<S, T> {
    using F = Node<T>;

    Chmax(): _id(numeric_limits<T>::min()) {};

    T id() override {
        return _id;
    }

    void map(S &x, const F &f) override {
        if (x < T(f.value)) x = T(f.value);
    }

    void com(F &f, const F &s) override {
        if (f.value < s.value) f = s;
    }

private:
    T _id;
};

template<typename S, typename T>
struct Flip: Mapping<S, T> {
    using F = Node<T>;

    Flip(): _id(T()) {};

    T id() override {
        return _id;
    }

    void map(S &x, const F &f) override {
        if (f.value) x = ~x;
    }

    void com(F &f, const F &s) override {
        f = s;
    }

private:
    T _id;
};

template<typename S, 
    typename T,
    template<class, class> class _mapping>
struct DualSegmentTree {
    using F = Node<T>;

    long long N, _N, height;

    vector<S> v;
    vector<F> node;
    _mapping<S, T> mapping;

    long long time;

    DualSegmentTree(ll n) : _N(n), mapping(), time(0) {
        v(n, mapping.id());
        init();
    }

    DualSegmentTree(ll n, S a) : _N(n), v(n, a), mapping(), time(0) {
        init();
    }

    DualSegmentTree(vector<S> &A) : _N(v.size()), v(A), mapping(), time(0) {
        init();
    }

    void init() {
        _N = v.size();
        height = 1;
        N = 1;

        while (N < _N) {
            N *= 2;
            height++;
        }
        
        node.resize(N * 2, F(mapping.id()));
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply(long long p, T f) {
        apply_with_time(p, f, time++);
    }

    // p番目の配列の値に対して，fでmapping
    // pは0-indexed
    void apply_with_time(long long p, T f, long long t) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        mapping.composition(node[k], F(f, t));
    }

    // 半開区間[l, r)の配列の値に対して，fでmapping
    // l, rともに0-indexed
    void apply(long long l, long long r, T f) {
        apply_with_time(l, r, f, time++);
    }

    void apply_with_time(long long l, long long r, T f, long long t) {
        assert(0 <= l && l <= r && r <= _N);

        l += N;
        r += N;

        while (l < r) {
            if (l & 1) mapping.composition(node[l++], F(f, t));
            if (r & 1) mapping.composition(node[--r], F(f, t));
            l >>= 1;
            r >>= 1;
        }
    }

    S get(long long p) {
        assert(0 <= p and p < _N);

        long long k = p + N;
        F f(mapping.id());

        repd(i, height) mapping.composition(f, node[k >> i]);

        S ret = v[p];
        mapping(ret, f);
        return ret;
    }

    friend ostream& operator << (ostream& os, DualSegmentTree& seg) {
        os << "v" << endl;
        rep(i, seg._N) {
            os << seg.v[i] << " ";
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

template<typename S = long long, typename T = long long> using RangeAddPointGet = DualSegmentTree<S, T, Add>;
template<typename S = long long, typename T = long long> using RangeSetPointGet = DualSegmentTree<S, T, Set>;
template<typename S = long long, typename T = long long> using RangeChminPointGet = DualSegmentTree<S, T, Chmin>;
template<typename S = long long, typename T = long long> using RangeChmaxPointGet = DualSegmentTree<S, T, Chmax>;