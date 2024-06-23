#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&"

#include "../../../structure/segment-tree-beats.cpp"

int main() {
    ll n, q;
    cin >> n >> q;
    
    SegmentTreeBeats<ll> tree(n, 0);

    while (q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y;
            cin >> x >> y;
            tree.apply_add(x - 1, y);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << tree.prod_sum(x - 1, y) << endl;
        }
    }

    return 0;
}