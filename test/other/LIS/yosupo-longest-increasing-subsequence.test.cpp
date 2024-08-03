#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../../../other/LIS.cpp"


int main() {
    ll N;
    cin >> N;

    vll A(N);
    fore(a, A) cin >> a;

    LIS<ll> lis(A);
    lis.solve();

    vll ans = lis.restore_indices();
    cout << ans.size() << endl;
    cout << ans << endl;    
}