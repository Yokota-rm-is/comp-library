#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include "../../../other/LIS.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    fore(a, A) cin >> a;

    LIS<ll> lis(A);
    cout << lis.solve() << endl;

    return 0;
} 
