#define PROBLEM "https://atcoder.jp/contests/abc348/tasks/abc348_e"

#include "../../../tree/tree-dp.cpp"

template<typename Weight, typename T>
struct ABC348E : Put<Weight, T> {
    using S = Product<T>;

    ABC348E(bool is_vertex) : _e(T(0)), _is_vertex(is_vertex), _is_none(false) {};

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
        T value = dp.value + dp.sub0;
        T sub0 = dp.sub0 + w;
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

int main() {
    ll N;
    cin >> N;

    TreeDP<ll, ll, ll, ABC348E, None, Sum> tree(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        --a; --b;

        tree.connect(a, b, 0);
    }

    rep(i, N) {
        ll c;
        cin >> c;
        tree.set_vertex_weight(i, c);
    }

    tree.build(0);
    auto dp = tree.reroot();

    ll ans = inf64;
    rep(i, N) chmin(ans, dp[i].value);

    cout << ans << endl;

    return 0;
}