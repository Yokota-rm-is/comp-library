#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc386/tasks/abc386_e"

#include "../../../search/foreach-combination.cpp"

int main() {
    ll N, K;
    cin >> N >> K;

    vll A(N);
    rep(i, N) cin >> A[i];
    
    ull x = 0, ans = 0;
    if (K <= N / 2) {
        auto apply_xor = [&](ll i) {
            x ^= A[i];
        };

        auto f = [&](vll& indices) {
            chmax(ans, x);
        };

        foreach_comb(N, K, f, apply_xor, apply_xor);
    } 
    else {
        ull xor_sum = 0;
        rep(i, N) xor_sum ^= A[i];

        auto apply_xor = [&](ll i) {
            xor_sum ^= A[i];
        };

        auto f = [&](vll& indices) {
            chmax(ans, xor_sum ^ x);
        };

        foreach_comb(N, N - K, f, apply_xor, apply_xor);
    }

    cout << ans << endl;

    return 0;
} 
