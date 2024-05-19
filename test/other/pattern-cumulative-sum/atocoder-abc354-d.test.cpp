#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc354/tasks/abc354_d"

#include "../../../other/pattern-cumulative-sum.cpp"

int main() {
    long long A;
    cin >> A;
    long long B;
    cin >> B;
    long long C;
    cin >> C;
    long long D;
    cin >> D;

    vector<vector<ll>> pattern(2, vector<ll>(4, 0));
    pattern[0][0] = 2;
    pattern[0][1] = 1;
    pattern[0][2] = 0;
    pattern[0][3] = 1;
    pattern[1][0] = 1;
    pattern[1][1] = 2;
    pattern[1][2] = 1;
    pattern[1][3] = 0;

    PatternCumulativeSum<ll> pcs(pattern);
    ll ans = pcs.sum(A, B, C, D);

    cout << ans << endl;

    return 0;
}