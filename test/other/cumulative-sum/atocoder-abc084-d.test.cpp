#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc084/tasks/abc084_d"
// https://atcoder.jp/contests/abc084/submissions/52932657

#include "../../../other/cumulative-sum.cpp"
#include "../../../math/eratosthenes.cpp"

int main() {
    ll N = 1e5;

    Eratosthenes era(N);

    vector<ll> A(N + 1, 0);
    rep(i, 1, N + 1, 2) {
        if (!era.is_prime[i]) continue;
        if (!era.is_prime[(i + 1) / 2]) continue;

        A[i] = 1;
    }

    auto B = CumulativeSum(A);

    ll Q;
    cin >> Q;
    while (Q--) {
        ll l, r;
        cin >> l >> r;

        cout << B.sum(l, r + 1) << endl;
    }

    return 0;
}