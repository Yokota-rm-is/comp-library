#define PROBLEM "https://atcoder.jp/contests/abc340/tasks/abc340_e"

#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    long long N;
    cin >> N;
    long long M;
    cin >> M;
    vector<long long> A(N);
    for(int i = 0 ; i < N ; ++i){
        cin >> A[i];
    }
    vector<long long> B(M);
    for(int i = 0 ; i < M ; ++i){
        cin >> B[i];
    }

    BinaryIndexedTree bit(A);
    rep(i, M) {
        ll ball = bit.get(B[i]);
        bit.add(B[i], -ball);
        ll start = B[i] + 1;

        if (ball >= N) {
            bit.add(0, N, ball / N);
            ball %= N;
        }

        bit.add_circular(start, start + ball, 1);
    }

    vll ans(N);
    rep(i, N) ans[i] = bit.get(i);

    cout << ans << endl;

    return 0;
}