#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&"

#include "../../../math/prime-factorization.cpp"

int main() {
    ll n;
    cin >> n;

    cout << n << ":";

    auto mp = prime_factorization(n);
    fore(p, mp) {
        rep(i, p.second) cout << " " << p.first;
    }
    cout << endl;

    return 0;
}