#define PROBLEM "https://atcoder.jp/contests/abc328/tasks/abc328_e"

#include "../../../other/next-combination.cpp"
#include "../../../structure/unionfind.cpp"

int main() {
    ll N, M, K;
    input(N, M, K);

    vll U, V, W;
    input(M, U, V, W);
    --U; --V;

    vll A(M);
    rep(i, M) A[i] = i;

    ll ans = inf64;
    do {
        UnionFind uf(N);
        ll sum = 0;

        rep(i, N - 1) {
            uf.unite(U[A[i]], V[A[i]]);
            sum += W[A[i]];
        }

        if (!uf.is_connected()) continue;

        chmin(ans, sum % K);

    } while (next_combination(A.begin(), A.begin() + N - 1, A.end()));

    cout << ans << endl;

    return 0;
} 
