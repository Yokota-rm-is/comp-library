#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc358/tasks/abc358_d"

#include "../../../mystd/mymultiset.cpp"

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);

    fore(a, A) cin >> a;
    fore(b, B) cin >> b;

    MultiSet<ll> ms;
    rep(i, N) ms.insert(A[i]);

    ll ans = 0;

    rep(i, M) {
        ll key = B[i];
        auto p = ms.find_greater_than_or_equal(key);
        if (p == ms.end()) {
            cout << -1 << endl;
            return 0;
        }
        ans += p->first;
        ms.erase(p->first);
    }

    cout << ans << endl;

    return 0;
} 
