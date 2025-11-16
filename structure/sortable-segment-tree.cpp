#pragma once
#include "../base.cpp"

#if __cplusplus >= 201703L
template<class Key, 
    class S, 
    auto op,
    auto e,
    class F,
    auto mapping>
#else
template<class Key,
    S (*op)(S, S),
    S (*e)(),
    class F,
    S (*mapping)(S, F)>
#endif
struct SegmentTree {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>, "op must be function<S(S, S)>");
    static_assert(is_convertible_v<decltype(e), function<S()>>, "e must be function<S()>");
    static_assert(is_convertible_v<decltype(mapping), function<S(S, F)>>, "mapping must be function<S(S, F)>");

    static_assert(op(S(), e()) == S(), "op(S(), e()) must be S()");
#endif
private:
    struct Node {
        Key k, kmin, kmax;
        S val, prod, rprod;
        bool flip = false;
        int sz_all = 1, sz_inner = 1;
        unsigned int p;
        Node *inner_l = 0, *inner_r = 0, *outer_l = 0, *outer_r = 0;
    };

    using pNode = unique_ptr<Node>;

    vector<pNode> A;
    Node *root;
    long long N;

    static unsigned int xor128() {
        static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 86675123;
        unsigned int t = (x ^ (x << 11));
        x = y, y = z, z = w;
        return (w = (w ^ (w >> 19)) ^ (t ^ ( t >> 8)));
    }

    void update(Node *v) {
        v->sz_inner = 1;
        v->prod = e();
        v->rprod = e();
        v->kmin = v->kmax = v->k;
        if (v->outer_l) {
            v->prod = op(v->prod, v->outer_l->prod);
            v->rprod = op(v->outer_l->rprod, v->rprod);
        }
        if (v->inner_l) {
            v->sz_inner += v->inner_l->sz_inner;
            v->prod = op(v->prod, v->inner_l->prod);
            v->rprod = op(v->inner_l->rprod, v->rprod);
            v->kmin = min(v->kmin, v->inner_l->kmin);
            v->kmax = max(v->kmax, v->inner_l->kmax);
        }
        v->prod = op(v->prod, v->val);
        v->rprod = op(v->val, v->rprod);
        if (v->inner_r) {
            v->sz_inner += v->inner_r->sz_inner;
            v->prod = op(v->prod, v->inner_r->prod);
            v->rprod = op(v->inner_r->rprod, v->rprod);
            v->kmin = min(v->kmin, v->inner_r->kmin);
            v->kmax = max(v->kmax, v->inner_r->kmax);
        }
        if (v->outer_r) {
            v->prod = op(v->prod, v->outer_r->prod);
            v->rprod = op(v->outer_r->rprod, v->rprod);
        }
        v->sz_all = v->sz_inner + (v->outer_l ? v->outer_l->sz_all : 0) + (v->outer_r ? v->outer_r->sz_all : 0);
    }

    int size(Node *v) {
        return v ? v->sz_all : 0;
    }

    Node *make_node(Key k, S val) {
        ++N;
        pNode pnx = make_unique<Node>();
        Node* nx = pnx.get();
        nx->k = nx->kmin = nx->kmax = k;
        nx->val = nx->prod = nx->rprod = val;
        nx->flip = false;
        nx->sz_all = nx->sz_inner = 1;
        nx->p = xor128();
        nx->inner_l = nx->inner_r = nx->outer_l = nx->outer_r = nullptr;
        A.push_back(move(pnx));
        
        return nx;
    }

    void reverse(Node *v) {
        swap(v->inner_l, v->inner_r);
        swap(v->outer_l, v->outer_r);
        swap(v->prod, v->rprod);
        v->flip ^= 1;
    }

    void push_down(Node *v) {
        if (!v->flip) return;
        if (v->inner_l) reverse(v->inner_l);
        if (v->inner_r) reverse(v->inner_r);
        if (v->outer_l) reverse(v->outer_l);
        if (v->outer_r) reverse(v->outer_r);
        v->flip = false;
    }

    Node *insert(Node *v, Node *n, int k) {
        if (!v) return n;
        push_down(v);
        int szl = size(v->outer_l);
        if (v->p < n->p) {
            pair<Node*, Node*> s = split_outer(v, k);
            n->outer_l = s.first;
            n->outer_r = s.second;
            update(n);
            return n;
        }
        else if (szl <= k && k < szl + v->sz_inner) {
            pair<Node*, Node*> s = split_outer(v, k);
            s.first = insert(s.first, n, k);
            update(s.first);
            return merge_outer(s.first, s.second);
        }
        else if (k < szl) {
            v->outer_l = insert(v->outer_l, n, k);
        }
        else {
            v->outer_r = insert(v->outer_r, n, k - szl - v->sz_inner);
        }
        update(v);
        return v;
    }

    Node *merge_inner(Node *a, Node *b) {
        if (!a || !b) return !a ? b : a;
        push_down(a), push_down(b);
        if (a->p > b->p) {
            a->inner_r = merge_inner(a->inner_r, b);
            update(a);
            return a;
        }
        else {
            b->inner_l = merge_inner(a, b->inner_l);
            update(b);
            return b;
        }
    }

    Node *merge_outer(Node *a, Node *b) {
        if (!a || !b) return !a ? b : a;
        push_down(a), push_down(b);
        if (a->p > b->p) {
            a->outer_r = merge_outer(a->outer_r, b);
            update(a);
            return a;
        }
        else {
            b->outer_l = merge_outer(a, b->outer_l);
            update(b);
            return b;
        }
    }

    tuple<Node*, Node*, Node*> cut_inner(Node *v, int k) {
        if (!v) return {nullptr, nullptr, nullptr};
        push_down(v);
        int szl = size(v->inner_l);
        if (k <= szl) {
            if (k == szl) {
                tuple<Node*, Node*, Node*> res = {v->inner_l, v, v->inner_r};
                v->inner_l = v->inner_r = nullptr;
                update(v);
                return res;
            }
            auto [a, b, c] = cut_inner(v->inner_l, k);
            v->inner_l = c;
            update(v);
            return {a, b, v};
        }
        else {
            auto [a, b, c] = cut_inner(v->inner_r, k - szl - 1);
            v->inner_r = a;
            update(v);
            return {v, b, c};
        }
    }

    tuple<Node*, Node*, Node*> cut_outer(Node *v, int k) {
        if (!v) return {nullptr, nullptr, nullptr};
        push_down(v);
        int szl = size(v->outer_l);
        int szr = szl + v->sz_inner;
        if (k < szl) {
            auto [a, b, c] = cut_outer(v->outer_l, k);
            v->outer_l = c;
            update(v);
            return {a, b, v};
        }
        else if (szr <= k) {
            auto [a, b, c] = cut_outer(v->outer_r, k - szr);
            v->outer_r = a;
            update(v);
            return {v, b, c};
        }
        else {
            Node *tmp_l = v->outer_l, *tmp_r = v->outer_r;
            v->outer_l = v->outer_r = nullptr;
            auto [a, b, c] = cut_inner(v, k - szl);
            a = merge_outer(tmp_l, a);
            c = merge_outer(c, tmp_r);
            return {a, b, c};
        }
    }

    pair<Node*, Node*> split_inner(Node *v, int k) {
        if (!v) return {nullptr, nullptr};
        push_down(v);
        int szl = size(v->inner_l);
        if (k <= szl) {
            pair<Node*, Node*> s = split_inner(v->inner_l, k);
            v->inner_l = s.second;
            update(v);
            return {s.first, v};
        } 
        else {
            pair<Node*, Node*> s = split_inner(v->inner_r, k - szl - 1);
            v->inner_r = s.first;
            update(v);
            return {v, s.second};
        }
    }

    void update_range_inner(Node *v, int l, int r) {
        if (!v) return;
        if (l == 0 && r == v->sz_all) {
            // propagate
            return;
        }
        push_down(v);
        int szl = size(v->inner_l);
        int szr = szl + 1;
        if(l < szl){
            if(r <= szl){
                update_range_inner(v->inner_l, l, r);
                update(v);
                return;
            }
            update_range_inner(v->inner_l, l, szl);
            l = szl;
        }
        if (szr < r) {
            if (szr <= l) {
                update_range_inner(v->inner_r, l - szr, r - szr);
                update(v);
                return;
            }
            update_range_inner(v->inner_r, 0, r - szr);
            r = szr;
        }
        if (l != r) {
            // apply
        }
        update(v);
    }

    void update_range_outer(Node *v, int l, int r) {
        if (!v) return;
        if (l == 0 && r == v->sz_all){
            // propagate
            return;
        }
        push_down(v);
        int szl = size(v->outer_l);
        int szr = szl + v->sz_inner;
        if (l < szl) {
            if (r <= szl) {
                update_range_outer(v->outer_l, l, r);
                update(v);
                return;
            }
            update_range_outer(v->outer_l, l, szl);
            l = szl;
        }
        if (szr < r) {
            if (szr <= l) {
                update_range_outer(v->outer_r, l - szr, r - szr);
                update(v);
                return;
            }
            update_range_outer(v->outer_r, 0, r - szr);
            r = szr;
        }
        if (l != r) {
            // apply
        }
        update(v);
    }

    S query_range_inner(Node *v, int l, int r) {
        if (!v) return e();
        if (l == 0 && r == v->sz_all) return v->prod;
        push_down(v);
        int szl = size(v->inner_l);
        int szr = szl + 1;
        S left_q = e(), right_q = left_q;
        if (l < szl) {
            if (r <= szl) return query_range_inner(v->inner_l, l, r);
            left_q = query_range_inner(v->inner_l, l, szl);
            l = szl;
        }
        if (szr < r) {
            if (szr <= l) return query_range_inner(v->inner_r, l - szr, r - szr);
            right_q = query_range_inner(v->inner_r, 0, r - szr);
            r = szr;
        }
        S res = (l == r ? e() : v->val);
        res = op(left_q, res);
        res = op(res, right_q);
        return res;
    }

    S query_range_outer(Node *v, int l, int r) {
        if (!v) return e();
        if (l == 0 && r == v->sz_all) return v->prod;
        push_down(v);
        int szl = size(v->outer_l);
        int szr = szl + v->sz_inner;
        S left_q = e(), right_q = left_q;
        if (l < szl){
            if (r <= szl) return query_range_outer(v->outer_l, l, r);
            left_q = query_range_outer(v->outer_l, l, szl);
            l = szl;
        }
        if (szr < r) {
            if (szr <= l) return query_range_outer(v->outer_r, l - szr, r - szr);
            right_q = query_range_outer(v->outer_r, 0, r - szr);
            r = szr;
        }
        S res = (l == r ? e() : query_range_inner(v, l - szl, r - szl));
        res = op(left_q, res);
        res = op(res, right_q);
        return res;
    }

    pair<Node*, Node*> split_outer(Node *v, int k) {
        if (!v) return {nullptr, nullptr};
        push_down(v);
        int szl = size(v->outer_l);
        int szr = szl + v->sz_inner;
        if (k < szl){
            pair<Node*, Node*> s = split_outer(v->outer_l, k);
            v->outer_l = s.second;
            update(v);
            return {s.first, v};
        }
        else if (szr <= k) {
            pair<Node*, Node*> s = split_outer(v->outer_r, k - szr);
            v->outer_r = s.first;
            update(v);
            return {v, s.second};
        }
        else {
            Node *tmp_l = v->outer_l, *tmp_r = v->outer_r;
            v->outer_l = v->outer_r = nullptr;
            pair<Node*, Node*> s = split_inner(v, k - szl);
            s.first = merge_outer(tmp_l, s.first);
            s.second = merge_outer(s.second, tmp_r);
            return {s.first, s.second};
        }
    }

    tuple<Node*, Node*, Node*> split_range_outer(Node *v, int l, int r) {
        auto [a, b] = split_outer(v, l);
        auto [bb, c] = split_outer(b, r - l);
        return {a, bb, c};
    }

    pair<Node*, Node*> split_key(Node *v, Key k) {
        if (!v) return {nullptr, nullptr};
        if (k < v->kmin) return {nullptr, v};
        else if (v->kmax <= k) return {v, nullptr};
        push_down(v);
        if (k < v->k) {
            pair<Node*, Node*> s = split_key(v->inner_l, k);
            v->inner_l = s.second;
            update(v);
            return {s.first, v};
        }
        else {
            pair<Node*, Node*> s = split_key(v->inner_r, k);
            v->inner_r = s.first;
            update(v);
            return {v, s.second};
        }
    }

    Node *merge_compress(Node *a, Node *b) {
        if (!a || !b) return !a ? b : a;
        push_down(a), push_down(b);
        if (a->p < b->p) swap(a, b);
        if (a->k <= b->kmin) {
            a->inner_r = merge_compress(a->inner_r, b);
        }
        else if (b->kmax <= a->k) {
            a->inner_l = merge_compress(a->inner_l, b);
        }
        else {
            auto [bl, br] = split_key(b, a->k);
            a->inner_l = merge_compress(a->inner_l, bl);
            a->inner_r = merge_compress(a->inner_r, br);
        }
        update(a);
        return a;
    }

    Node *sort_inner(Node *v) {
        if (!v) return nullptr;
        Node *tmp_l = v->outer_l, *tmp_r = v->outer_r;
        push_down(v);
        v->outer_l = v->outer_r = nullptr;
        Node *res = sort_inner(tmp_l);
        if ((v->inner_l && v->k < v->inner_l->kmax) || (v->inner_r && v->inner_r->kmin < v->k)) reverse(v);
        res = merge_compress(res, v);
        res = merge_compress(res, sort_inner(tmp_r));
        return res;
    }

    void enumerate_inner(Node *v, vector<pair<Key, S>> &res) {
        if (!v) return;
        push_down(v);
        if (v->inner_l) enumerate_inner(v->inner_l, res);
        res.push_back({v->key, v->val});
        if (v->inner_r) enumerate_inner(v->inner_r, res);
    }

    void enumerate_outer(Node *v, vector<pair<Key, S>> &res) {
        if (!v) return;
        push_down(v);
        if (v->outer_l) enumerate_outer(v->outer_l, res);
        enumerate_inner(v, res);
        if (v->outer_r) enumerate_outer(v->outer_r, res);
    }

    void p_satisfy(Node *v) {
        if (!v->outer_l){
            if (!v->outer_r || v->p > v->outer_r->p) return;
            swap(v->p, v->outer_r->p);
            p_satisfy(v->outer_r);
        }
        else if (!v->outer_r) {
            if (v->p > v->outer_l->p) return;
            swap(v->p, v->outer_l->p);
            p_satisfy(v->outer_l);
        }
        else {
            if (v->outer_l->p > v->outer_r->p) {
                if (v->p > v->outer_l->p) return;
                swap(v->p, v->outer_l->p);
                p_satisfy(v->outer_l);
            }
            else {
                if (v->p > v->outer_r->p) return;
                swap(v->p, v->outer_r->p);
                p_satisfy(v->outer_r);
            }
        }
    }

    Node *build(int l, int r, vector<pair<Key, S>> &v) {
        int mid = (l + r) / 2;
        Node *u = make_node(v[mid].first, v[mid].second);

        if (l < mid) u->outer_l = build(l, mid, v);
        else u->outer_l = nullptr;
        if (mid + 1 < r) u->outer_r = build(mid + 1, r, v);
        else u->outer_r = nullptr;

        p_satisfy(u);
        update(u);
        return u;
    }

