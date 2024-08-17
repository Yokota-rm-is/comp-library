#pragma once
#include "../base.cpp"

template <typename T>
struct Node {
    T value;
    long long freq;

    Node(T v, long long f = 0) : value(v), freq(f) {};

    operator T() const {
        return value;
    }

    bool operator< (const Node &other) const {
        if (freq == other.freq) return value < other.value;
        return freq < other.freq;
    }
};

template<typename T>
struct SqrtDecomposition {
    using S = Node<T>;

    long long _N, N, sqrtN, K;
    
    vector<S> node;
    vector<vector<S>> bucket;
    vector<long long> rank;
    unordered_map<T, vector<long long>> indices;

    T e = inf64;

    SqrtDecomposition(long long n) : _N(n) {
        vector<T> v(n, 0);
        init(v);
    }

    SqrtDecomposition(long long n, T a) : _N(n) {
        vector<T> v(n, a);
        init(v);
    }

    SqrtDecomposition(vector<T> &v) : _N(v.size()) {
        init(v);
    }

    void init(vector<T> &a) {
        sqrtN = 1;
        while ((sqrtN + 1) * (sqrtN + 1) < _N) ++sqrtN;

        K = (_N + sqrtN - 1) / sqrtN;
        N = K * sqrtN;
        
        node.assign(N, e);
        rank.assign(N, -1);
        rep(i, _N) {
            node[i] = S(a[i], 1);
            indices[a[i]].push_back(i);
            rank[i] = indices[a[i]].size() - 1;
        }

        bucket.assign(K + 1, vector<S>(K + 1, S(e, 0)));
        rep(l, K) {
            unordered_map<T, long long> freq;
            S sm(e, 0);

            rep(r, l + 1, K + 1) {
                rep(i, (r - 1) * sqrtN, r * sqrtN) {
                    if (i >= _N) break;
                    T v = node[i].value;
                    freq[v] += node[i].freq;

                    if (freq[v] > sm.freq) {
                        sm.value = v;
                        sm.freq = freq[v];
                    }
                }
                bucket[l][r] = sm;
            }
        }
    }
    
    // [l, r)
    S query(long long l, long long r) {
        long long lk = ceil(l, sqrtN), rk = floor(r, sqrtN);
        S sm = bucket[lk][rk];

        rep(i, l, min(r, (l / sqrtN + 1) * sqrtN)) {
            T v = node[i].value;
            long long idx;

            while ((idx = rank[i] + sm.freq) < (long long)indices[v].size() and indices[v][idx] < r) {
                sm.value = v;
                sm.freq += 1;
            }
        }

        repd(i, max(l, (r / sqrtN) * sqrtN), r) {
            T v = node[i].value;
            long long idx;

            while ((idx = rank[i] - sm.freq) >= 0 and indices[v][idx] >= l) {
                sm.value = v;
                sm.freq += 1;
            }
        }

        return sm;
    }
};
