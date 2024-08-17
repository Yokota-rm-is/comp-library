#define PROBLEM "https://atcoder.jp/contests/abc167/tasks/abc167_d"

#include "../../../other/doubling.cpp"

int main() {
    ll N, K;
    cin >> N >> K;

    vll A(N);
    rep(i, N) cin >> A[i];
    --A;

    Doubling db(A, K);

    ll index = db.get(0, K);
    cout << index + 1 << endl;

    return 0;
} 