public:
    SegmentTree() : root(nullptr), N(0) {}
    SegmentTree(vector<pair<Key, S>> &v) : root(v.empty() ? nullptr : build(0, v.size(), v)), N(0) {}

    void insert(int k, Key key, S x) {
        root = insert(root, make_node(key, x), k);
    }

    void erase(int k) {
        auto [a, b, c] = cut_outer(root, k);
        root = merge_outer(a, c);
    }

    void apply(int k, Key key, F f) {
        auto [a, b, c] = cut_outer(root, k);
        b->k = key;
        b->val = mapping(b->val, f);
        update(b);
        root = merge_outer(a, merge_outer(b, c));
    }

    void apply(int k, F f) {
        auto [a, b, c] = cut_outer(root, k);
        b->val = mapping(b->val, f);
        update(b);
        root = merge_outer(a, merge_outer(b, c));
    }

    S get(int k) {
        return query_range_outer(root, k, k + 1);
    }

    S prod(int l, int r) {
        if (r == l) return e();
        return query_range_outer(root, l, r);
    }

    S prod_all() {
        assert(root);
        return root->prod;
    }

    void reverse(int l, int r) {
        if (r == l) return;
        auto [a, b, c] = split_range_outer(root, l, r);
        reverse(b);
        root = merge_outer(a, merge_outer(b, c));
    }

    void sort(int l, int r, bool descending = false) {
        if (r == l) return;
        auto [a, b, c] = split_range_outer(root, l, r);
        b = sort_inner(b);
        if (descending) reverse(b);
        root = merge_outer(a, merge_outer(b, c));
    }

    vector<pair<Key, S>> to_vector() {
        vector<pair<Key, S>> res;
        enumerate_outer(root, res);
        return res;
    }
};