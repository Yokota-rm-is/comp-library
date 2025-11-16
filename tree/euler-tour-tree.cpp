#pragma once
#include "../base.cpp"

// 参考: https://kopricky.github.io/code/DataStructure_OnGraph/euler_tour_tree.html
template<typename T, typename F> 
struct BSTNode {
public:
    int from, to, sz;
    T value, al;
    F lazy;
    BSTNode *left, *right, *par;
    BSTNode(const int _from, const int _to) noexcept
        : from(_from), to(_to), sz(0), value(e), al(e), lazy(id),
            left(nullptr), right(nullptr), par(nullptr){}
    BSTNode(const int _from, const int _to, const T& _value) noexcept
        : from(_from), to(_to), sz(1), value(_value), al(value), lazy(id),
            left(nullptr), right(nullptr), par(nullptr){}
    static const T e = (T)0;
    static const F id = (T)0;
    static T op(const T arg1, const T arg2) noexcept { return arg1 + arg2; }
    static void mapping(T& arg1, const F arg2) noexcept { arg1 += arg2; }
    static void composition(T& arg1, const F arg2) noexcept { arg1 += arg2; }
    inline bool IsRoot() const noexcept { return !par; }
    inline bool IsVertex() const noexcept { return from == to; }
    void push() noexcept {
        if(lazy != id){
            if(IsVertex()) mapping(value, lazy);
            al += lazy * sz;
            if(left) composition(left->lazy, lazy);
            if(right) composition(right->lazy, lazy);
            lazy = id;
        }
    }
    void eval() noexcept {
        sz = IsVertex(), al = value;
        if(left) left->push(), sz += left->sz, al = op(left->al, al);
        if(right) right->push(), sz += right->sz, al = op(al, right->al);
    }
    void rotate(const bool right_) noexcept {
        BSTNode *p = par, *g = p->par;
        if(right_){
            if((p->left = right)) right->par = p;
            right = p, p->par = this;
        }else{
            if((p->right = left)) left->par = p;
            left = p, p->par = this;
        }
        p->eval(), eval();
        if(!(par = g)) return;
        if(g->left == p) g->left = this;
        if(g->right == p) g->right = this;
        g->eval();
    }
};

template<typename T, typename F>
BSTNode<T, F>* splay(BSTNode<T, F> *u) noexcept {
    if(!u) return nullptr;
    while(!(u->IsRoot())){
        BSTNode<T, F> *p = u->par, *gp = p->par;
        if(p->IsRoot()){ // zig
            p->push(), u->push();
            u->rotate((u == p->left));
        }else{
            gp->push(), p->push(), u->push();
            bool flag = (u == p->left);
            if((u == p->left) == (p == gp->left)){ // zig-zig
                p->rotate(flag), u->rotate(flag);
            }else{ // zig-zag
                u->rotate(flag), u->rotate(!flag);
            }
        }
    }
    u->push();
    return u;
}

template<typename T, typename F>
BSTNode<T, F>* join(BSTNode<T, F> *root1, BSTNode<T, F> *root2) noexcept {
    if(!root1 || !root2) return root1 ? root1 : root2;
    BSTNode<T, F> *cur = nullptr, *nx = root1;
    do{ cur = nx, cur->push(), nx = cur->right; }while(nx);
    BSTNode<T, F> *ver = splay(cur);
    ver->right = root2, ver->eval(), root2->par = ver;
    return ver;
}

template<typename T, typename F>
pair<BSTNode<T, F>*, BSTNode<T, F>*> split_lower_bond(BSTNode<T, F> *ver) noexcept {
    BSTNode<T, F> *res = splay(ver)->left;
    ver->left = nullptr, ver->eval();
    if(res) res->par = nullptr;
    return make_pair(res, ver);
}

template<typename T, typename F>
pair<BSTNode<T, F>*, BSTNode<T, F>*> split_upper_bond(BSTNode<T, F> *ver) noexcept {
    BSTNode<T, F> *res = splay(ver)->right;
    ver->right = nullptr, ver->eval();
    if(res) res->par = nullptr;
    return make_pair(ver, res);
}

