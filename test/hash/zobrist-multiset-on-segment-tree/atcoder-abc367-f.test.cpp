#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc367/tasks/abc367_f"
// https://atcoder.jp/contests/abc367/submissions/61981692

#include "../../../hash/zobrist-multiset-on-segment-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    ZobristMultisetonSegmentTree treeA(A), treeB(B);

    while (Q--) {
        ll l, r, L, R;
        cin >> l >> r >> L >> R;
        --l, --L;

        cout << YesNo(treeA.prod(l, r) == treeB.prod(L, R)) << endl;
    }

    return 0;
} 