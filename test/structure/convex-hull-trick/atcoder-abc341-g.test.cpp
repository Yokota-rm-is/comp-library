#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc341/tasks/abc341_g"

#include "../../../structure/convex-hull-trick.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];

    vector<long double> B(N + 1);
    B[0] = 0;
    rep(i, N) B[i + 1] = B[i] + A[i];

    ConvexHullTrick<long double, long double, false> cht;

    auto binary_search = [](function<bool(long double)> is_ok, long double ok, long double ng) {
        if (!is_ok(ok)) return (long double)-1.;
        if (is_ok(ng)) return ng;

        /* ok と ng のどちらが大きいかわからないことを考慮 */
        rep(i, 80) {
            long double mid = (ok + ng) / 2;

            if (is_ok(mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    vector<long double> ans(N, 0);
    repd(i, N) {
        cht.add(-(i + 1),  B[i + 1]);

        auto is_ok = [&](long double x) {
            return cht.query(x) >= B[i] - i * x;
        };

        ans[i] = binary_search(is_ok, 0.0, 1e6 + 1);    
    }

    rep(i, N) {
        cout << fixed << setprecision(10) << ans[i] << endl;
    }

    return 0;
}