#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc077/tasks/arc077_c"
// https://atcoder.jp/contests/arc077/submissions/66142377

#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    ll n, m;
    cin >> n >> m;

    vll a(n);
    rep(i, n) cin >> a[i];
    --a;

    ll S = 0;
    BinaryIndexedTree<> bit(m, 0);

    rep(i, n - 1) {
        S += (a[i + 1] - a[i] + m) % m;

        bit.add_circular(a[i], a[i + 1], 0, 1);
    }

    ll ans = S;
    rep(i, m) {
        chmin(ans, (ll)(S - bit.get(i)));
    }

    cout << ans << endl;

    return 0;
} 