#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc239/tasks/abc239_g"
// https://atcoder.jp/contests/abc239/submissions/68275452

#include "../../../graph/flow.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    MinCostFlow<ll, ll> mcf(N * 2);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        --a; --b;

        mcf.connect(a + N, b, inf64);
        mcf.connect(b + N, a, inf64);
    }

    rep(i, N) {
        ll c;
        cin >> c;
        if (c == 0) c = inf64;
        mcf.connect(i, i + N, c);
    }

    ll max_flow = mcf.max_flow(0, N - 1);
    vector<bool> min_cut = mcf.min_cut(0);

    vll ans;
    rep(i, N) {
        if (min_cut[i] and !min_cut[i + N]) {
            ans.push_back(i + 1);
        }
    }

    cout << max_flow << endl;
    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}