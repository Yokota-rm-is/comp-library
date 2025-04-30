#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc322/tasks/abc322_f"
// https://atcoder.jp/contests/abc322/submissions/64271428

#include "../../../structure/lazy-segment-tree-01.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<bool> A(N);
    rep(i, N) A[i] = (S[i] == '1');

    LazySegmentTree01 tree(A);

    while (Q--) {
        ll c, L, R;
        cin >> c >> L >> R;
        --L;

        if (c == 1) {
            tree.apply_flip(L, R);
        }
        else {
            cout << tree.prod_len_ones(L, R) << endl;
        }
    }

    return 0;
} 
