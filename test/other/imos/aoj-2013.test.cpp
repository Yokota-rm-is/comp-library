#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2013"

#include "../../../other/imos.cpp"

ll hhmmss2sec(const string &S) {
    ll h = stoll(S.substr(0, 2));
    ll m = stoll(S.substr(3, 5));
    ll s = stoll(S.substr(6, 8));
    return h * 3600 + m * 60 + s;
}

int main() {
    while (true) {
        ll N;
        cin >> N;
        if (N == 0) break;

        Imos<ll> imos(24 * 60 * 60, 0);

        vector<string> S(N), T(N);
        rep(i, N) {
            cin >> S[i] >> T[i];
            ll s = hhmmss2sec(S[i]);
            ll t = hhmmss2sec(T[i]);

            imos.add(s, t, 1);
        }

        imos.build();
        ll ans = 0;
        rep(i, 24 * 60 * 60) {
            chmax(ans, imos.get(i));
        }

        cout << ans << endl;
    }

    return 0;
} 
