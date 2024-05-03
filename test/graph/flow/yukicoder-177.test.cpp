#define PROBLEM "https://yukicoder.me/problems/no/177"

#include "../../../graph/flow.cpp"

int main() {
    ll W;
    cin >> W;

    ll N;
    cin >> N;
    vll J(N);
    fore(j, J) cin >> j;

    ll M;
    cin >> M;
    vll C(M);
    fore(c, C) cin >> c;

    ll start = N + M;
    ll goal = start + 1;

    MinCostFlow<ll, ll> graph(N + M + 2);
    rep(i, N) graph.connect(start, i, J[i]);
    rep(j, M) graph.connect(N + j, goal, C[j]);

    rep(j, N, N + M) {
        ll Q;
        cin >> Q;

        setll st;
        rep(i, Q) {
            ll x;
            cin >> x;
            --x;
            st.insert(x);
        }

        rep(i, N) {
            if (st.contains(i)) continue;
            graph.connect(i, j, inf64);
        }
    }

    ll flow = graph.max_flow(start, goal);
    if (flow < W) cout << "BANSAKUTSUKITA" << endl;
    else cout << "SHIROBAKO" << endl;

    return 0;
}