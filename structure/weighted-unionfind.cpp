#pragma once
#include "../base.cpp"

template <bool fastMode = false>
struct WeightedUnionFind {
    long long V{};
    vector<long long> par{}; // par[i]: iの親の番号 or サイズ (iが親の時)
    vector<long long> diff_weight{};
    map<long long, set<long long>> cc;
    long long cc_size;
    long long cc_edge_size;

    explicit WeightedUnionFind(long long V) : V(V), par(V, -1), diff_weight(V, 0) { //最初は全てが根であるとして初期化
        cc_size = V;
        cc_edge_size = 0;
    }

    // xの根を返す
    long long find(long long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] < 0) return x;

        long long rx = find(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = rx;
    }

    // xの根からの重みを返す
    long long weight(long long x) {
        find(x);
        return diff_weight[x];
    }

    // xとyを連結
    // w = weight(y) - weight(x)
    bool unite(long long x, long long y, long long w = 0) {
        w += weight(x);
        w -= weight(y);

        long long rx = find(x); //xの根をrx
        long long ry = find(y); //yの根をry
        if (rx == ry) return false; //xとyの根が同じ(=同じ木にある)時はそのまま

        --cc_size;
        ++cc_edge_size;

        // -parはサイズを返す
        // ryの方がサイズが大きければrxとrxを入れ替える
        if (-par[rx] < -par[ry]) {
            swap(rx, ry);
            w = -w;
        }

        par[rx] += par[ry]; // rxのサイズを変更
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：yの根ryをxの根rxにつける

        if (!fastMode) {
            if (cc.contains(ry)) {
                cc[rx].insert(cc[ry].begin(), cc[ry].end());
                cc.erase(ry);
            }
            else if (!cc.contains(rx)) cc[rx] = {rx, ry};
            else cc[rx].insert(ry);
        }

        diff_weight[ry] = w;

        return true;
    }

    // 2つのデータx, yが属する木が同じならtrueを返す
    bool is_same(long long x, long long y) { 
        return find(x) == find(y);
    }

    // return weight(y) - weight(x)
    long long diff(long long x, long long y) {
        return weight(y) - weight(x);
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
        return cc_size;
    }

    map<long long, set<long long>> all_group_members() {
        auto ret = cc;
        rep(i, V) {
            if (par[i] != -1) continue;
            ret[i] = {i}; 
        }
        return ret;
    }
};