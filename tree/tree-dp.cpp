#pragma once
#include "../base.cpp"

template<typename T, typename S = T>
struct Product {
    T value;
    S sub0, sub1;
    long long num_v;
    long long num_e;

    Product(T v = 0, S s0 = 0, S s1 = 0, long long nv = 0, long long ne = 0) : value(v), sub0(s0), sub1(s1), num_v(nv), num_e(ne) {};

    operator T() const {
        return value;
    }
};

template<typename Weight, typename T>
struct Put {
    using S = Product<T>;

    Put() {};

    virtual T e() = 0;
    virtual bool is_vertex() = 0;
    virtual bool is_none() = 0;

    virtual S operator() (const S& dp, const Weight& w) = 0;
};

template<typename Weight, typename T>
struct None : Put<Weight, T> {
    using S = Product<T>;

    None(bool is_vertex): _e(numeric_limits<T>::min()), _is_vertex(is_vertex), _is_none(true) {};

    T e() override {
        return _e;
    }

    bool is_vertex() override {
        return _is_vertex;
    }

    bool is_none() override {
        return _is_none;
    }

    S operator() (const S& dp, const Weight& w) override {
        T value = dp.value;
        T sub0 = dp.sub0;
        T sub1 = dp.sub1;
        long long num_v = dp.num_v + (is_vertex() == true);
        long long num_e = dp.num_e + (is_vertex() == false);

        return S(value, sub0, sub1, num_v, num_e);
    }

private:
    T _e;
    bool _is_vertex;
    bool _is_none;
};

template<typename Weight, typename T>
struct Add : Put<Weight, T> {
    using S = Product<T>;

    Add(bool is_vertex) : _e(T(0)), _is_vertex(is_vertex), _is_none(false) {};

    T e() override {
        return _e;
    }

    bool is_vertex() override {
        return _is_vertex;
    }

    bool is_none() override {
        return _is_none;
    }

    S operator() (const S& dp, const Weight& w) override {
        T value = dp.value + T(w);
        T sub0 = dp.sub0;
        T sub1 = dp.sub1;
        long long num_v = dp.num_v + (is_vertex() == true);
        long long num_e = dp.num_e + (is_vertex() == false);

        return S(value, sub0, sub1, num_v, num_e);
    }

private:
    T _e;
    bool _is_vertex;
    bool _is_none;
};

template<typename Weight, typename T>
struct Mul : Put<Weight, T> {
    using S = Product<T>;

    Mul(bool is_vertex) : _e(T(1)), _is_vertex(is_vertex), _is_none(false) {};

    T e() override {
        return _e;
    }

    bool is_vertex() override {
        return _is_vertex;
    }

    bool is_none() override {
        return _is_none;
    }

    S operator() (const S& dp, const Weight& w) override {
        T value = dp.value * T(w);
        T sub0 = dp.sub0;
        T sub1 = dp.sub1;
        long long num_v = dp.num_v + (is_vertex() == true);
        long long num_e = dp.num_e + (is_vertex() == false);

        return S(value, sub0, sub1, num_v, num_e);
    }

private:
    T _e;
    bool _is_vertex;
    bool _is_none;
};

template<typename Weight, typename T>
struct AddETimes : Put<Weight, T> {
    using S = Product<T>;

    AddETimes(bool is_vertex) : _e(T(0)), _is_vertex(is_vertex), _is_none(false) {};

    T e() override {
        return _e;
    }

    bool is_vertex() override {
        return _is_vertex;
    }

    bool is_none() override {
        return _is_none;
    }

    S operator() (const S& dp, const Weight& w) override {
        T value = dp.value + T(w * dp.num_e);
        T sub0 = dp.sub0;
        T sub1 = dp.sub1;
        long long num_v = dp.num_v + (is_vertex() == true);
        long long num_e = dp.num_e + (is_vertex() == false);

        return S(value, sub0, sub1, num_v, num_e);
    }

private:
    T _e;
    bool _is_vertex;
    bool _is_none;
};

template<typename Weight, typename T>
struct AddVTimes : Put<Weight, T> {
    using S = Product<T>;

    AddVTimes(bool is_vertex) : _e(T(0)), _is_vertex(is_vertex), _is_none(false) {};

    T e() override {
        return _e;
    }

    bool is_vertex() override {
        return _is_vertex;
    }

    bool is_none() override {
        return _is_none;
    }

    S operator() (const S& dp, const Weight& w) override {
        T value = dp.value + T(w * dp.num_v);
        T sub0 = dp.sub0;
        T sub1 = dp.sub1;
        long long num_v = dp.num_v + (is_vertex() == true);
        long long num_e = dp.num_e + (is_vertex() == false);

        return S(value, sub0, sub1, num_v, num_e);
    }

private:
    T _e;
    bool _is_vertex;
    bool _is_none;
};

template<typename T>
struct Merge {
    using S = Product<T>;

    Merge() {};

    virtual T e() = 0;

    virtual S operator() (const S& x, const S& y) = 0;
};

template<typename T>
struct Sum : Merge<T> {
    using S = Product<T>;

