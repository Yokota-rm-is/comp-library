#define PROBLEM "https://atcoder.jp/contests/abc220/tasks/abc220_f"

#include "../../../tree/tree-dp.cpp"


int main() {
    ll n;
    cin >> n;

    TreeDP<ll, ll, ll, None, AddVTimes, Sum> tree(n);
    rep(i, n - 1) {
        ll s, t;
        cin >> s >> t;
        --s; --t;

        tree.connect(s, t, 1);
    }

    tree.build(0);
    auto ans = tree.reroot();

    rep(i, n) {
        cout << ans[i] << endl;
    }

    return 0;
}