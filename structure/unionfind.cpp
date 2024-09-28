#pragma once
#include "../base.cpp"

template <bool mergeCC = true>
struct UnionFind {
    long long V;
    vector<long long> par; // par[i]: iの親の番号 or サイズ (iが親の時)
    vector<vector<long long>> cc;
    long long cc_size;
    
    vector<pair<long long, long long>> edges;
    vector<vector<long long>> cc_edge;

    UnionFind(long long V) : V(V), par(V, -1), cc(V), cc_edge(V) { //最初は全てが根であるとして初期化
        cc_size = V;

        rep(i, V) cc[i] = {i};
    }

    // xの根を返す
    long long find(long long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] < 0) return x;

        long long rx = find(par[x]);
        return par[x] = rx;
    }

    // xとyを連結
    bool unite(long long x, long long y) {
        long long edge_index = edges.size();
        edges.emplace_back(x, y);

        long long rx = find(x); //xの根をrx
        long long ry = find(y); //yの根をry

        // -parはサイズを返す
        // ryの方がサイズが大きければrxとrxを入れ替える
        if (-par[rx] < -par[ry]) {
            swap(rx, ry);
        }

        cc_edge[rx].push_back(edge_index);

        // 結合時の処理をここに書く


        if (rx == ry) return false; //xとyの根が同じ時は何もしない

        --cc_size;
        par[rx] += par[ry]; // rxのサイズを変更
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：yの根ryをxの根rxにつける

        if (mergeCC) {
            cc[rx].insert(cc[rx].end(), cc[ry].begin(), cc[ry].end());
            cc[ry].clear();

            cc_edge[rx].insert(cc_edge[rx].end(), cc_edge[ry].begin(), cc_edge[ry].end());
            cc_edge[ry].clear();
        }
    
        return true;
    }

    // 2つのデータx, yが属する木が同じならtrueを返す
    bool is_same(long long x, long long y) { 
        return find(x) == find(y);
    }

    bool is_root(long long x) {
        return find(x) == x;
    }

    // xが所属する連結成分の要素の数を返す
    long long size(long long x) {
        long long rx = find(x);
        return -par[rx];
    }

    long long edge_size(long long x) {
        assert(mergeCC);
        long long rx = find(x);
        return cc_edge[rx].size();
    }

    bool is_connected() {
        long long rx = find(0);
        return -par[rx] == V;
    }

    // xが所属する連結成分の要素を返す
    vector<long long> members(long long x) {
        assert(mergeCC);
        long long rx = find(x);
        return cc[rx];
    }

    // 根のみの配列を返す
    vector<long long> roots() {
        assert(mergeCC);
        vector<long long> ret;
        fore(p, cc) {
            ret.push_back(p.front());
        }
        
        return ret;
    }

    // 連結成分の個数を返す
    long long group_count() {
        return cc_size;
    }

    vector<vector<long long>> all_group_members() {
        assert(mergeCC);
        vector<vector<long long>> ret;
        rep(i, V) {
            if (par[i] != -1) continue;
            ret.push_back(cc[i]);
            sort(ret.back().begin(), ret.back().end());
        }

        return ret;
    }
};