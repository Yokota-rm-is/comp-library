#define PROBLEM "https://atcoder.jp/contests/abc259/tasks/abc259_c"

#include "../../../other/run-length-encoding.cpp"

int main() {
    string S, T;
    cin >> S >> T;

    auto s = encode(S);
    auto t = encode(T);

    string ans = "Yes";
    if (s.size() != t.size()) {
        ans = "No";
    }
    else {
        rep(i, s.size()) {
            if (s[i].first != t[i].first) ans = "No";
            else {
                if (s[i].second == 1 and t[i].second > 1) ans = "No";
                else if (s[i].second > t[i].second) ans = "No";
            }
        }
    }

    cout << ans << endl;

    return 0;
}