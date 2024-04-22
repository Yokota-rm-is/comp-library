#pragma once
#include "../base.cpp"

template<typename T, typename F>
struct Node {
    Node *l = 0, *r = 0, *p = 0;
    T value = 0;
    T prod = 0, rprod = 0;
    F lazy = {1, 0};
    long long index = -1;
    long long z = 0;
    long long sumz = 0;
    bool rev = false;

    bool operator< (const Node &other) const {
        return value < other.value;
    }

    bool operator== (const T other) const {
        return value == other;
    }

    bool operator!= (const T other) const {
        return value != other;
    }

    operator T() const {
        return value;
    }

    friend ostream& operator << (ostream &os, const Node<T, F>& node) {
        return os << node.value;
    }
};

template<typename T, typename F>
struct Operation {
    using S = Node<T, F>;

    Operation() {};

    virtual T e() = 0;

    virtual void operator() (S* x) = 0;
};

template<typename T, typename F>
struct Max : Operation<T, F> {
    using S = Node<T, F>;

    Max(): _e(numeric_limits<T>::min()) {};

    T e() override {
        return _e;
    }

    void operator() (S* x) override {
        x->prod = max({x->l->prod, x->value, x->r->prod});
        x->rprod = max({x->r->rprod, x->value, x->l->rprod});
        x->sumz = x->l->sumz + x->z + x->r->sumz;
    }

private:
    T _e;
};

template<typename T, typename F>
struct Min: Operation<T, F> {
    using S = Node<T, F>;

    Min(): _e(numeric_limits<T>::max()) {};

    T e() override {
        return _e;
    }

    void operator() (S* x) override {
        x->prod = min({x->l->prod, x->value, x->r->prod});
        x->rprod = min({x->r->rprod, x->value, x->l->rprod});
        x->sumz = x->l->sumz + x->z + x->r->sumz;
    }


private:
    T _e;
};

template<typename T, typename F>
struct Sum: Operation<T, F> {
    using S = Node<T, F>;

    Sum(): _e(T(0)) {};

    T e() override {
        return _e;
    }

    void operator() (S* x) override {
        x->prod = x->l->prod + x->value + x->r->prod;
        x->rprod = x->r->rprod + x->value + x->l->rprod;
        x->sumz = x->l->sumz + x->z + x->r->sumz;
    }

private:
    T _e;
};

template<typename T, typename F>
struct Mul: Operation<T, F> {
    using S = Node<T, F>;

    Mul(): _e(T(1)) {};

    T e() override {
        return _e;
    }

    void operator() (S* x) override {
        x->prod = x->l->prod * x->value * x->r->prod;
        x->rprod = x->r->rprod * x->value * x->l->rprod;
        x->sumz = x->l->sumz + x->z + x->r->sumz;
    }

private:
    T _e;
};

template<typename T, typename F>
struct GCD : Operation<T, F> {
    using S = Node<T, F>;

    GCD(): _e(T(0)) {};

    T e() override {
        return _e;
    }

    void operator() (S* x) override {
        x->prod = gcd(gcd(x->l->prod, x->value), x->r->prod);
        x->rprod = gcd(gcd(x->r->rprod, x->value), x->l->rprod);
        x->sumz = x->l->sumz + x->z + x->r->sumz;
    }

private:
    T _e;
};

template<typename T, typename F>
struct LCM : Operation<T, F> {
    using S = Node<T, F>;

    LCM(): _e(T(1)) {};

    T e() override {
        return _e;
    }

    void operator() (S* x) override {
        x->prod = lcm(lcm(x->l->prod, x->value), x->r->prod);
        x->rprod = lcm(lcm(x->r->rprod, x->value), x->l->rprod);
        x->sumz = x->l->sumz + x->z + x->r->sumz;
    }

private:
    T _e;
};

template<typename T, typename F>
struct Mapping {
    using S = Node<T, F>;

    Mapping() {};

    virtual F id() = 0;

    void operator() (S* x, const F f) {
        if (f == id()) return;

        map(x, f);
    }

    void composition(F &f, const F s) {
        if (f == id()) {
            f = s;
            return;
        };
        if (s == id()) return;

        com(f, s);
    }

    virtual void map(S* x, const F f) = 0;
    virtual void com(F &f, const F s) = 0;
};

template<typename T, typename F>
struct Add: Mapping<T, F> {
    using S = Node<T, F>;

