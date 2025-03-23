#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../../math/log-ceil.cpp"

// log_ceil関数の検証関数
bool validate_log_ceil(long long x, long long base, long long ret) {
    __int128_t x_ = x;

    if (x == 1) {
        if (ret == 0) return true;

        cout << "Test failed for x = " << x << ", base = " << base << endl;
        cout << "Expected: " << 0 << " < " << x << " <= " << 1 << endl;
        cout << "Result: " << ret << endl;
    }
    else {
        // ret^n を計算
        __int128_t prev_power_n = binpow<__uint128_t>(base, ret - 1);
        __int128_t ret_power_n = binpow<__uint128_t>(base, ret);

        if (prev_power_n < x_ and x_ <= ret_power_n) return true;

        cout << "Test failed for x = " << x << ", base = " << base << endl;
        cout << "Expected: " << prev_power_n << " < " << x << " <= " << ret_power_n << endl;
        cout << "Result: " << ret << endl;
    }

    return false; // 条件 ret^n <= x < (ret+1)^n を満たす
}

int main() {
    // テストケースの範囲
    const unsigned long long x_min = 1;
    const unsigned long long x_max = 1e18;
    const unsigned long long base_min = 10;
    const unsigned long long base_max = 1e18;

    bool all_tests_passed = true;

    // 各範囲をループ
    for (unsigned long long x = x_min; x <= x_max; x *= 10) { // xを10倍ずつ増やしてテスト
        for (unsigned long long base = base_min; base <= base_max; base *= 10) {
            // root_floor関数の出力
            long long fast_result = log_ceil((long long)x, base);
            all_tests_passed &= validate_log_ceil((long long)x, base, fast_result);
        }
    }

    // ランダムテストの設定
    const int random_test_count = 1000;
    mt19937_64 rng(0); // seed = 0
    uniform_int_distribution<long long> dist_x(x_min, x_max);
    uniform_int_distribution<long long> dist_base(base_min, base_max);

    // ランダムテスト
    for (int i = 0; i < random_test_count; ++i) {
        long long x = dist_x(rng);
        int base = dist_base(rng);

        // root_floor関数の出力
        long long fast_result = log_ceil(x, base);
        all_tests_passed &= validate_log_ceil(x, base, fast_result);
    }

    if (all_tests_passed) {
        cout << "Hello World" << endl;
    }

    return 0;
}
