#pragma once
#include "../base.cpp"

// 参考: https://ei1333.hateblo.jp/entry/2018/05/29/011140
#if __cplusplus >= 201703L
template<class T,
    auto op,
    auto e,
    class F,
    auto mapping,
    auto composition,
    auto id>
#else
template<class T,
    T (*op)(T, T),
    T (*e)(),
    class F,
    T (*mapping)(T, F),
    F (*composition)(F, F),
    F (*id)()>
#endif
struct LinkCutTree {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<T(T, T)>>, "op must be function<T(T, T)>");
    static_assert(is_convertible_v<decltype(e), function<T()>>, "e must be function<T()>");
    static_assert(is_convertible_v<decltype(mapping), function<T(T, F)>>, "mapping must be function<T(T, F)>");
    static_assert(is_convertible_v<decltype(composition), function<F(F, F)>>, "composition must be function<F(F, F)>");
    static_assert(is_convertible_v<decltype(id), function<F()>>, "id must be function<F()>");
#endif
    struct Node {
        Node *l, *r, *p;
        int idx;
        T value, prod, rprod;
        F lazy;

        bool rev;
        long long size;

        bool is_root() {
            return !p || (p->l != this && p->r != this);
        }

        Node(int i, T v) :
            idx(i), value(v), prod(v), rprod(v), lazy(id()), size(1),
            l(nullptr), r(nullptr), p(nullptr), rev(false) {}
    };

    using S = Node;
    using pS = unique_ptr<S>;

    vector<pS> A;

    LinkCutTree() {}

    Node *make_node(int idx, T v) {
        pS pnx = make_unique<S>(idx, v);
        S *nx = pnx.get();
        A.emplace_back(move(pnx));
        return nx;
    }

    void propagate(Node *t, F f) {
        t->lazy = composition(t->lazy, f);
        t->value = mapping(t->value, f);
        t->prod = mapping(t->prod, f);
        t->rprod = mapping(t->rprod, f);
    }

    void toggle(Node *t) {
        assert(t);
        swap(t->l, t->r);
        swap(t->prod, t->rprod);
        t->rev ^= true;
    }

    void push(Node *t) {
        if(t->lazy != id()) {
            if(t->l) propagate(t->l, t->lazy);
            if(t->r) propagate(t->r, t->lazy);
            t->lazy = id();
        }
        if(t->rev) {
            if(t->l) toggle(t->l);
            if(t->r) toggle(t->r);
            t->rev = false;
        }
    }

    void push_rev(Node *t) {
        if (!t->rev) return;
        if (t->l) toggle(t->l);
        if (t->r) toggle(t->r);
        t->rev = false;
    }

    void update(Node *t) {
        t->size = 1;
        t->prod = t->value;
        t->rprod = t->value;
        if(t->l) {
            t->size += t->l->size;
            t->prod = op(t->l->prod, t->prod);
            t->rprod = op(t->rprod, t->l->rprod);
        }
        if(t->r) {
            t->size += t->r->size;
            t->prod = op(t->prod, t->r->prod);
            t->rprod = op(t->r->rprod, t->rprod);
        }
    }

    void rotr(Node *t) {
        auto *x = t->p, *y = x->p;
        push(x), push(t);
        if ((x->l = t->r)) t->r->p = x;
        t->r = x, x->p = t;
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
        }
    }

    void rotl(Node *t) {
        auto *x = t->p, *y = x->p;
        push(x), push(t);
        if((x->r = t->l)) t->l->p = x;
        t->l = x, x->p = t;
        update(x), update(t);
        if((t->p = y)) {
            if(y->l == x) y->l = t;
            if(y->r == x) y->r = t;
        }
    }

    void splay(Node *t) {
        push(t);
        while(!t->is_root()) {
            auto *q = t->p;
            if(q->is_root()) {
                push_rev(q), push_rev(t);
                if(q->l == t) rotr(t);
                else rotl(t);
            } 
            else {
                auto *r = q->p;
                push_rev(r), push_rev(q), push_rev(t);
                if(r->l == q) {
                    if(q->l == t) rotr(q), rotr(t);
                    else rotl(t), rotr(t);
                } 
                else {
                    if(q->r == t) rotl(q), rotl(t);
                    else rotr(t), rotl(t);
                }
            }
        }
    }

    Node *expose(Node *t) {
        Node *rp = nullptr;
        for(Node *cur = t; cur; cur = cur->p) {
            splay(cur);
            cur->r = rp;
            update(cur);
            rp = cur;
        }
        splay(t);
        return rp;
    }

    bool link(Node *child, Node *parent) {
        if (is_same(child, parent)) return false;
        
        evert(child);
        expose(child);
        expose(parent);
        child->p = parent;
        parent->r = child;
        update(parent);

        return true;
    }

    void cut(Node *child) {
        expose(child);
        auto *parent = child->l;
        child->l = nullptr;
        parent->p = nullptr;
        update(child);
    }

    bool cut(Node *child, Node *parent) {
        if (!is_same(child, parent)) return false;

        evert(child);
        cut(parent);
        return true;
    }

    void evert(Node *t) {
        expose(t);
        toggle(t);
        push(t);
    }

    Node *lca(Node *u, Node *v) {
        if (!is_same(u, v)) return nullptr;
        expose(u);
        return expose(v);
    }

    vector<long long> get_path(Node *x) {
        vector<long long> vs;
        function< void(Node *) > dfs = [&](Node *cur) {
            if (!cur) return;
            push(cur);
            dfs(cur->r);
            vs.push_back(cur->idx);
            dfs(cur->l);
        };
        expose(x);
        dfs(x);
        return vs;
    }

    vector<long long> get_path(Node *x, Node *y) {
        if (!is_same(x, y)) return {};
        evert(y);
        expose(x);
        return get_path(x);
    }

    void apply(Node *t, F f) {
        expose(t);
        t->value = mapping(t->value, f);
        update(t);
    }

    void apply(Node *x, Node *y, F f) {
        if (!is_same(x, y)) return;
        evert(y);
        expose(x);
        propagate(x, f);
        push(x);
        update(x);
    }

    Node *get_kth(Node *x, int k) {
        expose(x);
        while(x) {
            push(x);
            if (x->r && x->r->size > k) {
                x = x->r;
            } 
            else {
                if(x->r) k -= x->r->size;
                if(k == 0) return x;
                k -= 1;
                x = x->l;
            }
        }
        return nullptr;
    }

    Node *get_kth(Node *x, Node *y, int k) {
        if (!is_same(x, y)) return nullptr;
        evert(y);
        expose(x);
        return get_kth(x, k);
    }

    Node *get_root(Node *x) {
        expose(x);
        while(x->l) {
            push(x);
            x = x->l;
        }
        return x;
    }

    bool is_same(Node *x, Node *y) {
        Node* rx = get_root(x);
        Node* ry = get_root(y);
        return (rx && ry && rx == ry);
    }

    long long depth(Node *x) {
        expose(x);
        return x->size - 1;
    }

    T prod(Node *x, Node *y) {
        assert(is_same(x, y));
        evert(x);
        expose(y);
        return y->prod;
    }
};