    Add(): _id(F(0)) {};

    F id() override {
        return _id;
    }

    void map(S* x, const F f) override {
        x->value += f * x->z;
        x->prod += f * x->sumz;
        x->rprod += f * x->sumz;
    }

    void com(F &f, const F s) override {
        f += s;
    }

private:
    F _id;
};

template<typename T, typename F>
struct Multiply: Mapping<T, F> {
    using S = Node<T, F>;

    Multiply(): _id(F(1)) {};

    F id() override {
        return _id;
    }

    void map(S* x, const F f) override {
        x->value *= f;
        x->prod *= f;
        x->rprod *= f;
    }

    void com(F &f, const F s) override {
        f *= s;
    }

private:
    F _id;
};

template<typename T, typename F>
struct Affine: Mapping<T, F> {
    using S = Node<T, F>;

    Affine(): _id(F(1, 0)) {};

    F id() override {
        return _id;
    }

    void map(S* x, const F f) override {
        x->value = f.first * x->value + f.second * x->z;
        x->prod = f.first * x->prod + f.second * x->sumz;
        x->rprod = f.first * x->rprod + f.second * x->sumz;
    }

    void com(F &f, const F s) override {
        f.first *= s.first;
        f.second *= s.first;
        f.second += s.second;
    }

private:
    F _id;
};

template<typename T, typename F>
struct Set: Mapping<T, F> {
    using S = Node<T, F>;

    Set(): _id(numeric_limits<F>::min()) {};

    F id() override {
        return _id;
    }

    void map(S* x, const F f) override {
        x->value = T(f) * x->z;
        x->prod = T(f) * x->sumz;
        x->rprod = T(f) * x->sumz;
    }

    void com(F &f, const F s) override {
        f = s;
    }

private:
    F _id;
};

template<typename T>
struct Set<T, string>: Mapping<T, string> {
    using S = Node<T, string>;
    using F = string;

    Set(): _id(F()) {};

    F id() override {
        return _id;
    }

    void map(S* x, const F f) override {
        x->value = T(f);
        x->prod = T(f);
        x->rprod = T(f);
    }

    void com(F &f, const F s) override {
        f = s;
    }

private:
    F _id;
};

template<typename T, typename F>
struct Flip: Mapping<T, F> {
    using S = Node<T, F>;

    Flip(): _id(F()) {};

    F id() override {
        return _id;
    }

    void map(S* x, const F f) override {
        if (f) {
            x->value ^= 1;
            x->prod ^= 1;
            x->rprod ^= 1;
        }
    }

    void com(F &f, const F s) override {
        f ^= s;
    }

private:
    F _id;
};

template<typename T, 
    typename F,
    template<class, class> class _mapping, 
    template<class, class> class _op>
struct SplayTreeByIdx{
    using S = Node<T, F>;
    using pS = unique_ptr<S>;

    pS pNIL;
    S *NIL = nullptr;
    vector<pS> A;
    S *R;

    _op<T, F> op;
    _mapping<T, F> mapping;

    SplayTreeByIdx() {
        if (!pNIL) {
            pNIL = make_unique<S>();
            NIL = pNIL.get();
            NIL->l = NIL->r = NIL->p = NIL;
            R = NIL;
        }
    }
    
    // 伝播
    void push(S* c){
        if (c->l != NIL) all_apply(c->l, c->lazy);
        if (c->r != NIL) all_apply(c->r, c->lazy);

        if (c->rev){
            swap(c->l, c->r);
            if (c->l != NIL) all_reverse(c->l);
            if (c->r != NIL) all_reverse(c->r);
            c->rev = false;
        }
        c->lazy = mapping.id(); // 伝播済み
    }

    void all_apply(S* c, F f) {
        mapping(c, f);
        mapping.composition(c->lazy, f);
    }

    void all_reverse(S* c) {
        c->rev ^= 1;
        swap(c->prod, c->rprod);
    }

    // 集約
    void update(S* c) {
        op(c); 
    }

    // （便利）
    // p の親が、子として p を参照するので、それを書き換えられるようにする
    // 根の場合に拡張して R の参照を返す。
    S*& parentchild(S* p) {
        if (p->p == NIL) return R;
        if (p->p->l == p) return p->p->l;
        else return p->p->r;
    }

