#pragma once
#include "../base.cpp"

void recursive_partition_at_most(vector<vector<long long>>& indices, long long K, long long idx, function<void(vvll&)> f, function<void(ll, ll)> insert, function<void(ll, ll)> erase) {
    if (idx == -1) {
        f(indices);
        return;
    }

    rep(i, indices.size()) {
        insert(i, idx);
        indices[i].push_back(idx);
        recursive_partition_at_most(indices, K, idx - 1, f, insert, erase);
        indices[i].pop_back();
        erase(i, idx);
    }

    if (indices.size() < K) {
        insert(indices.size(), idx);
        indices.push_back({idx});
        recursive_partition_at_most(indices, K, idx - 1, f, insert, erase);
        indices.pop_back();
        erase(indices.size(), idx);
    }
}

// 区別可能なN個の要素をK個以下のグループに分割する方法を全探索し，それぞれに対して関数fを適用する
// 探索する個数はベル数となるので，O(Bell(N, K)) * O(f)
// insert(i, idx)はi番目のグループにidx番目の要素を追加する処理
// erase(i, idx)はi番目のグループからidx番目の要素を削除する処理
void foreach_partition_at_most(long long N, long long K, function<void(vvll&)> f, function<void(ll, ll)> insert = [](ll, ll){}, function<void(ll, ll)> erase = [](ll, ll){}) {
    vector<vector<long long>> indices;
    recursive_partition_at_most(indices, K, N - 1, f, insert, erase);
}