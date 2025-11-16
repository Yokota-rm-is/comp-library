#pragma once
#include "../base.cpp"

struct Zalgorithm {
    string S;
    vector<long long> Z;

    Zalgorithm(const string& s) : S(s) {
        build();
    }

    void build() {
        long long N = S.size();
        Z.assign(N, 0);
        Z[0] = N;

        long long i = 1, j = 0;
        while (i < N) {
            while (i + j < N and S[j] == S[i + j]) j++;
            Z[i] = j;

            if (j == 0) {
                i++;
                continue;
            }

            long long k = 1;
            while (i + k < N and k + Z[k] < j) {
                Z[i + k] = Z[k];
                k++;
            }

            i += k;
            j -= k;
        }
    }

    long long operator[](long long i) {
        return Z[i];
    }

    long long lcp(long long i) {
        return Z[i];
    }
};