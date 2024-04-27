#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C&"

#include "../../base.cpp"

int main() {
    ll n;
    cin >> n;

    vll A(n);
    rep(i, n) cin >> A[i];

    cout << lcm(A) << endl;

    return 0;
}