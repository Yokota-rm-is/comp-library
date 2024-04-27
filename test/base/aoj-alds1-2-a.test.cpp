#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&"

#include "../../base.cpp"

int main() {
    ll n;
    cin >> n;

    vll A(n);
    rep(i, n) cin >> A[i];

    ll ans = bubble_sort(A);

    cout << A << endl;
    cout << ans << endl;

    return 0;
}