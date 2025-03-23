#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include "../../../other/lis-vector.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    fore(a, A) cin >> a;

    LISVector<ll> lis;
    rep(i, N) lis.push_back(A[i]);

    cout << lis.size_lis() << endl;

    return 0;
} 
