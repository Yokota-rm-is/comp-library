#define PROBLEM "https://atcoder.jp/contests/agc023/tasks/agc023_a"

#include "../../../other/cumulative-sum.cpp"
#include "../../../mystd/mymultiset.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];

    auto B = CumulativeSum(A);
    MultiSet<ll> ms;
    rep(i, N) ms.insert(B[i]);
    ll bias = 0;
    ll ans = 0;

    rep(i, N) {
        ans += ms.count(bias);
        bias = B[i];
        ms.erase(B[i]);
    }

    cout << ans << endl;

    return 0;
}