    // 左回転
    void rotL(S* c) {
        S* p = c->p;
        parentchild(p) = c;
        c->p = p->p;
        p->p = c;
        if (c->l != NIL) c->l->p = p; // 子が NIL かもしれない
        p->r = c->l;
        c->l = p;
    }

    // 右回転
    void rotR(S* c) {
        S* p = c->p;
        parentchild(p) = c;
        c->p = p->p;
        p->p = c;
        if (c->r != NIL) c->r->p = p; // 子が NIL かもしれない
        p->l = c->r;
        c->r = p;
    }

    // splay 後、 c は伝播済み
    void splay(S* c) {
        push(c); // ループが回らない時のために
        while (c->p != NIL) {
            S* p = c->p;
            S* pp = p->p;
            // 伝播は親から
            if (pp != NIL) push(pp);
            if (p != NIL) push(p);
            push(c);
            if (p->l == c) {
                if (pp == NIL) rotR(c);
                else if (pp->l == p) { 
                    rotR(p); 
                    rotR(c); 
                }
                else if (pp->r == p) { 
                    rotR(c); 
                    rotL(c); 
                }
            }
            else {
                if (pp == NIL) rotL(c);
                else if (pp->r == p) { 
                    rotL(p); 
                    rotL(c); 
                }
                else if (pp->l == p) { 
                    rotL(c); 
                    rotR(c); 
                }
            }
            // 集約は子から
            if (pp != NIL) update(pp);
            if (p != NIL) update(p);
            update(c);
        }
        update(c); // ループが回らない時のために
    }

    S* kth_element(long long k) {
        S* c = R;

        while (true) {
            push(c);
            if (c->l->sumz == k) break;
            if (c->l->sumz > k) { 
                c = c->l; 
                continue;
            }

            k -= c->l->sumz + 1;
            c = c->r;
        }

        push(c);
        splay(c);
        return c;
    }

    void insert_at(long long k, T x) {
        pS pnx = make_unique<S>(*NIL);
        S* nx = pnx.get();
        nx->z = nx->sumz = 1;
        nx->index = A.size();
        nx->value = nx->prod = nx->rprod = x;
        nx->lazy = mapping.id();
        A.emplace_back(move(pnx));

        if (k == 0) {  // 左端
            nx->r = R;
            if (R != NIL) R->p = nx; // 元々 0 頂点かもしれない
            R = nx;
            update(nx); // 挿入したら集約
            return;
        }

        if (k == R->sumz) { // 右端（左端と同様）
            nx->l = R;
            if (R != NIL) R->p = nx;
            R = nx;
            update(nx);
            return;
        }

        auto p = kth_element(k);
        nx->l = p->l;
        nx->r = p;
        R = nx;
        p->l->p = nx;
        p->p = nx;
        p->l = NIL;
        update(p);  // split/merge の影響
        update(nx); //
    }

    void erase_at(long long k) {
        auto p = kth_element(k);
        if (k == 0) { // 左端
            R = p->r;
            if (R != NIL) R->p = NIL; // 0 頂点になるかもしれない
        }
        else if (k == R->sumz-1) { // 右端
            R = p->l;
            if (R != NIL) R->p = NIL;
        }
        else {
            auto l = p->l;
            auto r = p->r;
            r->p = NIL;   // split
            R = r;        //
            kth_element(0);
            r = R;        // merge
            r->l = l;     //
            l->p = r;     //
            update(r); // split/merge の影響
        }
        swap(p->index, A.back()->index); // index が更新されるよ
        swap(A[p->index], A[A.back()->index]); // 後ろに移動して
        A.pop_back(); // 削除
    }

    S* between(long long l, long long r) {
        if (l == 0 && r == R->sumz) return R; // 全域
        if (l == 0) return kth_element(r)->l; // 左端
        if (r == R->sumz) return kth_element(l - 1)->r; // 右端

        auto rp = kth_element(r);
        auto lp = rp->l;
        R = lp;        // split
        lp->p = NIL;   //
        lp = kth_element(l - 1);
        R = rp;        // merge
        rp->l = lp;    //
        lp->p = rp;    //
        update(rp); // split/merge の影響
        return lp->r;
    }

    void reverse(long long l, long long r) {
        auto c = between(l, r);
        all_reverse(c);
        splay(c);
    }

    void apply(long long l, long long r, F f) {
        auto c = between(l, r);
        all_apply(c, f);
        splay(c);
    }

    T prod(long long l, long long r) {
        return between(l, r)->prod;
    }
};