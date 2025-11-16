#pragma once
#include "../base.cpp"

struct CentroidDecomposition {
    long long V;
    
    vector<vector<long long>> G;
    vector<long long> size;
    vector<bool> done;

    CentroidDecomposition(long long n) : V(n), G(n), size(n, 0), done(n, false) {}

    void connect(long long u, long long v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    long long dfs_size(long long now, long long p = -1) {
        size[now] = 1;
        fore (to, G[now]) {
            if (to == p) continue;
            if (done[to]) continue;
            size[now] += dfs_size(to, now);
        }
        return size[now];
    }

    long long dfs_centroid(long long now, long long p, long long n) {
        for (auto to : G[now]) {
            if (to == p) continue;
            if (done[to]) continue;
            if (size[to] > n / 2) return dfs_centroid(to, now, n);
        }
        return now;
    }

    long long find_centroid(long long root) {
        dfs_size(root);
        long long centroid = dfs_centroid(root, -1, size[root]);
        done[centroid] = true;

        return centroid;
    }
};

// main関数では再帰関数に入れて使う
// function<void(ll)> dfs = [&](ll root) {
//     ll centroid = CD.find_centroid(root);
//
//     rep(i, G[centroid].size()) {
//         if (CD.done[G[centroid][i]]) continue;
//
//         // DFS・BFSなど部分木に対する処理
//     }
//
//     fore(e, CD.G[centroid]) {
//         if (CD.done[e]) continue;
//         dfs(e);
//     }
// };