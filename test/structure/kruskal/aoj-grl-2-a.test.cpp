#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&"

#include "../../../structure/kruskal.cpp"

int main() {
    ll V, E;
    cin >> V >> E;

    UnionFind tree(V);
    
    rep(i, E) {
        ll s, t, w;
        cin >> s >> t >> w;

        tree.add_edge(s, t, w);
    }

    cout << tree.kruskal() << endl;

    return 0;
}