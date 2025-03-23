#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc033/tasks/arc033_3"
// https://atcoder.jp/contests/arc033/submissions/60114708

#include "../../../structure/binary-indexed-tree.cpp"

int main() {
    long long Q;
    cin >> Q;

    BinaryIndexedTree tree(2e5 + 1);
    
    while (Q--) {
        ll t, x;
        cin >> t >> x;
        
        if (t == 1) {
            tree.add(x, 1);
        }
    
        if (t == 2) {
            ll index = tree.lower_bound(x);
            cout << index - 1 << endl;
            tree.add(index - 1, -1);
        }
    } 

    return 0;
}