#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&"

#include "../../../tree/tree-dp.cpp"

int main() {
    ll n;
    cin >> n;

    TreeDP<ll, ll, ll, None, Add, Max> tree(n);
    rep(i, n - 1) {
        ll s, t, w;
        cin >> s >> t >> w;

        tree.connect(s, t, w);
    }

    tree.build(0);
    auto dp = tree.reroot();

    ll ans = 0;
    rep(i, n) {
        chmax(ans, dp[i].value);
    }

    cout << ans << endl;

    return 0;
}