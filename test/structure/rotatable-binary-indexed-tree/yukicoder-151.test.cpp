#define PROBLEM "https://yukicoder.me/problems/no/151"

#include "../../../structure/rotatable-binary-indexed-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    RotatableBinaryIndexedTree<ll> to_left(N, 0), to_right(N, 0);
    while (Q--) {
        char t;
        ll y, z;
        cin >> t >> y >> z;

        if (t == 'L') {
            to_left.add(y, z);
        } 
        else if (t == 'R') {
            to_right.add(y, z);
        }
        else {
            ll ans = to_left.sum(y, z) + to_right.sum(y, z);
            cout << ans << endl;
        }

        ll l = to_left.get(0);
        to_left.set(0, 0);
        to_left.rotate_left(1);

        ll r = to_right.get(N - 1);
        to_right.set(N - 1, 0);
        to_right.rotate_right(1);

        to_left.add(N - 1, r);
        to_right.add(0, l);
    }

    return 0;
}