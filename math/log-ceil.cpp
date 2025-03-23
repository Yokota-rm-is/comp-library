#pragma once
#include "../base.cpp"

long long log_ceil(long long x, long long base) {
    if (x <= 1) return 0; // x が 1 以下の場合、結果は 0

    // powers[i] = n^(2^i) を格納するベクター
    vector<__int128_t> powers;
    powers.push_back(base);

    // powers の構築：powers.back() が x 以上になるまで繰り返す
    while (powers.back() < x) {
        __int128_t next_power = powers.back() * powers.back();
        powers.push_back(next_power);
    }

    // 指数の決定
    long long exponent = 0;
    __int128_t current_value = 1;

    // 上位ビットから探索
    for (int i = powers.size() - 1; i >= 0; --i) {
        __int128_t temp_value = current_value * powers[i];

        // temp_value が x 未満なら、指数と現在の値を更新
        if (temp_value < x) {
            exponent += (1LL << i);
            current_value = temp_value;
        }
    }

    // ceil の場合、最後に 1 を足す
    return exponent + 1;
}
