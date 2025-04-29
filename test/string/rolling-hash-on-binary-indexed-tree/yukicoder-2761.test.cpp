#define PROBLEM "https://yukicoder.me/problems/no/2761"

#include "../../../string/rolling-hash-on-binary-indexed-tree.cpp"

int main() {
    ll N, L, Q;
    cin >> N >> L >> Q;
    
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    
    vector<RollingHashonBinaryIndexedTree> bit(N, L);
    rep(i, N) rep(j, L) bit[i].set(j, S[i][j]);

    while (Q--) {
        ll q;
        cin >> q;

        if (q == 1) {
            ll k;
            char c, d;
            cin >> k >> c >> d;
            --k;

            rep(i, N) {
                if (S[i][k] != c) continue;
                S[i][k] = d;
                bit[i].set(k, d);
            }
        }
        else {
            string t;
            cin >> t;

            Hash61 hs(t);
            ll ans = 0;

            rep(i, N) {
                if (bit[i].get(0, t.size()) == hs) ++ans;
            }

            cout << ans << endl;
        }
    }

    return 0;
} 
