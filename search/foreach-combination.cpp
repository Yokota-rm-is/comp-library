#pragma once
#include "../base.cpp"

// 参考: https://kamino.hatenablog.com/entry/cpp-permutation-combination
void recursive_comb(vector<long long>& indices, long long idx, long long rest, function<void(vll&)> f, function<void(ll)> insert, function<void(ll)> erase) {
    if (rest == 0) {
        f(indices);
    } 
    else {
        if (idx < 0) return;

        recursive_comb(indices, idx - 1, rest, f, insert, erase);
        indices[rest - 1] = idx;
        insert(idx);  // i番目の要素を加える処理
        recursive_comb(indices, idx - 1, rest - 1, f, insert, erase);
        erase(idx);   // i番目の要素を外す処理
    }
}

// nCkの組み合わせを全探索し，それぞれに対して関数fを適用する
// 探索する個数はnCk通りなので，O(nCk) * O(f)
// insert(i)はi番目の要素を加える処理
// erase(i)はi番目の要素を外す処理
void foreach_comb(long long N, long long K, function<void(vll&)> f, function<void(ll)> insert = [](ll x) {}, function<void(ll)> erase = [](ll x) {}) {
    vll indices(K);
    recursive_comb(indices, N - 1, K, f, insert, erase);
}
