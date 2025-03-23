#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc032/tasks/abc032_c"
// https://atcoder.jp/contests/abc032/submissions/63315126

#include "../../../other/shakutori.cpp"

int main() {
    ll N, K;
    cin >> N >> K;

    vll s(N);
    rep(i, N) cin >> s[i];
    
    rep(i, N) {
        if (s[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }

    if (K == 0) {
        cout << 0 << endl;
        return 0;
    }

    auto e = [&]() { return 1ll; };
    auto insert = [&](ll& value, ll idx) { value *= s[idx]; };
    auto judge = [&](const ll& value) { return value <= K; };
    auto erase = [&](ll& value, ll idx) { value /= s[idx]; };

    cout << shakutori_max_range<ll>(N, e, insert, judge, erase) << endl;

    return 0;
}