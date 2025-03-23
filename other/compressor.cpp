#pragma once
#include "../base.cpp"

// EraseDuplicate: falseのとき，重複する要素を別の要素として扱う
// Accending: 重複する要素をどちらの方向に割り当てるか
template <typename T, bool EraseDuplicate = true, bool Accending = true>
struct Compressor {
    vector<T> original, values;
    vector<long long> compressed;
    unordered_map<T, long long> remap, count;

    Compressor() {}
    Compressor(const vector<T>& v) {
        init(v);
    }

    void init(const vector<T>& v) {
        original = v;
        values = v;

        sort(values.begin(), values.end());
        if (EraseDuplicate) {
            values.erase(unique(values.begin(), values.end()), values.end());
            compressed.resize(original.size());
        }

        rep(i, original.size()) {
            if (EraseDuplicate) compressed[i] = std::lower_bound(values.begin(), values.end(), original[i]) - values.begin();
            else {
                if (Accending) compressed[i] = std::lower_bound(values.begin(), values.end(), original[i]) - values.begin() + count[original[i]];
                else compressed[i] = std::upper_bound(values.begin(), values.end(), original[i]) - values.begin() - count[original[i]] - 1;
            }

            if (!remap.contains(original[i])) remap[original[i]] = compressed[i];
            ++count[original[i]];
        }
    }

    // xを圧縮後の値に変換
    long long compress(T x) {
        assert(remap.contains(x));
        return remap[x];
    }

    // xを圧縮後の値に変換
    long long operator()(T x) {
        return compress(x);
    }

    // xを圧縮後の値に変換
    long long find(T x) {
        return compress(x);
    }

    long long size() {
        return (long long)values.size();
    }

    long long lower_bound(T x) {
        return std::lower_bound(values.begin(), values.end(), x) - values.begin();
    }

    long long upper_bound(T x) {
        return std::upper_bound(values.begin(), values.end(), x) - values.begin();
    }

    bool contains(T x) {
        return remap.contains(x);
    }

    // コンストラクト時の配列のpos番目の値を取得
    T operator[](long long pos) {
        return compressed[pos];
    }

    // comp後の値から元の値を取得
    T retrieve(long long k) {
        return values[k];
    }
};