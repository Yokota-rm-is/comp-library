#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&"

#include "../../base.cpp"

int main() {
    ll a, b;
    cin >> a >> b;

    auto [g, x, y] = extGCD(a, b);

    cout << x << " " << y << endl;

    return 0;
}