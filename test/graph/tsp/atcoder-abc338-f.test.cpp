#define PROBLEM "https://atcoder.jp/contests/abc338/tasks/abc338_f"

#include "../../../graph/tsp.cpp"
#include "../../../graph/warshall-floyd.cpp"

int main() {
    ll N, M;
    cin >> N >> M;

    vll U(M), V(M), W(M);
    rep(i, M) cin >> U[i] >> V[i] >> W[i];
    --U; --V;

    WarshallFloyd<ll> wf(N, true);
    rep(i, M) {
        wf.connect(U[i], V[i], W[i]);
    }
    wf();

    TSP<ll> tsp(N, true);
    rep(i, N) rep(j, N) {
        if (i == j) continue;

        ll dist = wf.get_dist(i, j);
        if (dist == inf64) continue;
        
        tsp.connect(i, j, dist);
    }

    tsp();
    ll ans = tsp.get_min_dist();
    
    if (ans == inf64) cout << "No" << endl;
    else cout << ans << endl;

    return 0;
} 
