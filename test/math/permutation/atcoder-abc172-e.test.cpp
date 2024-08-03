#define PROBLEM "https://atcoder.jp/contests/abc172/tasks/abc172_e"

#include "../../../math/combination.cpp"
#include "../../../math/permutation.cpp"
#include "../../../math/modint.cpp"

const int MOD = 1000000007;
using mint = mint007;

int main() {
    ll N, M;
    cin >> N >> M;

    Combination<MOD> com;
    Permutation<MOD> perm;
    mint ans = 0;

    rep(i, 1, N + 1) {
        mint count = com(N, i) * perm(M - i, N - i);
        if (i % 2 == 1) ans += count;
        else ans -= count;
    }

    ans *= perm(M, N);
    ans = mint(perm(M, N) * perm(M, N)) - ans;

    cout << ans << endl;

    return 0;
} 
