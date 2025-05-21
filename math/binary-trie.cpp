#pragma once
#include "../base.cpp"

template <typename T = unsigned long long, int word_size = 64, typename U = long long>
struct BinaryTrie {
    struct Node {
        Node *p;
        Node* ch[2];
        bool v = 0;
        T lazy = 0;
        long long common = 0;
        long long depth = 0;
        U data = U();
    };

    using pN = unique_ptr<Node>;

    Node *NIL = nullptr;
    vector<vector<pN>> A;
    Node *root;

    U a;
    long long word_id;

    BinaryTrie(U a = U()) : A(word_size + 1), a(a), word_id(0) {
        pN pNIL = make_unique<Node>();
        NIL = pNIL.get();
        NIL->p = NIL;
        NIL->ch[0] = NIL;
        NIL->ch[1] = NIL;
        NIL->v = 0;
        NIL->lazy = 0;
        NIL->common = 0;
        NIL->depth = 0;
        NIL->data = a;

        A[0].emplace_back(move(pNIL));
        root = NIL;
    }

    Node* new_node(bool v, long long d) {
        pN pnx = make_unique<Node>();
        Node *nx = pnx.get();
        nx->p = NIL;
        nx->ch[0] = NIL;
        nx->ch[1] = NIL;
        nx->v = v;
        nx->lazy = 0;
        nx->common = 0;
        nx->depth = d;
        nx->data = a;

        A[d].emplace_back(move(pnx));
        return nx;
    }

    void push(Node* node) {
        if (node->depth == word_size) {
            node->lazy = 0;
            return;
        }

        bool v = (node->lazy >> (word_size - 1 - node->depth)) & 1;

        if (v) swap(node->ch[0], node->ch[1]);

        if (node->ch[0] != NIL) {
            node->ch[0]->lazy ^= node->lazy;
            node->ch[0]->v ^= v;
        }
        if (node->ch[1] != NIL) {
            node->ch[1]->lazy ^= node->lazy;
            node->ch[1]->v ^= v;
        }
        node->lazy = 0;
    }

    // 単語の挿入
    Node* insert(T word, long long n = 1, function<void(Node*, T)> f = [](Node* n, T word){}) {
        Node *node = root;
        node->common += n;
        f(node, word);

        rep(i, word_size){
            push(node);
            bool v = (word >> (word_size - 1 - i)) & 1;
            node = push_back(node, v, n);

            f(node, word);
        }

        return node;
    }

    // 単語の挿入
    Node* insert(T word, function<void(Node*, T)> f) {
        return insert(word, 1, f);
    }

    Node* push_back(Node* node, bool v, long long n = 1) {
        assert(node->depth < word_size);

        Node *next_node;
        if (node->ch[v] != NIL) next_node = node->ch[v];
        else {
            next_node = new_node(v, node->depth + 1);
            next_node->p = node;
            node->ch[v] = next_node;
        }

        next_node->common += n;

        return next_node;
    }

    void erase(T word, long long n = 1, function<void(Node*, T)> f = [](Node* n, T word){}) {
        Node* node = search(word);

        if (node->depth != word_size) return;
        n = node->common;

        rep(i, word_size + 1) {
            pop_back(node, n);
            f(node, word);

            if (node == root) break;
            node = node->p;
        }
    }

    vector<long long> erase(T word, function<void(Node*, T)> f) {
        return erase(word, 1, f);
    }

    void pop_back(Node* node, long long n = 1) {
        node->common -= n;

        if (node->common == 0 and node != root) {
            Node* prev_node = node->p;
            prev_node->ch[node->v] = NIL;
        }
    }

    // 単語 word の検索
    // ある単語が Trie 木に含まれるかどうかを判定する
    // wordと先頭が最大一致するノードを返す
    // f: 探索しながら処理したい関数
    Node* search(T word, function<void(Node*)> f = [](Node* n){}) {
        Node* node = root;

        rep(i, word_size + 1) {
            push(node);

            f(node);
            if (i == word_size) break;

            bool v = (word >> (word_size - 1 - i)) & 1;
            Node* next_node;
            if (node->ch[v] != NIL) next_node = node->ch[v];
            else break;
            
            node = next_node;
        }

        return node;
    }

    bool contains(T word) {
        Node* node = search(word);
        return node->depth == word_size and node->common > 0;
    }

    long long count(T word) {
        Node* node = search(word);
        return node->depth == word_size ? node->common : 0;
    }

    void apply_xor(T x) {
        root->lazy ^= x;
    }

    T min_element() {
        T ret = 0;
        Node* node = root;

        rep(i, word_size) {
            push(node);
            if (node->ch[0] != NIL) {
                node = node->ch[0];
            } 
            else {
                ret |= (1ull << (word_size - 1 - i));
                node = node->ch[1];
            }
        }

        return ret;
    }

    T max_element() {
        T ret = 0;
        Node* node = root;

        rep(i, word_size) {
            push(node);
            if (node->ch[1] != NIL) {
                ret |= (1ull << (word_size - 1 - i));
                node = node->ch[1];
            } 
            else {
                node = node->ch[0];
            }
        }

        return ret;
    }

    // k番目に小さい要素を求める (1-indexed)
    T kth_min(long long k) {
        assert(0 < k and k <= root->common);

        T ret = 0;
        Node* node = root;

        rep(i, word_size) {
            push(node);
            if (node->ch[0] != NIL and node->ch[0]->common >= k) {
                node = node->ch[0];
            } 
            else {
                if (node->ch[0] != NIL) k -= node->ch[0]->common;
                ret |= (1ull << (word_size - 1 - i));
                node = node->ch[1];
            }
        }

        return ret;
    }

    // k番目に大きい要素を求める (1-indexed)
    T kth_max(long long k) {
        return kth_min_element(root->common - k + 1);
    }

    long long count_less_than(T word) {
        long long ret = 0;
        
        auto f = [&](Node* node) {
            if (node->depth == word_size) return;
            bool v = (word >> (word_size - 1 - node->depth)) & 1;
            if (v & (node->ch[0] != NIL)) ret += node->ch[0]->common;
        };

        search(word, f);

        return ret;
    }

    long long count_less_than_or_equal(T word) {
        return count_less_than(word + 1);
    }

    long long count_greater_than(T word) {
        return root->common - count_less_than_or_equal(word);
    }

    long long count_greater_than_or_equal(T word) {
        return root->common - count_less_than(word);
    }

    T find_less_than(T word) {
        long long cnt = count_less_than(word);
        if (cnt == 0) return numeric_limits<T>::max();
        return kth_min(cnt);
    }

    T find_less_than_or_equal(T word) {
        long long cnt = count_less_than_or_equal(word);
        if (cnt == 0) return numeric_limits<T>::max();
        return kth_min(cnt);
    }

    T find_greater_than(T word) {
        long long cnt = count_less_than_or_equal(word);
        if (cnt == root->common) return numeric_limits<T>::max();
        return kth_min(cnt + 1);
    }

    T find_greater_than_or_equal(T word) {
        long long cnt = count_less_than(word);
        if (cnt == root->common) return numeric_limits<T>::max();
        return kth_min(cnt + 1);
    }

    // 挿入した単語の数
    long long count() const {
        return root->common;
    }

    // Trie木のノード数
    long long size() const {
        long long ret = 0;
        rep(i, word_size) ret += A[i].size();
        return ret;
    }
};