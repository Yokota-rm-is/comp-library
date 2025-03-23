#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc381/tasks/abc381_e"

#include "../../../string/string-table.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vll slashes(N, 0);
    rep(i, N) {
        if (S[i] == '/') slashes[i] = 1;
    }

    vll A(N);
    rep(i, N) {
        if (S[i] == '1') A[i] = 1;
        else if (S[i] == '2') A[i] = 2;
        else A[i] = 0;
    }

    StringTable st(S);

    while (Q--) {
        ll L, R;
        cin >> L >> R;
        --L;

        if (st.count(L, R, 0) == 0) {
            cout << 0 << endl;
            continue;
        }

        ll n1 = st.count('1', L, R);
        ll n2 = st.count('2', L, R);
        ll n = min(n1, n2);

        if (n == 0) {
            cout << 1 << endl;
            continue;
        }

        auto is_ok = [&](ll x){
            ll l = st.index('1', x, L, R);
            ll r = st.index('2', n2 - x + 1, L, R);

            return r - l >= 0 and st.count('/', l, r) > 0;
        };

        auto binary_search = [&](ll ok, ll ng, ll eps) {
            if (!is_ok(ok)) return -1ll;
            if (is_ok(ng)) return ng;

            /* ok と ng のどちらが大きいかわからないことを考慮 */
            while (abs(ok - ng) > eps) {
                ll mid = (ok + ng) / 2;

                if (is_ok(mid)) ok = mid;
                else ng = mid;
            }
            return ok;
        };

        ll ret = binary_search(1, n, 1);
        if (ret == -1) cout << 1 << endl;
        else cout << ret * 2 + 1 << endl;
    }

    return 0;
} 
