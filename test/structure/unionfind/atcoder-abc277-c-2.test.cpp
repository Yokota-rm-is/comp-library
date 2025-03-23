#define PROBLEM "https://atcoder.jp/contests/abc277/tasks/abc277_c"

#include "../../../structure/unionfind.cpp"
#include "../../../other/compressor.cpp"

int main() {
    long long N;
    cin >> N;

    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vll X;
    X.push_back(1);
    rep(i, N) {
        X.emplace_back(A[i]);
        X.emplace_back(B[i]);
    }

    Compressor<long long> comp(X);

    UnionFind<true, false, true> tree(comp.size());
    rep(i, N) {
        tree.unite(comp(A[i]), comp(B[i]));
    }

    auto members = tree.members(comp(1));
    long long ans = 1;
    for (auto x : members) {
        chmax(ans, comp.retrieve(x));
    }

    cout << ans << endl;
    
    return 0;
}