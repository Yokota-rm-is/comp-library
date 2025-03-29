#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc331/tasks/abc331_f"
// https://atcoder.jp/contests/abc331/submissions/64350046

#include "../../../string/rolling-hash-on-segment-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    RollingHashonSegmentTree tree(S);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll x;
            cin >> x;
            --x;

            char c;
            cin >> c;

            tree.set(x, c);
        }
        else {
            ll L, R;
            cin >> L >> R;
            --L;

            cout << YesNo(tree.prod(L, R).is_palindrome()) << endl;
        }
    }

    return 0;
} 
