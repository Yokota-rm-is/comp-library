#define PROBLEM "https://atcoder.jp/contests/abc367/tasks/abc367_d"

#include "../../../other/rotatable-vector.cpp"
#include "../../../other/cumulative-sum.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A.push_back(A[i]);

    vll B = CumulativeSum(A);

    RotatableVector<ll> rv(M, 0);
    rep(i, N - 1) {
        rv[B[i] % M]++;
    }

    ll ans = 0;
    ll offset = 0;
    rep(i, N) {
        ans += rv[0];

        rv.at(B[i] % M)--;
        rv.at(B[i + N - 1] % M)++;
        // rv[(B[i] + M - offset) % M]--;
        // rv[(B[i + N - 1] + M - offset) % M]++;
        offset = rv.rotate_left(A[i]);
    }

    cout << ans << endl;

    return 0;
}