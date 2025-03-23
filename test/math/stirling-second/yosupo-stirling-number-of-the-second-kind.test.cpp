#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include "../../../math/stirling-second.cpp"

int main() {
    ll N;
    cin >> N;

    StirlingSecond<998244353> stirling(N);

    vll ans;
    rep(i, N + 1) {
        ans.push_back(stirling.get(N, i));
    }

    cout << ans << endl;

    return 0;
}