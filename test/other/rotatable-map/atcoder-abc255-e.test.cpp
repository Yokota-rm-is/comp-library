#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc255/tasks/abc255_e"
// https://atcoder.jp/contests/abc255/submissions/66073016

#include "../../../other/rotatable-map.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll S(N - 1);
    rep(i, N - 1) cin >> S[i];
    
    vll X(M);
    rep(i, M) cin >> X[i];

    vll D(N - 1);
    D[0] = S[0];
    rep(i, 1, N - 1) D[i] = S[i] - D[i - 1];

    RotatableMap<ll, ll> mp0, mp1;
    rep(i, N - 1) {
        if (i % 2 == 0) mp0[D[i]] += 1;
        else mp1[D[i]] += 1;
    }

    ll ans = 0;

    rep(i, N) {
        rep(j, M) {
            ll a0;
            if (i == 0) a0 = X[j];
            else a0 = (X[j] - D[i - 1]) * ((i % 2 == 0) ? 1 : -1);

            mp0.subtract_key(a0);
            mp1.add_key(a0);

            ll cnt = 0;
            rep(k, M) {
                if (a0 == X[k]) cnt++;
            }

            rep(k, M) {
                if (mp0.contains(X[k])) cnt += mp0[X[k]];
                if (mp1.contains(X[k])) cnt += mp1[X[k]];
            }

            chmax(ans, cnt);
        
            mp0.add_key(a0);
            mp1.subtract_key(a0);
        }
    }

    cout << ans << endl;

    return 0;
} 