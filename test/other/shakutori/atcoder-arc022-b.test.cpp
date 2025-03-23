#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc022/tasks/arc022_2"
// https://atcoder.jp/contests/arc022/submissions/63315479

#include "../../../other/shakutori.cpp"

template <typename T>
struct CountMap {
    map<T, ll> mp_single, mp_multiple;

    void insert(T value) {
        if (mp_multiple.count(value)) {
            mp_multiple[value]++;
        }
        else if (mp_single.count(value)) {
            mp_single.erase(value);
            mp_multiple[value] = 2;
        }
        else {
            mp_single[value]++;
        }
    }

    void erase(T value) {
        if (mp_multiple.count(value)) {
            mp_multiple[value]--;
            if (mp_multiple[value] == 0) mp_multiple.erase(value);
            else if (mp_multiple[value] == 1) {
                mp_multiple.erase(value);
                mp_single[value]++;
            }
        }
        else {
            mp_single[value]--;
            if (mp_single[value] == 0) mp_single.erase(value);
        }
    }

    bool contains_multiple_item() const {
        return !mp_multiple.empty();
    }
};

int main() {
    ll N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];

    using T = CountMap<ll>;

    auto e = [&]() { return T(); };
    auto insert = [&](T& value, ll idx) {
        value.insert(A[idx]);
    };
    auto judge = [&](const T& value) { 
        return !value.contains_multiple_item();
    };
    auto erase = [&](T& value, ll idx) {
        value.erase(A[idx]);
    };

    cout << shakutori_max_range<T>(N, e, insert, judge, erase) << endl;

    return 0;
}