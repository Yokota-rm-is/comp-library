#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc331/tasks/abc331_f"
// https://atcoder.jp/contests/abc331/submissions/65344239

#include "../../../string/rolling-hash-on-binary-indexed-tree.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    RollingHashonBinaryIndexedTree bit(S);

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll x;
            cin >> x;
            --x;

            char c;
            cin >> c;

            bit.set(x, c);
        }
        else {
            ll L, R;
            cin >> L >> R;
            --L;

            cout << YesNo(bit.get(L, R).is_palindrome()) << endl;
        }
    }

    return 0;
} 
