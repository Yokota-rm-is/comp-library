#pragma once
#include "../base.cpp"

// 参考:https://github.com/kazuma8128/procon-lib/blob/master/Structure/binary_search_tree/red_black_tree/normal/set.cpp
template <typename T, bool multi = false>
struct RedBlackTree {
    using Color = bool;
    static const Color RED = false, BLACK = true;

    struct Node {
        Color color = BLACK;
        long long size = 0;
        long long unique_size = 0;
        long long count = 0;
        T val = T(), sum = T();
        Node *p = 0, *ch[2] = {0, 0};

        operator T() const {
            return val;
        }
    };

    struct iterator {
        Node *node;
        RedBlackTree *rbt;

        iterator(Node *n, RedBlackTree *tree) : node(n), rbt(tree) {}

        iterator& operator++() {
            node = rbt->next(node);
            return *this;
        }

        iterator& operator--() {
            node = rbt->prev(node);
            return *this;
        }

        T operator*() const {
            return node->val;
        }

        bool operator==(const iterator &it) const {
            return node == it.node;
        }

        bool operator!=(const iterator &it) const {
            return node != it.node;
        }
    };

    struct reverse_iterator {
        Node *node;
        RedBlackTree *rbt;

        reverse_iterator(Node *n, RedBlackTree *tree) : node(n), rbt(tree) {}

        reverse_iterator& operator++() {
            node = rbt->prev(node);
            return *this;
        }

        reverse_iterator& operator--() {
            node = rbt->next(node);
            return *this;
        }

        T operator*() const {
            return node->val;
        }

        bool operator==(const reverse_iterator &it) const {
            return node == it.node;
        }

        bool operator!=(const reverse_iterator &it) const {
            return node != it.node;
        }
    };

    RedBlackTree() {
        pNIL = make_unique<Node>();
        NIL = pNIL.get();
        NIL->p = NIL->ch[0] = NIL->ch[1] = NIL;
        NIL->size = 0;
        NIL->unique_size = 0;
        NIL->count = 0;
        NIL->color = BLACK;
        NIL->val = T();
        NIL->sum = T();
        root = NIL;

        front_node = back_node = NIL;
    }

    long long size() const {
        return root->size;
    }

    long long unique_size() const {
        return root->unique_size;
    }

    T front() const {
        return front_node->val;
    }

    T back() const {
        return back_node->val;
    }

    long long count(T val) const {
        return find(root, val)->count;
    }

    long long count(T l, T r) const {
        return count_less_than(r) - count_less_than(l);
    }

    bool contains(T val) const {
        return find(root, val) != NIL;
    }

    long long count_less_than(T val, bool unique = false) const {
        Node *x = lower_bound(root, val);
        if (!unique) return rank(x);
        else return unique_rank(x);
    }

    long long count_less_than_or_equal(T val, bool unique = false) const {
        Node *x = upper_bound(root, val);
        if (!unique) return rank(x);
        else return unique_rank(x);
    }

    long long count_greater_than(T val, bool unique = false) const {
        if (!unique) return size() - count_less_than_or_equal(val, false);
        else return unique_size() - count_less_than_or_equal(val, true);
    }

    long long count_greater_than_or_equal(T val, bool unique = false) const {
        if (!unique) return size() - count_less_than(val, false);
        else return unique_size() - count_less_than(val, true);
    }

    iterator find_greater_than(T val) {
        return upper_bound(val);
    }

    iterator find_greater_than_or_equal(T val) {
        return lower_bound(val);
    }

    iterator find_less_than(T val) {
        Node *x = lower_bound(root, val);
        if (x == front_node) return end();
        return iterator(prev(x), this);
    }

    iterator find_less_than_or_equal(T val) {
        Node *x = upper_bound(root, val);
        if (x == front_node) return end();
        return iterator(prev(x), this);
    }

    T at(long long k) const {
        assert(0 <= k && k < size());

        Node *x = root;
        while (x != NIL) {
            if (k < x->ch[0]->size) {
                x = x->ch[0];
            }
            else if (k < x->ch[0]->size + x->count) {
                return x->val;
            }
            else {
                k -= x->ch[0]->size + x->count;
                x = x->ch[1];
            }
        }
        return x->val;
    }

    pair<iterator, bool> insert(T val, long long num = 1) {
        Node *x = root, *y = NIL;
        while (x != NIL) {
            if (val == x->val) {
                if (!multi) return {iterator(x, this), false};

                x->count += num;
                while (x != NIL) update(x), x = x->p;
                return {iterator(x, this), false};
            }
            y = x;
            x = x->ch[val > x->val];
        }
        Node *v = new_node(val, num);
        v->p = y;
        if (y == NIL) {
            root = v;
        }
        else {
            y->ch[val > y->val] = v;
        }
        while (y != NIL) update(y), y = y->p;
        insert_fix(v);

        if (front_node == NIL || val < front_node->val) front_node = v;
        if (back_node == NIL || back_node->val < val) back_node = v;

        return {iterator(v, this), true};
    }

    long long erase_all(T val) {
        return erase(val, size());
    }

