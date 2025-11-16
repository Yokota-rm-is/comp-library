#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc296/tasks/abc296_g"
// https://atcoder.jp/contests/abc296/submissions/68845864

#include "../../../other/range-map.cpp"

int main() {
    ll N;
    cin >> N;

    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    ll Q;
    cin >> Q;

    vll A(Q), B(Q);
    rep(i, Q) cin >> A[i] >> B[i];

    ll l = inf64, r = -inf64;
    ll lt = -inf64, lb = inf64, rt = inf64, rb = -inf64;
    ll idx_lt = -1, idx_lb = -1, idx_rt = -1, idx_rb = -1;

    rep(i, N) {
        if (chmin(l, X[i])) {
            lt = Y[i];
            lb = Y[i];
            idx_lt = i;
            idx_lb = i;
        }
        else if (l == X[i]) {
            if (chmax(lt, Y[i])) idx_lt = i;
            if (chmin(lb, Y[i])) idx_lb = i;
        }

        if (chmax(r, X[i])) {
            rt = Y[i];
            rb = Y[i];
            idx_rt = i;
            idx_rb = i;
        }
        else if (r == X[i]) {
            if (chmax(rt, Y[i])) idx_rt = i;
            if (chmin(rb, Y[i])) idx_rb = i;
        }
    }

    vector<string> ans(Q, "");
    rep(i, Q) {
        if (A[i] == l) {
            if (lb <= B[i] and B[i] <= lt) ans[i] = "ON";
            else ans[i] = "OUT";
        }

        if (A[i] == r) {
            if (rb <= B[i] and B[i] <= rt) ans[i] = "ON";
            else ans[i] = "OUT";
        }

        if (A[i] < l or r < A[i]) ans[i] = "OUT";
    }

    RangeMap<ll, ll> upper(-1), lower(-1);

    for (ll i = idx_lt; i != idx_rt; i = (i + N - 1) % N) {
        upper.set(X[i], X[(i + N - 1) % N], i);
    }

    for (ll i = idx_lb; i != idx_rb; i = (i + 1) % N) {
        lower.set(X[i], X[(i + 1) % N], i);
    }

    rep(i, Q) {
        if (ans[i] != "") continue;

        ll idx_u = upper.get(A[i]);
        ll idx_l = lower.get(A[i]);
        
        ll dy_u = Y[(idx_u + N - 1) % N] - Y[idx_u];
        ll dx_u = X[(idx_u + N - 1) % N] - X[idx_u];
        ll a_u = dy_u;
        ll b_u = X[(idx_u + N - 1) % N] * Y[idx_u] - X[idx_u] * Y[(idx_u + N - 1) % N];

        if (dx_u * B[i] > a_u * A[i] + b_u) {
            ans[i] = "OUT";
            continue;
        }
        else if (dx_u * B[i] == a_u * A[i] + b_u) {
            ans[i] = "ON";
            continue;
        }

        ll dy_l = Y[(idx_l + 1) % N] - Y[idx_l];
        ll dx_l = X[(idx_l + 1) % N] - X[idx_l];
        ll a_l = dy_l;
        ll b_l = X[(idx_l + 1) % N] * Y[idx_l] - X[idx_l] * Y[(idx_l + 1) % N];

        if (dx_l * B[i] < a_l * A[i] + b_l) {
            ans[i] = "OUT";
            continue;
        }
        else if (dx_l * B[i] == a_l * A[i] + b_l) {
            ans[i] = "ON";
            continue;
        }

        ans[i] = "IN";
    }

    cout << ans << endl;

    return 0;
} 
