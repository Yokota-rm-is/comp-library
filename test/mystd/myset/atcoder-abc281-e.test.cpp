#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_e"

#include "../../../mystd/myset.cpp"

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    vll A(N);
    rep(i, N) cin >> A[i];

    MultiSet<ll> ms;
    rep(i, M - 1) ms.insert(A[i]);
    rep(i, M - 1, N) {
        ms.insert(A[i]);

        cout << ms.sum_min_k(K);
        if (i < N - 1) cout << " ";
        else cout << endl;

        ms.erase(A[i - M + 1]);
    }

    return 0;
} 
