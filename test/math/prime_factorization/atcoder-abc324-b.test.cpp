#define PROBLEM "https://atcoder.jp/contests/abc324/tasks/abc324_b"

#include "../../../math/prime_factorization.cpp"

int main() {
    ll N;
    cin >> N;

    auto v = prime_factorization(N);
    bool ans = true;
    v.erase(2);
    v.erase(3);
    if (v.size() != 0) ans = false;

    cout << YesNo(ans) << endl;

    return 0;
}