#define PROBLEM "https://atcoder.jp/contests/abc358/tasks/abc358_e"

#include "../../../math/combination.cpp"
#include "../../../math/modint.cpp"

const int MOD = 998244353;
using mint = Fp<MOD>;

int main() {
    ll K;
    cin >> K;

    vll C(26);
    fore(c, C) cin >> c;

    Combination<MOD> com;

    vector A(27, vector<mint>(K + 1, 0));
    A[0][0] = 1;

    rep(i, 26) {
        rep(j, K + 1) {
            rep(k, C[i] + 1) {
                if (j + k <= K) {
                    A[i + 1][j + k] += A[i][j] * com(j + k, k);
                }
                else break;
            }
        }
    }

    mint ans = 0;
    rep(i, 1, K + 1) ans += A[26][i];

    cout << ans << endl;

    return 0;
} 