    Sum() : _e(T(0)) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value = x.value + y.value;
        T sub0 = x.sub0 + y.sub0;
        T sub1 = x.sub1 + y.sub1;
        long long num_v = x.num_v + y.num_v;
        long long num_e = x.num_e + y.num_e;

        return S(value, sub0, sub1, num_v, num_e);
    }

private:
    T _e;
};

template<typename T>
struct Max : Merge<T> {
    using S = Product<T>;

    Max() : _e(numeric_limits<T>::min()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value, sub0, sub1;
        if (x.value < y.value) {
            value = y.value;
            sub0 = y.sub0;
            sub1 = y.sub1;
        }
        else {
            value = x.value;
            sub0 = x.sub0;
            sub1 = x.sub1;
        }

        long long num_v = x.num_v + y.num_v;
        long long num_e = x.num_e + y.num_e;

        return S(value, sub0, sub1, num_v, num_e);
    }

private:
    T _e;
};

template<typename T>
struct Min : Merge<T> {
    using S = Product<T>;

    Min() : _e(numeric_limits<T>::max()) {};

    T e() override {
        return _e;
    }

    S operator() (const S& x, const S& y) override {
        T value, sub0, sub1;
        if (x.value < y.value) {
            value = x.value;
            sub0 = x.sub0;
            sub1 = x.sub1;
        }
        else {
            value = y.value;
            sub0 = y.sub0;
            sub1 = y.sub1;
        }

        long long num_v = x.num_v + y.num_v;
        long long num_e = x.num_e + y.num_e;

        return S(value, sub0, sub1, num_v, num_e);
    }

private:
    T _e;
};

/**
 * @brief tree-dp
 * @docs docs/tree/tree-dp.md
*/
template <typename EdgeWeight, 
    typename VertexWeight, 
    typename T,
    template<class, class> class _put_vertex,
    template<class, class> class _put_edge,
    template<class> class _merge>
struct TreeDP {
    struct Edge {
        long long from;
        long long to;
        EdgeWeight weight;
        long long rev;
        
        explicit Edge(long long u = -1, long long v = -1, EdgeWeight w = 1, long long r = -1) : from(u), to(v), weight(w), rev(r) {};

        bool operator < (const Edge& other) const {
            if (from == other.from) {
                if (to == other.to) return weight < other.weight;
                else return to < other.to;
            }
            else return from < other.from;
        }

        friend ostream& operator << (ostream& os, const Edge& edge) {
            return os << edge.to;
        }
    };

    using DP = Product<T>;

    long long V;
    vector<vector<Edge>> G;
    vector<bool> seen;

    vector<VertexWeight> v_weight;

    _put_vertex<VertexWeight, T> put_vertex;
    _put_edge<EdgeWeight, T> put_edge;
    _merge<T> merge;

    // 全方位木dp用
    vector<vector<DP>> dp;
    vector<DP> prod_all;
    long long root;

    TreeDP(long long N) : V(N), G(V), put_vertex(true), put_edge(false), merge() {
        init();
    };

    DP e() {
        if (!put_vertex.is_none()) return put_vertex.e();
        else return put_edge.e();
    }
    
    void init() {
        seen.assign(V, false);

        v_weight.resize(V);
        dp.resize(V);
        prod_all.assign(V, merge.e());
    }
    
    void connect(long long from, long long to, EdgeWeight weight) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);

        long long from_id = G[from].size();
        long long to_id = G[to].size();

        G[from].emplace_back(from, to, weight, to_id);
        G[to].emplace_back(to, from, weight, from_id);

        dp[from].push_back(e());
        dp[to].push_back(e());
    }

    void set_vertex_weight(long long v, VertexWeight w) {
        assert(0 <= v and v < V);

        v_weight[v] = w;
    }

    DP build(long long root_) {
        root = root_;
        return dfs(root);
    }

    vector<DP> reroot() {
        prod(root, e());

        return prod_all;
    }

    DP dfs(long long now) {
        assert(0 <= now and now < V);

        DP ret = e();

        seen[now] = true;

        rep(i, G[now].size()) {
            Edge edge = G[now][i];
            long long next = edge.to;

            if (seen[next]) continue;

            dp[now][i] = dfs(next);
            ret = merge(ret, put_edge(dp[now][i], edge.weight));
        }

        return put_vertex(ret, v_weight[now]);
    }

    void prod(long long now, const DP& dp_p, Edge e_p = Edge()) {
        long long deg = G[now].size();

        if (e_p.rev != -1) dp[now][e_p.rev] = dp_p;

        vector<DP> prod_l(deg + 1, e()), prod_r(deg + 1, e());

        rep(i, deg) {
            Edge edge = G[now][i];
            prod_l[i + 1] = merge(prod_l[i], put_edge(dp[now][i], edge.weight));
        }

        repd(i, deg) {
            Edge edge = G[now][i];
            prod_r[i] = merge(prod_r[i + 1], put_edge(dp[now][i], edge.weight));
        }

        prod_all[now] = put_vertex(prod_l.back(), v_weight[now]);

        rep(i, deg) {
            if (i == e_p.rev) continue;

            Edge edge = G[now][i];
            long long child = edge.to;
            prod(child, put_vertex(merge(prod_l[i], prod_r[i + 1]), v_weight[now]), edge);
        }
    }
};