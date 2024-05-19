#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc036/tasks/abc036_c"
// https://atcoder.jp/contests/abc036/tasks/abc036_c

#include "../../../base.cpp"

int main() {
    ll N;
    cin >> N;
    
    vll A(N);
    rep(i, N) cin >> A[i];

    vll B = compress(A, false);
    rep(i, N) cout << B[i] << endl;

    return 0;
}