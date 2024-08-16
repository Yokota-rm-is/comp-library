#define PROBLEM "https://yukicoder.me/problems/no/789"

#include "../../../structure/dynamic-binary-indexed-tree.cpp"

int main() {
    ll n;
    cin >> n;

    DynamicBinaryIndexedTree<ll> bit(1e9 + 1);

    ll ans = 0;

    while (n--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y;
            cin >> x >> y;

            bit.add(x, y);
        }
        else {
            ll l, r;
            cin >> l >> r;

            ans += bit.sum(l, r + 1);
        }
    }

    cout << ans << endl;

    return 0;
}