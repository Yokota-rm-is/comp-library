#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include "../../../tree/tree-dp.cpp"

int main() {
    ll n;
    cin >> n;

    TreeDP<ll, ll, ll, None, Add, Max> tree(n);
    rep(i, n - 1) {
        ll s, t;
        cin >> s >> t;
        --s; --t;

        tree.connect(s, t, 1);
    }

    tree.build(0);
    auto ans = tree.reroot();

    rep(i, n) {
        cout << 2 * n - 2 - ans[i] << endl;
    }

    return 0;
}