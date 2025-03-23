#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc375/tasks/abc375_f"
#include "../../../graph/warshall-floyd.cpp"

int main() {
    ll N, M, Q;
    cin >> N >> M >> Q;

    vll A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];
    --A, --B;

    WarshallFloyd<ll> wf(N, false);
    setll removed_edges;

    vvll query(Q);
    rep(q, Q) {
        ll t;
        cin >> t;

        query[q].push_back(t);

        if (t == 1) {
            ll i;
            cin >> i;
            --i;

            query[q].push_back(i);
            removed_edges.insert(i);
        }
        else {
            ll x, y;
            cin >> x >> y;
            --x, --y;

            query[q].push_back(x);
            query[q].push_back(y);
        }
    }

    rep(i, M) {
        if (removed_edges.contains(i)) continue;

        wf.connect(A[i], B[i], C[i]);
    }

    wf.build();

    vll ans;
    repd(q, Q) {
        ll t = query[q][0];

        if (t == 1) {
            ll i = query[q][1];
            ll a = A[i], b = B[i], c = C[i];

            wf.connect(a, b, c);
        }
        else {
            ll x = query[q][1], y = query[q][2];
            ll dist = wf.get_dist(x, y);

            ans.push_back(dist);
        }
    }

    reverse(ans);

    rep(i, ans.size()) cout << (ans[i] < inf64 ? ans[i] : -1) << endl;

    return 0;
} 
