#define PROBLEM "https://atcoder.jp/contests/abc147/tasks/abc147_c"

#include "../../../search/bit-zentansaku.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    vvll X(N), Y(N); 

    rep(i, N) {
        cin >> A[i];

        rep(j, A[i]) {
            ll x, y;
            cin >> x >> y;

            X[i].push_back(x - 1);
            Y[i].push_back(y);
        }
    }

    ll ans = 0;

    for (long long bit = 0; bit < (1ll << N); ++bit) {
        setll st;

        rep(i, N) {
            if (bit & (1ll << i)) {
                // iがbitに含まれる場合の処理を書く
                st.insert(i);
            }
            else {
                // iがbitに含まれない場合の処理を書く

            }
        }

        bool flg = true;

        fore(i, st) {
            rep(j, A[i]) {
                ll x = X[i][j], y = Y[i][j];

                if (st.contains(x) and y == 1) continue;
                if (!st.contains(x) and y == 0) continue;

                flg = false;
                break;
            }
            if (!flg) break;
        }

        if (flg) {
            chmax(ans, (ll)st.size());
        };
    }

    cout << ans << endl;

    return 0;
}