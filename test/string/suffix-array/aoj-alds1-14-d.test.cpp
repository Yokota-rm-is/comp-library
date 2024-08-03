#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D"

#include "../../../string/suffix-array.cpp"


int main() {
    string S;
    cin >> S;
    ll Q;
    cin >> Q;

    SuffixArray sa(S);
    while (Q--) {
        string T;
        cin >> T;

        cout << sa.contains(T) << endl;
    }

    return 0;
}