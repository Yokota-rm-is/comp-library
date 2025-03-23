#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc038/tasks/abc038_c"
// https://atcoder.jp/contests/abc038/submissions/63315290

#include "../../../other/shakutori.cpp"

int main() {
    ll N;
    cin >> N;

    vll a(N);
    rep(i, N) cin >> a[i];

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    using T = deque<pll>;

    auto e = [&]() { return T(); };
    auto insert = [&](T& value, ll idx) {
        value.emplace_back(idx, a[idx]);
    };
    auto judge = [&](const T& value) { 
        if (value.size() <= 1) return true;
        return value[value.size() - 2].second < value[value.size() - 1].second; 
    };
    auto erase = [&](T& value, ll idx) {
        if (value.front().first == idx) value.pop_front();
        else if (value.back().first == idx) value.pop_back();
        else assert(false);
    };

    cout << shakutori_inner_count<T>(N, e, insert, judge, erase) << endl;

    return 0;
}