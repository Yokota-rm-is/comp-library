#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc381/tasks/abc381_e"

#include "../../../structure/binary-indexed-tree.cpp"
#include "../../../other/cumulative-sum.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vll slashes(N, 0);
    rep(i, N) {
        if (S[i] == '/') slashes[i] = 1;
    }

    CumulativeSum<ll> cs(slashes);

    vll ones(N, 0), twos(N, 0);
    rep(i, N) {
        if (S[i] == '1') ones[i] = 1;
        if (S[i] == '2') twos[i] = 1;
    }

    BinaryIndexedTree<ll> bit1(ones), bit2(twos);

    while (Q--) {
        ll L, R;
        cin >> L >> R;
        --L;

        if (cs.sum(L, R) == 0) {
            cout << 0 << endl;
            continue;
        }

        ll n = min(bit1.sum(L, R), bit2.sum(L, R));

        if (n == 0) {
            cout << 1 << endl;
            continue;
        }

        auto is_ok = [&](ll x){
            ll l = bit1.find_lower_right(x, L);
            ll r = bit2.find_lower_left(x, R);

            if (l == N or r == -1) return false;
            return r - l >= 0 and cs.sum(l, r) > 0;
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