template<typename T, typename F> 
struct EulerTourTree {
private:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator() (const pair<T1, T2>& p) const {
            size_t lhs = hash<T1>()(p.first), rhs = hash<T2>()(p.second);
            return lhs^(rhs+0x9e3779b9+(lhs<<6)+(lhs>>2));
        }
    };

    using S = BSTNode<T, F>;
    using pS = unique_ptr<S>;

    vector<pS> A;

    vector<BSTNode<T, F>*> vertex_set;
    unordered_map<pair<int, int>, pair<BSTNode<T, F>*, BSTNode<T, F>*>, pair_hash> edge_set;

    BSTNode<T, F>* new_node(const int from, const int to) noexcept {
        pS node = make_unique<S, F>(from, to);
        BSTNode<T, F>* res = node.get();
        A.push_back(move(node));
        return res;
    }

    BSTNode<T, F>* new_node(const int from, const int to, const T& value) noexcept {
        pS node = make_unique<S, F>(from, to, value);
        BSTNode<T, F>* res = node.get();
        A.push_back(move(node));
        return res;
    }

    BSTNode<T, F> *reroot(BSTNode<T, F> *ver) noexcept {
        BSTNode<T, F> *res = splay(ver)->left;
        if(!res) return ver;
        ver->left = nullptr, ver->eval();
        while(ver->right) ver->push(), ver = ver->right;
        splay(ver), ver->right = res, ver->eval(), res->par = ver;
        return ver;
    }

    void link(BSTNode<T, F> *ver1, BSTNode<T, F> *ver2) noexcept {
        BSTNode<T, F>* e1 = new_node(ver1->from, ver2->from);
        BSTNode<T, F>* e2 = new_node(ver2->from, ver1->from);
        edge_set[{ver1->from, ver2->from}] = {e1, e2};
        join(join(reroot(ver1), e1), join(reroot(ver2), e2));
    }
    
    void cut(BSTNode<T, F> *edge1, BSTNode<T, F> *edge2) noexcept {
        splay(edge1), splay(edge2);
        BSTNode<T, F> *p = edge1->par;
        bool _right = (edge1 == edge2->right);
        if(p != edge2){
            _right = (p == edge2->right);
            p->par = nullptr, edge1->rotate((edge1 == p->left));
        }
        if(edge1->left) edge1->left->par = nullptr;
        if(edge1->right) edge1->right->par = nullptr;
        if(_right){
            if(edge2->left) edge2->left->par = nullptr;
            join(edge2->left, edge1->right);
        }else{
            if(edge2->right) edge2->right->par = nullptr;
            join(edge1->left, edge2->right);
        }
    }

    bool IsConnected(BSTNode<T, F> *ver1, BSTNode<T, F> *ver2) noexcept {
        splay(ver1), splay(ver2);
        return ver1->par;
    }

    T& get(BSTNode<T, F> *ver) noexcept { return splay(ver)->value; }

    void point_update(BSTNode<T, F> *ver, const F& val){
        splay(ver);
        BSTNode<T, F>::mapping(ver->value, val);
        ver->al = BSTNode<T, F>::op(ver->al, val);
    }

    void range(BSTNode<T, F> *edge1, BSTNode<T, F> *edge2, const F& val) noexcept {
        auto res1 = split_lower_bond(edge1);
        auto res2 = split_upper_bond(edge2);
        BSTNode<T, F>::composition(res2.first->lazy, val);
        join(join(res1.first,res2.first), res2.second);
    }

    T query(BSTNode<T, F> *edge1, BSTNode<T, F> *edge2) noexcept {
        auto res1 = split_lower_bond(edge1);
        auto res2 = split_upper_bond(edge2);
        T res = res2.first->al;
        return join(join(res1.first,res2.first), res2.second), res;
    }

    void dfs(const int u, const int p, const BSTNode<T, F> *cur,
        bool *visit, vector<BSTNode<T, F>*>& nodes, const vector<vector<int> >& G) noexcept {
        visit[u] = true;
        nodes.push_back(vertex_set[u]);
        for(auto& v : G[u]){
            if(v != p){
                BSTNode<T, F>* e1 = new_node(u, v);
                nodes.push_back(e1);
                dfs(v, u, cur, visit, nodes, G);
                BSTNode<T, F>* e2 = new_node(v, u);
                if(u < v) edge_set[{u, v}] = {e1, e2};
                else edge_set[{v, u}] = {e2, e1};
                nodes.push_back(e2);
            }
        }
    }

    void bst_build(vector<BSTNode<T, F>* >& nodes) noexcept {
        int i, n = (int)nodes.size(), st = 2, isolate = ((n % 4 == 1) ? (n-1) : -1);
        while(st <= n){
            for(i = st-1; i < n; i += 2*st){
                nodes[i]->left = nodes[i-st/2], nodes[i-st/2]->par = nodes[i];
                if(i+st/2 < n) nodes[i]->right = nodes[i+st/2], nodes[i+st/2]->par = nodes[i];
                else if(isolate >= 0) nodes[i]->right = nodes[isolate], nodes[isolate]->par = nodes[i];
                nodes[i]->eval();
            }
            isolate = ((n % (4*st) >= st && (n % (4*st) < 2*st)) ? (i-2*st): isolate);
            st <<= 1;
        }
    }

    void build_forest(const vector<vector<int> >& forest) noexcept {
        bool *visit = new bool[V]();
        for(int i = 0; i < V; i++){
            if(!visit[i]){
                vector<BSTNode<T, F>* > nodes;
                BSTNode<T, F> *cur = nullptr;
                dfs(i, -1, cur, visit, nodes, forest);
                bst_build(nodes);
            }
        }
    }

    void build_tree(const int root, const vector<vector<int> >& tree) noexcept {
        bool *visit = new bool[V]();
        vector<BSTNode<T, F>* > nodes;
        BSTNode<T, F> *cur = nullptr;
        dfs(root, -1, cur, visit, nodes, tree);
        bst_build(nodes);
    }

