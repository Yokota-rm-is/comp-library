#define PROBLEM "https://yukicoder.me/problems/no/2761"

#include "../../../string/rolling-hash-on-segment-tree.cpp"

int main() {
    ll N, L, Q;
    cin >> N >> L >> Q;
    
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    
    vector<RollingHashonSegmentTree> R(N);
    rep(i, N) {
        R[i].init(S[i]);
    }

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
                R[i].set(k, d);
            }
        }
        else {
            string t;
            cin >> t;

            Hash61 rhs(t);
            ll ans = 0;

            rep(i, N) {
                if (R[i].prod(0, t.size()) == rhs) ++ans;
            }

            cout << ans << endl;
        }
    }

    return 0;
} 
