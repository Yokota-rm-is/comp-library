#define PROBLEM "https://atcoder.jp/contests/abc360/tasks/abc360_g"

#include "../../../other/lis-vector.cpp"
#include "../../../other/lds-vector.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];

    LISVector<ll> lis_l;
    LDSVector<ll> lds_r;
    repd(i, 1, N) lds_r.push_back(A[i]);

    ll ans = lds_r.size_lds() + 1;
    rep(i, N - 2) {
        lis_l.push_back(A[i]);
        lds_r.pop_back();
        if (lis_l.min_right(lis_l.size_lis()) + 1 < lds_r.max_right(lds_r.size_lds())) {
            chmax(ans, lis_l.size_lis() + lds_r.size_lds() + 1);
        } 
    }

    if (N - 2 >= 0) {
        lis_l.push_back(A[N - 2]);
        chmax(ans, lis_l.size_lis() + 1);
    }

    cout << ans << endl;

    return 0;
} 
