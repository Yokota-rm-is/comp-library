#define PROBLEM "https://atcoder.jp/contests/abc370/tasks/abc370_e"

#include "../../../other/rotatable-map.cpp"
#include "../../../math/modint.cpp"

using mint = mint998;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    RotatableMap<ll, mint> rm;
    rm[0] = 1;

    mint ans = 0, sum = 1;

    rep(i, N) {
        rm.add_key(A[i]);
        
        mint ans_i = sum;
        if (rm.contains(K)) ans_i -= rm[K];
        ans = ans_i;

        sum += ans_i;
        rm[0] += ans_i;
    }

    cout << ans << endl;

    return 0;
} 