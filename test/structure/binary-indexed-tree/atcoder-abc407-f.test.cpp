#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc407/tasks/abc407_f"
// https://atcoder.jp/contests/abc407/submissions/66142172

#include "../../../structure/binary-indexed-tree.cpp"
#include "../../../structure/segment-tree.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];
    PointAddRangeMax<ll, ll> tree(A);
    BinaryIndexedTree<> bit(N, 0);

    rep(i, N) {
        ll a = A[i];

        auto F = [&](Node<ll> node) {
            return node.value <= a;
        };
        ll r = tree.max_right(i, F);

        auto G = [&](Node<ll> node) {
            return node.value < a;
        };
        ll l = tree.min_left(i, G);

        bit.add(0, r - l, a * (i - l + 1));
        bit.add(0, i - l, -a * (i - l), a);
        bit.add(r - i, r - l, -a, -a); 
    }

    rep(i, N) {
        cout << bit.get(i) << endl;
    }  

    return 0;
} 