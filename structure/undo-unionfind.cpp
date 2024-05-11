#pragma once
#include "../base.cpp"

struct UndoUnionFind {
    long long V;
    vector<long long> par; // par[i]: iの親の番号 or サイズ (iが親の時)
    stack<pair<long long, long long>> history;

    UndoUnionFind(long long v) : V(v), par(V, -1) { //最初は全てが根であるとして初期化
    }

    // xの根を返す
    long long find(long long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] < 0) return x;

        return find(par[x]);
    }

    // xとyを連結
    bool unite(long long x, long long y) {
        long long rx = find(x); //xの根をrx
        long long ry = find(y); //yの根をry

        history.emplace(rx, par[rx]);
        history.emplace(ry, par[ry]);

        // 結合時の処理をここに書く

        if (rx == ry) return false; //xとyの根が同じ時は何もしない

        // -parはサイズを返す
        // ryの方がサイズが大きければrxとrxを入れ替える
        if (-par[rx] < -par[ry]) {
            swap(rx, ry);
        }

        par[rx] += par[ry]; // rxのサイズを変更
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：yの根ryをxの根rxにつける

        return true;
    }

    // 2つのデータx, yが属する木が同じならtrueを返す
    bool is_same(long long x, long long y) { 
        return find(x) == find(y);
    }

    void undo() {
        par[history.top().first] = history.top().second;
        history.pop();
        par[history.top().first] = history.top().second;
        history.pop();
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
};