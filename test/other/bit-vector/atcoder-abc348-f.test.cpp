#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc348/tasks/abc348_f"
// https://atcoder.jp/contests/abc348/submissions/65406323

#include "../../../other/bit-vector.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vvll A(N, vll(M));
    rep(i, N) rep(j, M) cin >> A[i][j];

    vector B(M, vector(1000, BitVector<>(N, 0)));
    rep(j, M) rep(i, N) {
        B[j][A[i][j]].set(i, 1);
    }

    ll ans = 0;

    rep(i, 1, N) {
        BitVector bv(i, 0);
            
        rep(j, M) {
            bv ^= B[j][A[i][j]].get(0, i);
        }

        ans += bv.bit_count();
    }

    cout << ans << endl;

    return 0;
} 
