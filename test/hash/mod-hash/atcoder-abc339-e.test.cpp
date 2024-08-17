#define PROBLEM "https://atcoder.jp/contests/abc339/tasks/abc339_f"

#include "../../../hash/mod-hash.cpp"
#include "../../../mystd/mymultiset.cpp"

int main() {
   ll N;
    cin >> N;

    vector<string> A(N);
    rep(i, N) cin >> A[i];

    MultiSet<ModHash> ms;

    vector<ModHash> B;
    rep(i, N) {
        ModHash mh(A[i]);
        ms.insert(mh);
        B.push_back(mh);
    }

    ll ans = 0;
    rep(i, N) rep(j, N) {
        ModHash mh = B[i] * B[j];
        ans += ms.count(mh);
    }

    cout << ans << endl;

    return 0;
} 