#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"

#include "../../../math/bell.cpp"

int main() {
    ll n, k;
    cin >> n >> k;

    Bell<1000000007> bell(n);

    cout << bell.get(k) << endl;

    return 0;
}