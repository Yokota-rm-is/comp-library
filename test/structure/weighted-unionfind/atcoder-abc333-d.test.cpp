#define PROBLEM "https://atcoder.jp/contests/abc333/tasks/abc333_d"

#include "../../../structure/weighted-unionfind.cpp"

int main() {
    long long N;
    cin >> N;

    vll A;

    WeightedUnionFind<ll> tree(N);
    rep(i, N - 1) {
        long long u, v;
        cin >> u >> v;
        --u, --v;

        if (u == 0) A.push_back(v);
        else if (v == 0) A.push_back(u);
        else tree.unite(u, v, 0);
    }

    ll ans = 1;
    if (A.size() > 1) {
        vll sizes;
        for (auto x : A) sizes.push_back(tree.size(x));

        sort(sizes.begin(), sizes.end());
        ans += accumulate(sizes.begin(), sizes.end(), 0ll) - sizes.back();
    }

    cout << ans << endl;

    return 0;
}