#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc284/tasks/abc284_f"
// https://atcoder.jp/contests/abc284/submissions/64151714

#include "../../../string/rolling-hash.cpp"

int main() {
    ll N;
    cin >> N;

    string T;
    cin >> T;

    RollingHash rh(T);
    rep(i, N + 1) {
        Hash61 S = rh.erase(i, i + N);
        Hash61 U = rh.get(i, i + N);
        if (S == U.reverse()) {
            cout << T.substr(0, i) + T.substr(i + N) << endl;
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
} 
