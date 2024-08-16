#pragma once
#include "../base.cpp"

template <typename T, bool Unique = false, bool Accending = true>
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
        if (!Unique) {
            values.erase(unique(values.begin(), values.end()), values.end());
            compressed.resize(original.size());
        }

        rep(i, original.size()) {
            if (!Unique) compressed[i] = std::lower_bound(values.begin(), values.end(), original[i]) - values.begin();
            else {
                if (Accending) compressed[i] = std::lower_bound(values.begin(), values.end(), original[i]) - values.begin() + count[original[i]];
                else compressed[i] = std::upper_bound(values.begin(), values.end(), original[i]) - values.begin() - count[original[i]] - 1;
            }

            if (!remap.contains(original[i])) remap[original[i]] = compressed[i];
            ++count[original[i]];
        }
    }

    long long find(T x) {
        assert(remap.contains(x));
        return remap[x];
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

    T operator[](long long pos) {
        return compressed[pos];
    }

    T retrieve(long long k) {
        return values[k];
    }
};