    long long erase(T val, long long num = 1) {
        Node *x = find(root, val);
        if (x == NIL) return 0;

        num = min(num, x->count);
        x->count -= num;
        if (x->count > 0) {
            while (x != NIL) update(x), x = x->p;
            return num;
        }

        Node *y = x, *z;
        Color c = y->color;
        if (x->ch[0] == NIL) {
            z = x->ch[1];
            transplant(x, x->ch[1]);
        }
        else if (x->ch[1] == NIL) {
            z = x->ch[0];
            transplant(x, x->ch[0]);
        }
        else {
            y = minimum(x->ch[1]);
            c = y->color;
            z = y->ch[1];
            if (y->p == x) {
                z->p = y;
            }
            else {
                transplant(y, y->ch[1]);
                y->ch[1] = x->ch[1];
                y->ch[1]->p = y;
            }
            transplant(x, y);
            y->ch[0] = x->ch[0];
            y->ch[0]->p = y;
            y->color = x->color;
            update(y);
        }
        Node *t = z->p;
        while (t != NIL) update(t), t = t->p;
        if (c == BLACK) {
            erase_fix(z);
        }

        if (front_node == x) front_node = next(x);
        if (back_node == x) back_node = prev(x);

        return num;
    }

    void erase(iterator first, iterator last) {
        while (first != last) {
            first = erase(first);
        }
    }

    iterator erase(iterator pos) {
        if (pos.node == NIL) return end();

        T val = *pos;
        iterator next_it = pos;
        ++next_it;
        erase(val);
        return next_it;
    }

    T sum() const {
        return root->sum;
    }

    T sum(T l, T r) const {
        return sum_less_than(r) - sum_less_than(l);
    }

    T sum_less_than(T x) const {
        T ret = T();

        Node *v = root;
        while (v != NIL) {
            if (x <= v->val) {
                v = v->ch[0];
            }
            else {
                ret += v->val * v->count;
                ret += v->ch[0]->sum;
                v = v->ch[1];
            }
        }

        return ret;
    }

    T sum_less_than_or_equal(T x) const {
        return sum_less_than(x) + x * count(x);
    }

    T sum_greater_than(T x) const {
        T ret = T();

        Node *v = root;
        while (v != NIL) {
            if (x < v->val) {
                ret += v->val * v->count;
                ret += v->ch[1]->sum;
                v = v->ch[0];
            }
            else {
                v = v->ch[1];
            }
        }

        return ret;
    }

    T sum_greater_than_or_equal(T x) const {
        return sum_greater_than(x) + x * count(x);
    }

    // 1-indexed
    T kth_min(long long k) const {
        assert(1 <= k && k <= size());

        return at(k - 1);
    }

    // 1-indexed
    T kth_max(long long k) const {
        assert(1 <= k && k <= size());

        return at(size() - k);
    }

    // 1-indexed 
    T sum_min_k(long long k) const {
        assert(0 <= k);
        if (k == 0) return 0;
        k = min(k, size());

        T kth_val = kth_min(k);
        long long kth_val_count = k - count_less_than(kth_val);
        return sum_less_than(kth_val) + kth_val * kth_val_count;
    }

    // 1-indexed
    T sum_max_k(long long k) const {
        assert(0 <= k);
        if (k == 0) return 0;
        k = min(k, size());

        T kth_val = kth_max(k);
        long long kth_val_count = k - count_greater_than(kth_val);
        return sum_greater_than(kth_val) + kth_val * kth_val_count;
    }

    Node* next(Node *x) const {
        assert(x != NIL);
        if (x == back_node) return NIL;

        if (x->ch[1] != NIL) {
            return minimum(x->ch[1]);
        }
        while (x->p != NIL && x == x->p->ch[1]) {
            x = x->p;
        }
        return x->p;
    }

    Node* prev(Node *x) const {
        assert(x != front_node);
        if (x == NIL) return back_node;

        if (x->ch[0] != NIL) {
            return maximum(x->ch[0]);
        }
        while (x->p != NIL && x == x->p->ch[0]) {
            x = x->p;
        }
        return x->p;
    }

    iterator begin() {
        return iterator(front_node, this);
    }

    iterator end() {
        return iterator(NIL, this);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(back_node, this);
    }

    reverse_iterator rend() {
        return reverse_iterator(NIL, this);
    }

    iterator find(T val) {
        return iterator(find(root, val), this);
    }

    iterator lower_bound(T val) {
        return iterator(lower_bound(root, val), this);
    }

    iterator upper_bound(T val) {
        return iterator(upper_bound(root, val), this);
    }

    void dump() const {
        rep(i, size()) {
            cerr << at(i) << " \n"[i == size() - 1];
        }
    }

private:
    using pN = unique_ptr<Node>;

    pN pNIL;
    Node *NIL = nullptr;
    vector<pN> A;
    Node *root;
    Node *front_node, *back_node;

