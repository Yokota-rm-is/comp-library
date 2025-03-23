#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../../math/root-floor.cpp"

string to_string(__int128_t x) {
    string ret;
    while (x > 0) {
        ret += (char)('0' + x % 10);
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

// root_floor関数の検証関数
bool validate_root_floor(long long x, long long n, long long ret) {
    __int128_t x_ = x;

    // ret^n を計算
    __int128_t ret_power_n = binpow<__uint128_t>(ret, n);
    __int128_t next_power_n = binpow<__uint128_t>(ret + 1, n);

    if (ret_power_n <= x_ and x_ < next_power_n) return true;

    cout << "Test failed for x = " << x << ", n = " << n << endl;
    cout << "Expected: " << to_string(ret_power_n) << " <= " << x << " < " << to_string(next_power_n) << endl;
    cout << "Result: " << ret << endl;

    return false; // 条件 ret^n <= x < (ret+1)^n を満たす
}

int main() {
    // テストケースの範囲
    const unsigned long long x_min = 1;
    const unsigned long long x_max = 1e18;
    const int n_min = 1;
    const int n_max = 100;

    bool all_tests_passed = true;

    // 各範囲をループ
    for (unsigned long long x = x_min; x <= x_max; x *= 10) { // xを10倍ずつ増やしてテスト
        for (int n = n_min; n <= n_max; n++) {
            // root_floor関数の出力
            long long fast_result = root_floor((long long)x, n);
            all_tests_passed &= validate_root_floor((long long)x, n, fast_result);
        }
    }

    // ランダムテストの設定
    const int random_test_count = 1000;
    mt19937_64 rng(0); // seed = 0
    uniform_int_distribution<long long> dist_x(x_min, x_max);
    uniform_int_distribution<int> dist_n(n_min, n_max);

    // ランダムテスト
    for (int i = 0; i < random_test_count; ++i) {
        long long x = dist_x(rng);
        int n = dist_n(rng);

        // root_floor関数の出力
        long long fast_result = root_floor(x, n);
        all_tests_passed &= validate_root_floor(x, n, fast_result);
    }

    if (all_tests_passed) {
        cout << "Hello World" << endl;
    }

    return 0;
}
