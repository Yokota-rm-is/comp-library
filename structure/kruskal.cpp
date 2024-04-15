#pragma once
#include "../base.cpp"

struct WeightPriorityEdge {
    long long from;
    long long to;
    long long weight;
    
    explicit WeightPriorityEdge(long long s, long long t, long long w = 0) : from(s), to(t), weight(w) {};

    bool operator< (const WeightPriorityEdge& other) const {
        if (weight == other.weight) {
            if (from == other.from) return to < other.to;
            else return from < other.from;
        }
        else return weight < other.weight;
    }
};

struct UnionFind {
    long long V{};
    vector<long long> par{}; // par[i]: iの親の番号 or サイズ (iが親の時)

    vector<WeightPriorityEdge> edges;

    explicit UnionFind(long long V) : V(V), par(V, -1) { //最初は全てが根であるとして初期化
    }

    // xの根を返す
    long long find(long long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] < 0) return x;

        long long rx = find(par[x]);
        return par[x] = rx;
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

    // kruskal用 
    void add_edge(long long u, long long v, long long w) {
        edges.emplace_back(u, v, w);
    }
    
    // 無向最小全域木のコストを求める
    long long kruskal() {
        sort(edges.begin(), edges.end());

        long long sum = 0;
        fore(e, edges) {
            if (is_same(e.from, e.to)) continue;

            unite(e.from, e.to, e.weight);
            sum += e.weight;
        }

        return sum;
    }

private:
    // xとyを連結
    bool unite(long long x, long long y, long long w = 0) {
        long long rx = find(x); //xの根をrx
        long long ry = find(y); //yの根をry
        if (rx == ry) return false; //xとyの根が同じ(=同じ木にある)時はそのまま

        // -parはサイズを返す
        // ryの方がサイズが大きければrxとrxを入れ替える
        if (-par[rx] < -par[ry]) {
            swap(rx, ry);
            w = -w;
        }

        par[rx] += par[ry]; // rxのサイズを変更
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：yの根ryをxの根rxにつける

        return true;
    }
};