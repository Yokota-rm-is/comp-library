#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/past17-open/tasks/past17_e"

#include "../../../other/run-length-encoding.cpp"

int main() {
    string S;
    cin >> S;

    auto comp = encode(S);

    rep(i, comp.size()) {
        cout << comp[i].first << " " << comp[i].second;
        if (i + 1 < comp.size()) cout << " ";
    }

    return 0;
}