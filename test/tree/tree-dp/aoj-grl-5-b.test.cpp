#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B&"

#include "../../../tree/tree-dp.cpp"

int main() {
    ll n;
    cin >> n;

    TreeDP tree(n);
    rep(i, n - 1) {
        ll s, t, w;
        cin >> s >> t >> w;

        tree.connect(s, t, w);
    }

    tree.build(0);
    auto ans = tree.reroot();

    rep(i, n) {
        cout << ans[i] << endl;;
    }

    return 0;
}