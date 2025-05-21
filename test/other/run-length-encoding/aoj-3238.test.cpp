#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3238"

#include "../../../other/run-length-encoding.cpp"

int main() {
    ll N;
    cin >> N;

    string S;
    cin >> S;

    auto s = encode(S);

    ll ans = 0;
    rep(i, 1, s.size() - 1) {
        if (s[i - 1].first == 'N' and s[i].first == 'A' and s[i + 1].first == 'N') ++ans;
    }

    cout << ans << endl;

    return 0;
}