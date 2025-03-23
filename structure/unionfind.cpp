#pragma once
#include "../base.cpp"


template<bool MergeCC = false, bool UnionBySize = true, bool PathCompression = true>
struct UnionFind {
    long long V;
    
    vector<long long> par; // par[i]: iの親の番号 or サイズ (iが親の時)
    vector<vector<long long>> cc;
    long long cc_size;
    
    vector<pair<long long, long long>> edges;
    vector<vector<long long>> cc_edge;

    UnionFind(long long V) : V(V) {
        init();
    }

    void init() {
        par.assign(V, -1);
        cc_size = V;
        cc.assign(V, {});
        rep(i, V) cc[i].push_back(i);
        cc_edge.assign(V, {});
    }

    // xの根を返す
    long long find(long long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] < 0) return x;

        long long rx = find(par[x]);
        if constexpr (PathCompression) par[x] = rx;
        return rx;
    }

    // xとyを連結
    bool unite(long long x, long long y) {
        return unite(x, y, [](long long, long long){});
    }

    // xとyを連結
    // f(rx, ry): 結合時の処理
    // fに与えられる引数(rx, ry)は(xとyの新たな親，消去される親)である
    // rx==ryの時もf(rx, ry)は呼ばれることに注意
    bool unite(long long x, long long y, auto f) {
        long long edge_index = edges.size();
        edges.emplace_back(x, y);

        long long rx = find(x); //xの根をrx
        long long ry = find(y); //yの根をry

        // -parはサイズを返す
        // ryの方がサイズが大きければrxとrxを入れ替える
        if constexpr (UnionBySize) {
            if (-par[rx] < -par[ry]) {
                swap(rx, ry);
            }
        }

        cc_edge[rx].push_back(edge_index);

        // 結合時の処理
        f(rx, ry);

        if (rx == ry) return false; //xとyの根が同じ時は何もしない

        if constexpr (MergeCC) {
            if constexpr (UnionBySize) merge(rx, ry);
            else if (-par[rx] >= -par[ry]) merge(rx, ry);
            else {
                merge(ry, rx);
                swap(cc[rx], cc[ry]);
                swap(cc_edge[rx], cc_edge[ry]);
            }
        }

        --cc_size;
        par[rx] += par[ry]; // rxのサイズを変更
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：yの根ryをxの根rxにつける

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

    // xが所属する連結成分に含まれる辺の数を返す
    long long edge_size(long long x) {
        assert(MergeCC);
        long long rx = find(x);
        return cc_edge[rx].size();
    }

    bool is_connected() {
        long long rx = find(0);
        return -par[rx] == V;
    }

    // xが所属する連結成分の要素を返す
    // MergeCC=trueの時はO(α(V))で取得できる
    // MergeCC=falseの時はO(Vα(V))で取得できる
    vector<long long> members(long long x) {
        if constexpr (MergeCC) {
            long long rx = find(x);
            return cc[rx];
        }
        else {
            long long rx = find(x);
            vector<long long> ret;
            rep(i, V) if (find(i) == rx) ret.push_back(i);
            return ret;
        }
    }

    // 根のみの配列を返す
    // MergeCC=trueの時はO(α(V))で取得できる
    // MergeCC=falseの時はO(V)で取得できる
    vector<long long> roots() {
        if constexpr (MergeCC) {
            vector<long long> ret;
            fore(p, cc) {
                if (p.empty()) continue;
                ret.push_back(find(*p.begin()));
            }
            return ret;
        }
        else {
            vector<long long> ret;
            rep(i, V) if (par[i] < 0) ret.push_back(i);
            return ret;
        }
    }

    // 連結成分の個数を返す
    long long group_count() {
        return cc_size;
    }

    // 連結成分の要素を返す
    vector<vector<long long>> all_group_members() {
        vector<vector<long long>> ret;
        fore(p, cc) {
            if (p.empty()) continue;
            ret.push_back(p);
        }

        return ret;
    }

private:
    void merge(long long rx, long long ry) {
        cc[rx].insert(cc[rx].end(), cc[ry].begin(), cc[ry].end());
        cc[ry].erase(cc[ry].begin(), cc[ry].end());
        cc[ry].shrink_to_fit();

        cc_edge[rx].insert(cc_edge[rx].end(), cc_edge[ry].begin(), cc_edge[ry].end());
        cc_edge[ry].erase(cc_edge[ry].begin(), cc_edge[ry].end());
        cc_edge[ry].shrink_to_fit();
    }
};