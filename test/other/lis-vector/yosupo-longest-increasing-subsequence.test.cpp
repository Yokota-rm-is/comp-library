#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../../../other/lis-vector.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    fore(a, A) cin >> a;

    LISVector<ll> lis(A);

    vll B = lis.get_lis();
    cout << B.size() << endl;

    auto p = B.begin();
    rep(i, N) {
        if (p != B.end() and *p == A[i]) {
            cout << i;
            if (++p != B.end()) cout << " ";
            else cout << endl;
        }
    }
}