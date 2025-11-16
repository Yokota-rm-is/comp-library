#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165"

#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    BinaryIndexedTree<ll> bit(N, 0);
    while (Q--) {
        ll l, k;
        cin >> l >> k;
        --l;

        bit.add(l, l + k, 1, 1);
    }

    rep(i, N) {
        cout << bit.get(i);
        if (i < N - 1) cout << " ";
    }
    cout << endl;

    return 0;
}