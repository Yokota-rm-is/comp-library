#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include "../../../math/stirling-second.cpp"

int main() {
    ll n, k;
    cin >> n >> k;

    StirlingSecond<1000000007> stirling(n);

    cout << stirling.get(k) << endl;

    return 0;
}