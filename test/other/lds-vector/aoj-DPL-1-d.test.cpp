#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include "../../../other/lds-vector.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    fore(a, A) cin >> a;

    LDSVector<ll> lds;
    rep(i, N) lds.push_back(-A[i]);

    cout << lds.size_lds() << endl;

    return 0;
} 
