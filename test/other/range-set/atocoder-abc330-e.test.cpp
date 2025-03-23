#define PROBLEM "https://atcoder.jp/contests/abc330/tasks/abc330_e"

#include "../../../other/range-set.cpp"
#include "../../../mystd/mymultiset.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll A(N);
    rep(i, N) cin >> A[i];

    RangeSet<ll> rs;
    MultiSet<ll> ms;

    rep(i, N) {
        if (!ms.contains(A[i])) {
            rs.insert(A[i]);
        }
        ms.insert(A[i]);
    }

    while (Q--) {
        ll i, x;
        cin >> i >> x;

        --i;
        if (ms.count(A[i]) == 1) {
            rs.erase(A[i]);
        }
        ms.erase(A[i]);

        A[i] = x;
        if (!ms.contains(A[i])) {
            rs.insert(A[i]);
        }
        ms.insert(A[i]);

        cout << rs.mex() << endl;
    }

    return 0;
} 
