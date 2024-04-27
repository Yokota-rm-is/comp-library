#define PROBLEM "https://atcoder.jp/contests/abc109/tasks/abc109_c"

#include "../../base.cpp"

int main() {
    ll N, X;
    cin >> N >> X;

    vll x(N);
    rep(i, N) cin >> x[i];
    
    vll L, R;
    rep(i, N) {
        if (x[i] > X) R.push_back(x[i] - X);
        else L.push_back(X - x[i]);
    }

    ll ans = gcd(gcd(L), gcd(R));

    cout << ans << endl;

    return 0;
}