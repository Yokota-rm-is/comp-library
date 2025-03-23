#pragma once
#include "../base.cpp"

// floor(log_n(x)) を計算する関数
long long log_floor(long long x, long long base) {
    // powers[i] = n^(2^i) を格納するベクター
    vector<__int128_t> powers;
    powers.push_back(base);

    // powers の構築：powers.back() が x を超えるまで繰り返す
    while (powers.back() <= x) {
        __int128_t next_power = powers.back() * powers.back();
        powers.push_back(next_power);
    }

    // 指数の決定
    long long exponent = 0;
    __int128_t current_value = 1;

    // 上位ビットから探索
    for (int i = powers.size() - 1; i >= 0; --i) {
        __int128_t temp_value = current_value * powers[i];

        // temp_value が x 以下なら、指数と現在の値を更新
        if (temp_value <= x) {
            exponent += (1LL << i);
            current_value = temp_value;
        }
    }

    return exponent;
}