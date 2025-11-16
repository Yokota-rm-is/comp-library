#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc287/tasks/abc287_g"
// https://atcoder.jp/contests/abc287/submissions/67883571

#include "../../../mystd/myset.cpp"

int main() {
    ll N;
    cin >> N;

    vll a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    MultiSet<ll> ms;
    rep(i, N) {
        ms.insert(a[i], b[i]);
    }

    ll Q;
    cin >> Q;

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll x, y;
            cin >> x >> y;
            --x;

            ms.erase(a[x], b[x]);
            a[x] = y;
            ms.insert(a[x], b[x]);
        }
        else if (t == 2) {
            ll x, y;
            cin >> x >> y;
            --x;

            ms.erase(a[x], b[x]);
            b[x] = y;
            ms.insert(a[x], b[x]);
        }
        else {
            ll x;
            cin >> x;

            if (ms.size() < x) {
                cout << -1 << endl;
            }
            else {
                cout << ms.sum_max_k(x) << endl;
            }
        }
    }

    return 0;
} 
