#define PROBLEM "https://atcoder.jp/contests/abc353/tasks/abc353_g"

#include "../../../structure/linear-add-range-min.cpp"

int main() {
    ll N, C, M;
    cin >> N >> C >> M;

    using T = lll;
    auto e = []() { return -INF64; };
    LinearAddRangeMax<T, e> tree(N, -INF64);
    tree.set(0, 0);

    rep(i, M) {
        ll t, p;
        cin >> t >> p;
        --t;

        lll m = tree.get(t);
        chmax(m, tree.prod_assume_apply_ar(0, t + 1, 0, C));
        chmax(m, tree.prod_assume_apply_al(t, N, 0, -C));

        tree.set(t, m + p);
    }

    lll ans = tree.prod(0, N);

    cout << ans << endl;

    return 0;
} 
