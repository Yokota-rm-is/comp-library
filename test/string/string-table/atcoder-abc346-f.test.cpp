#define PROBLEM "https://atcoder.jp/contests/abc346/tasks/abc346_f"

#include "../../../string/string-table.cpp"
#include "../../../search/binary-search.cpp"

int main() {
    ll N;
    cin >> N;

    string S;
    cin >> S;

    string T;
    cin >> T;

    StringTable st(S);

    auto is_ok = [&](ll x) {
        ll idx = 0;
        ll M = 0;

        if (x == 0) return true;

        fore(t, T) {
            ll y = x;
            ll cnt1 = st.count(t, idx, S.size());
            if (y > cnt1) {
                idx = 0;
                ++M;
                y -= cnt1;
            }

            ll cnt2 = st.count(t, 0, S.size());
            if (cnt2 == 0) return false;

            if (y > cnt2) {
                M += ceil(y, cnt2) - 1;
                y -= cnt2 * (ceil(y, cnt2) - 1);
            }

            if (y > 0) {
                idx = st.index(t, y, idx, S.size()) + 1;
            }
        }

        return M < N;
    };

    ll ans = binary_search<ll>(is_ok, 0, S.size() * N / T.size() + 1);

    // cout << fixed << setprecision(10);  // 小数点以下を10桁表示，許容誤差が1e-N以下の時はN+1に変更すること(16桁以上はlong double)
    cout << ans << endl;
    // cout << YesNo(ans) << endl;
    // rep(i, N) cout << (ans[i] < inf64 ? ans[i] : -1) << endl;

    return 0;
} 
