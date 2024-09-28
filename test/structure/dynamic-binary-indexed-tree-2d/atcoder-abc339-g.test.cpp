#define PROBLEM "https://atcoder.jp/contests/abc339/tasks/abc339_g"

#include "../../../structure/dynamic-binary-indexed-tree-2d.cpp"
#include "../../../other/compressor.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N);
    rep(i, N) cin >> A[i];

    Compressor<ll> comp(A);

    DynamicBinaryIndexedTree2D<ll> bit(N, comp.size() + 1);
    rep(i, N) {
        bit.add(i, comp[i], A[i]);
    }

    ll Q;
    cin >> Q;

    ll B = 0;

    while (Q--) {
        ll alpha, beta, gamma;
        cin >> alpha >> beta >> gamma;

        ll L = alpha ^ B;
        ll R = beta ^ B;
        ll X = gamma ^ B;

        --L;
        X = comp.upper_bound(X);
        
        ll ans = bit.sum(L, R, 0, X);
        cout << ans << endl;
        B = ans;
    }

    return 0;
} 
