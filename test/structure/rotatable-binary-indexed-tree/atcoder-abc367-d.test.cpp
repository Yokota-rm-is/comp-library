#define PROBLEM "https://atcoder.jp/contests/abc367/tasks/abc367_d"

#include "../../../structure/rotatable-binary-indexed-tree.cpp"
#include "../../../other/cumulative-sum.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A.push_back(A[i]);

    vll B = CumulativeSum(A);

    RotatableBinaryIndexedTree<ll> bit(M, 0);
    rep(i, N - 1) {
        bit.add(B[i] % M, 1);
    }

    ll ans = 0;
    rep(i, N) {
        ans += bit.get(0);
        bit.add<true>(B[i] % M, -1);
        bit.add<true>(B[i + N - 1] % M, 1);
        bit.rotate_left(A[i]);
    }

    cout << ans << endl;

    return 0;
}