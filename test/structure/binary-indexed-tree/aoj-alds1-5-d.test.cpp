#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&"

#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    ll n;
    cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];

    cout << calc_invension(a) << endl;

    return 0;
}