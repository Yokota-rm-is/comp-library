#define PROBLEM "https://atcoder.jp/contests/abc275/tasks/abc275_d"

#include "../../../search/memoization.cpp"

struct F : Memoization<long long, long long> {
    F() {};

    long long f(long long key) {
        if (key == 0) return 1;

        return get(floor(key, 2)) + get(floor(key, 3));
    }
};

int main() {
    ll N;
    cin >> N;

    F f;
    cout << f.f(N) << endl;
}