#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_ar"
// https://atcoder.jp/contests/typical90/submissions/58174978

#include "../../../other/rotatable-vector.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll A(N);
    rep(i, N) cin >> A[i];

    RotatableVector<ll> rv(A);

    while (Q--) {
        ll t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            swap(rv[x - 1], rv[y - 1]);
        } 
        else if (t == 2) {
            rv.rotate_right();
        } 
        else {
            cout << rv[x - 1] << endl;
        }
    }

    return 0;
}