public:
    const int V;

    EulerTourTree(int n) noexcept : V(n){
        for(int i = 0; i < V; i++) vertex_set.push_back(new_node(i, i, BSTNode<T, F>::e));
    }

    EulerTourTree(const vector<T>& ver_value) noexcept : V((int)ver_value.size()){
        for(int i = 0; i < V; i++) vertex_set.push_back(new_node(i, i, ver_value[i]));
    }

    // 根を node_id にする
    void reroot(const int node_id) noexcept { reroot(vertex_set[node_id]); }

    // 辺(node1_id, node2_id) を追加
    void link(int node1_id, int node2_id) noexcept {
        if(node1_id > node2_id) swap(node1_id, node2_id);
        link(vertex_set[node1_id], vertex_set[node2_id]);
    }

    // 辺(node1_id, node2_id) を削除(逆向きでも問題ない)
    void cut(int node1_id, int node2_id){
        if(node1_id > node2_id) swap(node1_id, node2_id);
        auto it = edge_set.find({node1_id, node2_id});
        assert(it != edge_set.end());
        BSTNode<T, F> *edge1 = (it->second).first, *edge2 = (it->second).second;
        edge_set.erase(it);
        cut(edge1, edge2);
    }

    // node1_id と node2_id が同じ木(連結成分)に属するか
    bool IsConnected(const int node1_id, const int node2_id) noexcept {
        if(node1_id == node2_id) return true;
        return IsConnected(vertex_set[node1_id], vertex_set[node2_id]);
    }

    // 頂点 ver_id の値を取得
    T& get(const int ver_id) noexcept { return get(vertex_set[ver_id]); }

    // 頂点 ver_id に val を加える
    void point_update(const int ver_id, const F& val) noexcept {
        return point_update(vertex_set[ver_id], val);
    }

    // 頂点 ver_id の存在する連結成分内の頂点全体に val を加える
    void component_range(const int ver_id, const F& val){ range(ver_id, -1, val); }

    // 親が par_id であるような頂点 ver_id の部分木内に存在する頂点全体に val を加える
    void range(const int ver_id, const int par_id, const F& val){
        if(par_id < 0) return BSTNode<T, F>::composition(splay(vertex_set[ver_id])->lazy, val);
        if(ver_id < par_id){
            auto it = edge_set.find({ver_id, par_id});
            assert(it != edge_set.end());
            range((it->second).second, (it->second).first, val);
        }else{
            auto it = edge_set.find({par_id, ver_id});
            assert(it != edge_set.end());
            range((it->second).first, (it->second).second, val);
        }
    }

    // 頂点 ver_id の存在する連結成分内の頂点全体の総和を取得
    T component_query(const int ver_id){ return query(ver_id, -1); }
    
    // 親が par_id であるような頂点 ver_id の部分木内に存在する頂点全体の総和を取得
    T query(const int ver_id, const int par_id){
        if(par_id < 0) return splay(vertex_set[ver_id])->al;
        if(ver_id < par_id){
            auto it = edge_set.find({ver_id, par_id});
            assert(it != edge_set.end());
            return query((it->second).second, (it->second).first);
        }else{
            auto it = edge_set.find({par_id, ver_id});
            assert(it != edge_set.end());
            return query((it->second).first, (it->second).second);
        }
    }

private:
    void check_dfs(const BSTNode<T, F>* cur) const noexcept {
        cur->push();
        if(cur->left) check_dfs(cur->left);
        if(cur->IsVertex()) cout <<"{" << (cur->from) << "," << (cur->value) << "} ";
        if(cur->right) check_dfs(cur->right);
    }
};