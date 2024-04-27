#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&"

#include "../../base.cpp"

int main() {
    ll m, n;
    cin >> m >> n;

    ll MOD = 1000000007;

    cout << binpow(m, n, MOD) << endl;

    return 0;
}