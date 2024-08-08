#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j"

#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    long long N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];

    cout << calc_invension(A) << endl;

    return 0;
}