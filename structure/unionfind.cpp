#pragma once
#include "../base.cpp"

struct UnionFind {
    long long V;
    vector<long long> par; // par[i]: iの親の番号 or サイズ (iが親の時)
    map<long long, set<long long>> cc;
    
    long long edge_index;
    map<long long, set<long long>> cc_edge;

    UnionFind(long long V) : V(V), par(V, -1) { //最初は全てが根であるとして初期化
        edge_index = 0;
        rep(i, V) {
            cc[i].insert(i);
        }
    }

    // xの根を返す
    long long find(long long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] < 0) return x;

        long long rx = find(par[x]);
        return par[x] = rx;
    }

    // xとyを連結
    bool unite(long long x, long long y) {
        long long rx = find(x); //xの根をrx
        long long ry = find(y); //yの根をry

        // 結合時の処理をここに書く

        if (rx == ry) {
            cc_edge[rx].insert(edge_index++);
            return false; //xとyの根が同じ時は何もしない
        } 

        // -parはサイズを返す
        // ryの方がサイズが大きければrxとrxを入れ替える
        if (-par[rx] < -par[ry]) {
            swap(rx, ry);
        }

        cc_edge[rx].insert(edge_index++);

        par[rx] += par[ry]; // rxのサイズを変更
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：yの根ryをxの根rxにつける
        cc[rx].insert(cc[ry].begin(), cc[ry].end());
        cc.erase(ry);

        if (!cc_edge[ry].empty()) {
            cc_edge[rx].insert(cc_edge[ry].begin(), cc_edge[ry].end());
            cc_edge.erase(ry);
        }
    
        return true;
    }

    // 2つのデータx, yが属する木が同じならtrueを返す
    bool is_same(long long x, long long y) { 
        return find(x) == find(y);
    }

    // xが所属する連結成分の要素の数を返す
    long long size(long long x) {
        long long rx = find(x);
        return -par[rx];
    }

    bool is_connected() {
        long long rx = find(0);
        return -par[rx] == V;
    }

    // xが所属する連結成分の要素を返す
    set<long long> members(long long x) {
        long long rx = find(x);
        return cc[rx];
    }

    // 根のみの配列を返す
    set<long long> roots() {
        set<long long> ret;
        fore(p, cc) {
            ret.insert(p.first);
        }
        
        return ret;
    }

    // 連結成分の個数を返す
    long long group_count() {
        return cc.size();
    }

    map<long long, set<long long>> all_group_members() {
        return cc;
    }
};