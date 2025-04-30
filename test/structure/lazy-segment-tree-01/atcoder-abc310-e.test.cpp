#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc310/tasks/abc310_e"
// https://atcoder.jp/contests/abc310/submissions/65362306

#include "../../../structure/lazy-segment-tree-01.cpp"

int main() {
    ll N;
    cin >> N;
    
    string S;
    cin >> S;

    LazySegmentTree01 tree(N, 0);

    ll ans = 0;
    rep(i, N) {
        bool x = S[i] - '0';

        tree.apply_nand(0, i, x);
        tree.apply_set(i, x);
        ans += tree.prod_ones(0, i + 1);
    }

    cout << ans << endl;

    return 0;
} 
