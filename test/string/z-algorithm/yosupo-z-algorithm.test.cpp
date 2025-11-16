#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../../string/z-algorithm.cpp"

int main() {
    string S;
    cin >> S;

    Zalgorithm z(S);
    cout << z.Z << endl;

    return 0;
}