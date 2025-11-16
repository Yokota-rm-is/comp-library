#define PROBLEM "https://yukicoder.me/problems/no/430"

#include "../../../string/aho-corasick.cpp"

int main() {
    string S;
    cin >> S;

    ll M;
    cin >> M;
    
    vector<string> C(M);
    rep(i, M) cin >> C[i];

    AhoCorasick<26, 'A'> aho;
    rep(i, M) {
        aho.add(C[i], i);
    }
    aho.build();

    cout << aho.move(S).first << endl;

    return 0;
}