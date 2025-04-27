#pragma once
#include "../base.cpp"

// mainにis_okをおく
// auto is_ok = [&](auto x){return A[x] < K;};

template<typename T>
T binary_search(function<bool(T)> is_ok, T ok, T ng) {
    if (!is_ok(ok)) return -1;
    if (is_ok(ng)) return ng;

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1ll) {
        T mid = midpoint(ok, ng);

        if (is_ok(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

template<>
double binary_search(function<bool(double)> is_ok, double ok, double ng) {
    if (!is_ok(ok)) return -1;
    if (is_ok(ng)) return ng;

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    rep(i, 64) {
        double mid = (ok + ng) / 2;

        if (is_ok(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}