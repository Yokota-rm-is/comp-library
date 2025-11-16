#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../../graph/lowlink.cpp"

int main() {
    ll N, M;
    cin >> N >> M;
    
    TwoEdgeConnectedComponents graph(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        graph.connect(a, b);
    }

    graph.build();
    cout << graph.group.size() << endl;
    rep(i, graph.group.size()) {
        cout << graph.group[i].size() << " ";
        rep(j, graph.group[i].size()) {
            cout << graph.group[i][j];
            if (j < graph.group[i].size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
} 
