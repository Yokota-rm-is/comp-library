#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp"

#include "../../../string/rolling-hash.cpp"

int main() {
    string T, P;
    cin >> T >> P;

    RollingHash rht(T), rhp(P);
    rep(i, T.size() - P.size() + 1) {
        if (rht.get(i, i + P.size()) == rhp.get(P.size())) {
            cout << i << endl;
        }
    }

    return 0;
} 
