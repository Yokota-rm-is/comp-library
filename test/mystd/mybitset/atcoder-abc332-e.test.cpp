#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc332/tasks/abc332_e"
// https://atcoder.jp/contests/abc332/submissions/60883645

#include "../../../mystd/mybitset.cpp"

int main() {
    ll N, D;
    cin >> N >> D;

    vll W(N);
    rep(i, N) cin >> W[i];

    vector dp(1 << N, vll(D + 1, inf64));
    rep(i, D + 1) dp[0][i] = 0;

    rep(bit, 1 << N) {
        ll sum = 0;

        rep(i, N) {
            if (bit & (1 << i)) {
                sum += W[i];
            }
        }

        dp[bit][1] = sum * sum;
    }

    rep(d, 2, D + 1) {
        auto f = [&](Bitset bit, Bitset sub, Bitset exclude) {
            chmin(dp[bit][d], dp[sub][1] + dp[exclude][d - 1]);
        };
    
        bitDP_subset(N, f);
    }

    ll sum = accumulate(W);
    
    double ans = (double)(dp[(1 << N) - 1][D] * D - sum * sum) / (D * D);

    cout << fixed << setprecision(10);  // 小数点以下を10桁表示，許容誤差が1e-N以下の時はN+1に変更すること(16桁以上はlong double)
    cout << ans << endl;

    return 0;
} 
