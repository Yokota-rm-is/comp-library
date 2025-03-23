#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc385/tasks/abc385_f"
// https://atcoder.jp/contests/abc385/submissions/61528310

#include "../../../search/stern-brocot-tree.cpp"

int main() {
    ll N;
    cin >> N;

    vll X(N), H(N);
    rep(i, N) cin >> X[i] >> H[i];

    auto is_ok = [&](ll a, ll b) {
        lll dx = lll(X[0]) * b;
        lll dy = lll(H[0]) * b - a;

        rep(i, 1, N) {
            lll dx2 = lll(X[i]) * b;
            lll dy2 = lll(H[i]) * b - a;

            // dy2/dx2 > dy/dxかどうか判定
            if (is_greater(dy2, dx2, dy, dx)) {
                dx = dx2;
                dy = dy2;
            }
            else return false;
        }

        return true;
    };

    SternBrocotTree<ll> sbt;

    if (sbt.is_all_true(is_ok, inf64)) {
        cout << -1 << endl;
        return 0;
    }

    auto [u, v, x, y] = sbt.search(is_ok, inf64);
    long double ans = (long double)x / y;

    cout << fixed << setprecision(20);  // 小数点以下を10桁表示，許容誤差が1e-N以下の時はN+1に変更すること(16桁以上はlong double)
    cout << ans << endl;

    return 0;
} 
