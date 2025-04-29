#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "../../../string/rolling-hash-on-binary-indexed-tree.cpp"

int main() {
    string T, P;
    cin >> T >> P;

    RollingHashonBinaryIndexedTree rht(T), rhp(P);
    rep(i, T.size() - P.size() + 1) {
        if (rht.get(i, i + P.size()) == rhp.get(0, P.size())) {
            cout << i << endl;
        }
    }

    return 0;
} 
