#define PROBLEM "https://atcoder.jp/contests/abc122/tasks/abc122_c"

#include "../../../other/cumulative-sum.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;
    
    string S;
    cin >> S;

    vll A(N, 0);

    rep(i, N - 1) {
        if (S[i] == 'A' and S[i + 1] == 'C') A[i] = 1;
    }

    auto B = CumulativeSum(A);
    debug(A, B);

    while (Q--) {
        ll l, r;
        cin >> l >> r;

        cout << B.sum(l - 1, r - 1) << endl;
    }

    return 0;
}