#define PROBLEM "https://atcoder.jp/contests/abc113/tasks/abc113_c"

#include "../../../base.cpp"

int main() {
    ll N, M;
    cin >> N >> M;
    
    vll P(M), Y(M);
    rep(i, M) cin >> P[i] >> Y[i];

    map<ll, vll> mp;
    rep(i, M) {
        mp[P[i]].push_back(Y[i]);
    }

    fore(p, mp) {
        p.second = compress(p.second, false);
        reverse(p.second);
    }

    rep(i, M) {
        cout << zero_padding(P[i], 6) << zero_padding(mp[P[i]].back() + 1, 6) << endl;
        mp[P[i]].pop_back();
    }

    return 0;
}