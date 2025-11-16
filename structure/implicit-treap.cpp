#pragma once
#include "../base.cpp"

struct xorshift {
    unsigned long long x;

    xorshift() {
        mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
        x = rnd();
        rep(i, 100) random();
    }
    unsigned long long random() {
        x = x ^ (x << 7);
        return x = x ^ (x >> 9);
    }
};

#if __cplusplus >= 201703L
template<typename S, 
    typename F,
    auto op,
    auto e,
    auto mapping,
    auto composition,
    auto id>
#else
template<typename S, 
    typename F,
    S (*op)(S, S),
    S (*e)(),
    S (*mapping)(S, F),
    void (*composition)(F&, F),
    F (*id)()>
#endif
struct ImplicitTreap {
#if __cplusplus >= 201703L
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>, "op must be function<S(S, S)>");
    static_assert(is_convertible_v<decltype(e), function<S()>>, "e must be function<S()>");
    static_assert(is_convertible_v<decltype(mapping), function<S(S, F)>>, "mapping must be function<S(S, F)>");
    static_assert(is_convertible_v<decltype(composition), function<void(F&, F)>>, "composition must be function<F(F, F)>");
    static_assert(is_convertible_v<decltype(id), function<F()>>, "id must be function<F()>");

    static_assert(op(S(), e()) == S(), "op(S(), e()) must be S()");
    static_assert(mapping(S(), id()) == S(), "mapping(S(), id()) must be S()");
#endif
    
    xorshift rnd;

    struct Node {
        S value = e(), prod = e(), rprod = e();
        F lazy = id();
        unsigned long long priority = numeric_limits<unsigned long long>::max();
        long long cnt = 0;
        bool rev = false;
        Node *l = nullptr, *r = nullptr;

        bool operator< (const Node &other) const {
            return value < other.value;
        }

        bool operator== (const S other) const {
            return value == other;
        }

        bool operator!= (const S other) const {
            return value != other;
        }

        operator S() const {
            return value;
        }
    };

    xorshift rng;

    using pNode = unique_ptr<Node>;

    pNode pNIL;
    Node *NIL = nullptr;

    vector<pNode> pool;
    Node* root = nullptr;

    ImplicitTreap() {
        init();
    }

    ImplicitTreap(long long n, S a) {
        init();
        rep(i, n) insert(i, a);
    }

    ImplicitTreap(const vector<S>& v) {
        init();
        rep(i, v.size()) insert(i, v[i]);
    }

    void init() {
        pNIL = make_unique<Node>();
        NIL = pNIL.get();
        NIL->l = NIL->r = NIL;
        NIL->value = NIL->prod = NIL->rprod = e();
        NIL->lazy = id();
        NIL->cnt = 0;
        NIL->priority = numeric_limits<unsigned long long>::max();
        NIL->rev = false;

        root = NIL;
    }

    long long size() { 
        return root->cnt; 
    }

    // posの前に挿入
    void insert(long long pos, S val) {
        assert(0 <= pos && pos <= size());

        pNode pnx = make_unique<Node>();
        Node* nx = pnx.get();
        nx->value = nx->prod = nx->rprod = val;
        nx->lazy = id();
        nx->priority = rnd.random();
        nx->cnt = 1;
        nx->l = nx->r = NIL;
        nx->rev = false;
        pool.emplace_back(move(pnx));

        insert(root, pos, nx);
    }

    void erase(long long pos) {
        assert(0 <= pos && pos < size());
        erase(root, pos);
    }

    void apply(long long pos, F val) {
        assert(0 <= pos && pos < size());
        apply(pos, pos + 1, val);
    }

    void apply(long long l, long long r, F val) {
        assert(0 <= l && l <= r && r <= size());
        apply(root, l, r, val);
    }

    S prod(long long l, long long r) {
        return prod(root, l, r);
    }

    S get(long long pos) {
        return prod(root, pos, pos + 1);
    }

    void push_back(S val) {
        insert(size(), val);
    }

    void pop_back() {
        if (size() == 0) return;
        erase(size() - 1);
    }

    void push_front(S val) {
        insert(0, val);
    }

    void pop_front() {
        if (size() == 0) return;
        erase(0);
    }

    // int find_first(int l, int r, S x) {
    //     Node *left, *mid, *right;
    //     split(root, l, left, mid);
    //     split(mid, r - l, mid, right);
    //     int res = find(mid, x, l, true);
    //     merge(mid, mid, right);
    //     merge(root, left, mid);
    //     return res;
    // }

    void reverse(long long l, long long r) {
        reverse(root, l, r);
    }

    void rotate(long long l, long long m, long long r) {
        rotate(root, l, m, r);
    }

    void dump() {
        rep(i, size()) cerr << (*this).get(i) << " ";
        cerr << endl;
    }

