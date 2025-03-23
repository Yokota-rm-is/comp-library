#define PROBLEM "https://atcoder.jp/contests/abc367/tasks/abc367_d"

#include "../../../structure/rotatable-lazy-segment-tree.cpp"
#include "../../../other/cumulative-sum.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A.push_back(A[i]);

    vll B = CumulativeSum(A);

    RotatableLazySegmentTree<ll> tree(M, 0);
    rep(i, N - 1) {
        tree.apply_add(B[i] % M, 1);
    }

    ll ans = 0;
    rep(i, N) {
        ans += tree.get(0);
        tree.apply_add<true>(B[i] % M, -1);
        tree.apply_add<true>(B[i + N - 1] % M, 1);
        tree.rotate_left(A[i]);
    }

    cout << ans << endl;

    return 0;
}