#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc202/tasks/abc202_e"

#include "../../../tree/tree-dfs.cpp"
#include "../../../structure/wavelet-matrix.cpp"


int main() {
    ll N;
    cin >> N;

    vll P(N - 1);
    rep(i, N - 1) cin >> P[i];
    --P;

    TreeDFS tree(N);
    
    rep(i, N - 1) tree.connect(P[i], i + 1);
    tree.build(0);

    vll A(4 * N - 2, inf32);
    rep(i, N) {
        A[tree.pre_order[i]] = tree.depth(i);
    }

    WaveletMatrix<ll> wm(A);
    
    ll Q;
    cin >> Q;

    while (Q--) {
        ll u, d;
        cin >> u >> d;
        --u;

        auto[l, r] = tree.get_vertex_index(u);

        cout << wm.count(l, r, d) << endl;
    }

    return 0;
} 
