#pragma once
#include "../base.cpp"

// mainにis_okをおく
// auto is_ok = [&](auto x){return A[x] < K;};

// 汎用的な二分探索のテンプレ
template<typename T>
T binary_search(function<bool(T)> is_ok, T ok, T ng) {
    if (!is_ok(ok)) return -1;
    if (is_ok(ng)) return ng;

    long long ok_ll = bit_cast<long long>(ok), ng_ll = bit_cast<long long>(ng);

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok_ll - ng_ll) > 1ll) {
        T mid = midpoint(ok, ng);
        long long mid_ll = midpoint(ok_ll, ng_ll);

        if (is_ok(mid)) ok = mid, ok_ll = mid_ll;
        else ng = mid, ng_ll = mid_ll;
    }
    return ok;
}