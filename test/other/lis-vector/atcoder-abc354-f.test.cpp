#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc354/tasks/abc354_f"
// https://atcoder.jp/contests/abc354/submissions/62402036

#include "../../../other/lis-vector.cpp"
#include "../../../other/lds-vector.cpp"

int main() {
    ll T;
    cin >> T;

    while (T--) {
        ll N;
        cin >> N;

        vll A(N);
        rep(i, N) cin >> A[i];

        LISVector<ll> lis;
        LDSVector<ll> lds;
        repd(i, N) lds.push_back(A[i]);

        ll L = lds.size_lds();

        vll ans;
        rep(i, N) {
            ll a = A[i];
            lds.pop_back();

            ll l = lis.size_lis_fixed_right(a);
            ll r = lds.size_lds_fixed_right(a);

            if (l + r - 1 == L) ans.push_back(i);

            lis.push_back(a);
        }

        cout << ans.size() << endl;
        ++ans;
        cout << ans << endl;
    }

    return 0;
} 
