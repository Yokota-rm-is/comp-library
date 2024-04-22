#define PROBLEM "https://atcoder.jp/contests/abc128/tasks/abc128_c"

#include "../../../search/bit-zentansaku.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vector<setll> A(M);

    rep(i, M) {
        ll k;
        cin >> k;

        rep(j, k) {
            ll s;
            cin >> s;

            A[i].insert(s - 1);
        }
    }

    vll p(M);
    rep(i, M) cin >> p[i];
    ll ans = 0;

    for (long long bit = 0; bit < (1ll << N); ++bit) {
        vll sum(M, 0);
        
        rep(i, N) {
            if (bit & (1ll << i)) {
                // iがbitに含まれる場合の処理を書く
                rep(j, M) {
                    if (A[j].contains(i)) sum[j] += 1;
                }
            }
            else {
                // iがbitに含まれない場合の処理を書く

            }
        }

        bool flg = true;
        rep(i, M) {
            sum[i] %= 2;
            if (sum[i] != p[i]) {
                flg = false;
                break;
            } 
        }

        if (flg) ++ans;
    }

    cout << ans << endl;


    return 0;
}