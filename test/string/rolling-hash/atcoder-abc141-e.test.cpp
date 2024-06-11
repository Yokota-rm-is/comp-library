#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"

#include "../../../string/rolling-hash.cpp"

int main() {
    ll N;
    cin >> N;

    string S;
    cin >> S;

    RollingHash rh(S);
    ll ans = 0;
    rep(i, N) rep(j, i + 1, N) {
        ll lcp = rh.lcp(i, j, j, N);
        chmax(ans, lcp);
    }

    cout << ans << endl;

    return 0;
} 