    Node* new_node(T val, long long num = 1) {
        pN pnx = make_unique<Node>();
        Node *nx = pnx.get();
        nx->color = RED;
        nx->val = val;
        nx->sum = val;
        nx->size = nx->count = num;
        nx->unique_size = 1;
        nx->p = nx->ch[0] = nx->ch[1] = NIL;

        A.emplace_back(move(pnx));
        return nx;
    }

    void update(Node *x) {
        x->size = x->ch[0]->size + x->ch[1]->size + x->count;
        x->unique_size = x->ch[0]->unique_size + x->ch[1]->unique_size + 1;
        x->sum = x->ch[0]->sum + x->ch[1]->sum + x->val * x->count;
    }

    void rotate(Node *x, int b) {
        Node *y = x->ch[1 - b];
        x->ch[1 - b] = y->ch[b];
        if (y->ch[b] != NIL) {
            y->ch[b]->p = x;
        }
        y->p = x->p;
        if (x->p == NIL) {
            root = y;
        }
        else {
            x->p->ch[x != x->p->ch[0]] = y;
        }
        y->ch[b] = x;
        x->p = y;
        update(x);
        update(y);
    }

    void insert_fix(Node *x) {
        while (x->p->color == RED) {
            int b = (x->p != x->p->p->ch[0]);
            Node *y = x->p->p->ch[1 - b];
            if (y->color == RED) {
                x->p->color = BLACK;
                y->color = BLACK;
                x->p->p->color = RED;
                x = x->p->p;
                continue;
            }
            if (x == x->p->ch[1 - b]) {
                x = x->p;
                rotate(x, b);
            }
            x->p->color = BLACK;
            x->p->p->color = RED;
            rotate(x->p->p, 1 - b);
        }
        root->color = BLACK;
    }

    void transplant(Node *u, Node *v) {
        if (u->p == NIL) {
            root = v;
        }
        else {
            u->p->ch[u != u->p->ch[0]] = v;
        }
        v->p = u->p;
    }

    void erase_fix(Node *x) {
        while (x != root && x->color == BLACK) {
            int b = (x != x->p->ch[0]);
            Node *w = x->p->ch[1 - b];
            if (w->color == RED) {
                w->color = BLACK;
                x->p->color = RED;
                rotate(x->p, b);
                w = x->p->ch[1 - b];
            }
            if (w->ch[b]->color == BLACK && w->ch[1 - b]->color == BLACK) {
                w->color = RED;
                x = x->p;
                continue;
            }
            if (w->ch[1 - b]->color == BLACK) {
                w->ch[b]->color = BLACK;
                w->color = RED;
                rotate(w, 1 - b);
                w = x->p->ch[1 - b];
            }
            w->color = x->p->color;
            x->p->color = BLACK;
            w->ch[1 - b]->color = BLACK;
            rotate(x->p, b);
            x = root;
        }
        x->color = BLACK;
    }

    Node* find(Node *x, T val) const {
        while (x != NIL) {
            if (val == x->val) return x;
            x = x->ch[val > x->val];
        }
        return NIL;
    }

    Node* lower_bound(Node *x, T val) const {
        Node *ret = NIL;
        while (x != NIL) {
            if (val <= x->val) {
                ret = x;
                x = x->ch[0];
            } 
            else {
                x = x->ch[1];
            }
        }
        return ret;
    }

    Node* upper_bound(Node *x, T val) const {
        Node *ret = NIL;
        while (x != NIL) {
            if (val < x->val) {
                ret = x;
                x = x->ch[0];
            } 
            else {
                x = x->ch[1];
            }
        }
        return ret;
    }

    // [l, r)の要素数 (重複を含む)
    long long rank(Node* l, Node* r) const {
        return rank(r) - rank(l);
    }

    // [0, pos)の要素数 (重複を含む)
    long long rank(Node* p) const {
        if (p == NIL) return size();

        long long ret = 0;
        T val = p->val;
        Node *x = root;

        while (x != NIL) {
            if (val <= x->val) {
                x = x->ch[0];
            } 
            else {
                ret += x->ch[0]->size + x->count;
                x = x->ch[1];
            }
        }
        return ret;
    }

    // [l, r)の要素数 (重複を含まない)
    long long unique_rank(Node* l, Node* r) const {
        return unique_rank(r) - unique_rank(l);
    }

    // [0, pos)の要素数 (重複を含まない)
    long long unique_rank(Node* p) const {
        if (p == NIL) return unique_size();

        long long ret = 0;
        T val = p->val;
        Node *x = root;

        while (x != NIL) {
            if (val <= x->val) {
                x = x->ch[0];
            } 
            else {
                ret += x->ch[0]->unique_size + 1;
                x = x->ch[1];
            }
        }
        return ret;
    }

    Node* minimum(Node *x) const {
        if (x == NIL) return NIL;
        while (x->ch[0] != NIL) {
            x = x->ch[0];
        }
        return x;
    }

    Node* maximum(Node *x) const {
        if (x == NIL) return NIL;
        while (x->ch[1] != NIL) {
            x = x->ch[1];
        }
        return x;
    }
};

template<typename T> using Set = RedBlackTree<T, false>;
template<typename T> using MultiSet = RedBlackTree<T, true>;