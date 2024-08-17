#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc367/tasks/abc367_e"

#include "../../../other/doubling.cpp"

int main() {
    ll N, K;
    cin >> N >> K;

    vll X(N);
    rep(i, N) cin >> X[i];
    --X;

    vll A(N);
    rep(i, N) cin >> A[i];

    Doubling db(X, K);
    rep(i, N) {
        ll index = db.get(i, K);
        cout << A[index];
        if (i < N - 1) cout << " ";
    }
    cout << endl;

    return 0;
} 
