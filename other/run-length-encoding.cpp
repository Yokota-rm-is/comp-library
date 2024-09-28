#pragma once
#include "../base.cpp"

template <typename T>
vector<pair<T, ll>> encode(vector<T>& A) {
    vector<pair<T, ll>> ret;
    ll N = A.size();
    rep(i, N) {
        if (ret.empty() || ret.back().first != A[i]) {
            ret.emplace_back(A[i], 1);
        } 
        else {
            ret.back().second++;
        }
    }
    return ret;
}

vector<pair<char, ll>> encode(string& S) {
    vector<pair<char, ll>> ret;
    ll N = S.size();
    rep(i, N) {
        if (ret.empty() || ret.back().first != S[i]) {
            ret.emplace_back(S[i], 1);
        } 
        else {
            ret.back().second++;
        }
    }
    return ret;
}

template<typename T>
vector<T> decode(vector<pair<T, ll>>& A) {
    vector<T> ret;
    for (auto [a, b] : A) {
        rep(i, b) ret.push_back(a);
    }
    return ret;
}

string decode(vector<pair<char, ll>>& S) {
    string ret;
    for (auto [a, b] : S) {
        rep(i, b) ret.push_back(a);
    }
    return ret;
}