private:
    void update(Node* node) {
        if (node == NIL) return;
        node->cnt = 1 + node->l->cnt + node->r->cnt;
        node->prod = op(node->l->prod, op(node->value, node->r->prod));
        node->rprod = op(node->r->rprod, op(node->value, node->l->rprod));
    }

    void push(Node* node) {
        if (node == NIL) return;
        if (node->rev) {
            swap(node->l, node->r);
            swap(node->prod, node->rprod);
            if (node->l) node->l->rev ^= 1;
            if (node->r) node->r->rev ^= 1;
            node->rev = false;
        }

        if (node->lazy != id()) {
            if (node->l != NIL) {
                composition(node->l->lazy, node->lazy);
                node->l->prod = mapping(node->l->prod, node->lazy);
                node->l->rprod = mapping(node->l->rprod, node->lazy);
            }
            if (node->r != NIL) {
                composition(node->r->lazy, node->lazy);
                node->r->prod = mapping(node->r->prod, node->lazy);
                node->r->rprod = mapping(node->r->rprod, node->lazy);
            }
            node->value = mapping(node->value, node->lazy);
            node->lazy = id();
        }

        update(node);
    }

    void split(Node* node, long long key, Node*& left, Node*& right) {
        if (node == NIL) { 
            left = right = NIL; 
            return; 
        }
        
        push(node);
        long long pos = node->l->cnt;
        if (key <= pos) {
            split(node->l, key, left, node->l);
            right = node;
        }
        else {
            split(node->r, key - pos - 1, node->r, right);
            left = node;
        }
        update(node);
    }

    void merge(Node*& node, Node* left, Node* right) {
        push(left);
        push(right);
        if (left == NIL || right == NIL) {
            node = (left != NIL) ? left : right;
        } 
        else if (left->priority > right->priority) {
            merge(left->r, left->r, right);
            node = left;
        } 
        else {
            merge(right->l, left, right->l);
            node = right;
        }
        update(node);
    }

    void insert(Node*& node, long long pos, Node* item) {
        Node *left, *right;
        split(node, pos, left, right);
        merge(left, left, item);
        merge(node, left, right);
    }

    void erase(Node*& node, long long pos) {
        Node *left, *mid, *right;
        split(node, pos + 1, mid, right);
        split(mid, pos, left, mid);
        merge(node, left, right);
    }

    void apply(Node*& node, long long l, long long r, F x) {
        Node *left, *mid, *right;
        split(node, l, left, mid);
        split(mid, r - l, mid, right);
        if (mid != NIL) {
            composition(mid->lazy, x);
            mid->prod = mapping(mid->prod, x);
            mid->rprod = mapping(mid->rprod, x);
        }
        merge(mid, mid, right);
        merge(node, left, mid);
    }

    S prod(Node*& node, long long l, long long r) {
        Node *left, *mid, *right;
        split(node, l, left, mid);
        split(mid, r - l, mid, right);
        S res = mid->prod;
        merge(mid, mid, right);
        merge(node, left, mid);
        return res;
    }

    void reverse(Node*& node, long long l, long long r) {
        if (l >= r) return;
        Node *left, *mid, *right;
        split(node, l, left, mid);
        split(mid, r - l, mid, right);
        if (mid != NIL) mid->rev ^= 1;
        merge(mid, mid, right);
        merge(node, left, mid);
    }

    void rotate(Node*& node, long long l, long long m, long long r) {
        reverse(node, l, r);
        reverse(node, l, l + r - m);
        reverse(node, l + r - m, r);
    }

    // int find(Node* node, S x, int offset, bool left_search) {
    //     if (!node || Monoid::op(node->aggregate, x) == x) return -1;
    //     push(node);
    //     if (left_search) {
    //         if (node->left && Monoid::op(node->left->aggregate, x) != x)
    //             return find(node->left, x, offset, true);
    //         if (Monoid::op(node->value, x) != x)
    //             return offset + get_count(node->left);
    //         return find(node->right, x, offset + get_count(node->left) + 1, true);
    //     } else {
    //         if (node->right && Monoid::op(node->right->aggregate, x) != x)
    //             return find(node->right, x, offset + get_count(node->left) + 1, false);
    //         if (Monoid::op(node->value, x) != x)
    //             return offset + get_count(node->left);
    //         return find(node->left, x, offset, false);
    //     }
    // }
};