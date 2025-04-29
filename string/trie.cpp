#pragma once
#include "../base.cpp"

template <typename T = long long>
struct Trie {
    struct Node {
        long long id = 0;
        char c = 0;
        long long common = 0;
        long long depth = 0;
        T data = T();
        vector<long long> accepts;
        Node *p = 0;
        unordered_map<char, Node*> ch;
    };

    using pN = unique_ptr<Node>;

    pN pNIL;
    Node *NIL = nullptr;
    vector<pN> A;
    Node *root;

    T a;
    long long node_id, word_id;
    vector<long long> erased_nodes;

    Trie(T a = T()) : a(a), node_id(0), word_id(0) {
        pNIL = make_unique<Node>();
        NIL = pNIL.get();
        NIL->p = NIL;
        NIL->id = node_id++;
        NIL->c = 0;
        NIL->common = 0;
        NIL->depth = 0;
        NIL->data = a;
        NIL->accepts = vector<long long>();
        NIL->ch = unordered_map<char, Node*>();
        root = NIL;
    }

    Node* new_node(char c, long long d) {
        pN pnx = make_unique<Node>();
        Node *nx = pnx.get();
        nx->p = NIL;
        nx->id = node_id++;
        nx->c = c;
        nx->common = 0;
        nx->depth = d;
        nx->data = a;
        nx->accepts = vector<long long>();
        nx->ch = unordered_map<char, Node*>();

        A.emplace_back(move(pnx));
        return nx;
	}

    // 単語の挿入
    Node* insert(const string& word, long long n = 1, function<void(Node*, const string&)> f = [](Node* n, const string& word){}) {
        Node *node = root;

        rep(i, word.size() + 1){
            node->common += n;
            if (i == word.size()) {
                rep(j, n) node->accepts.push_back(word_id++);
            }
            
            f(node, word);

            if (i == word.size()) break;

            char c = word[i];
            Node *next_node;
            if (node->ch.contains(c)) next_node = node->ch[c];
            else {
                next_node = new_node(c, node->depth + 1);
                next_node->p = node;
                node->ch[c] = next_node;
            }

            node = next_node;
        }

        return node;
    }

    // 単語の挿入
    Node* insert(const string& word, function<void(Node*, const string&)> f) {
        return insert(word, 1, f);
    }

    vector<long long> erase(const string& word, long long n = 1, function<void(Node*, const string&)> f = [](Node* n, const string& word){}) {
        Node* node = search(word);

        if (node->depth != word.size()) return {};
        
        vector<long long> ret;
        rep(i, n) {
            if (node->accepts.empty()) break;
            ret.push_back(node->accepts.back());
            node->accepts.pop_back();
        }

        while (true) {
            node->common -= ret.size();
            f(node, word);
            if (node == root) break;

            Node* next_node = node->p;
            if (node->common == 0) {
                next_node->ch.erase(node->c);
                erased_nodes.push_back(node->id);
            }
            node = next_node;
        }

        return ret;
    }

    vector<long long> erase(const string& word, function<void(Node*, const string&)> f) {
        return erase(word, 1, f);
    }

    void erase_with_prefix(const string& prefix, function<void(Node*, const string&)> f = [](Node* n, const string& prefix){}) {
        Node* node = search(prefix);

        if (node->depth != prefix.size()) return;
        
        long long n = node->common; 

        repd(i, prefix.size() + 1) {
            node->common -= n;
            f(node, prefix);
            if (node == root) break;

            Node* next_node = node->p;
            if (node->common == 0) {
                next_node->ch.erase(node->c);
                erased_nodes.push_back(node->id);
            }
            node = next_node;
        }
    }

    // 単語 word の検索
    // ある単語が Trie 木に含まれるかどうかを判定する
    // wordと先頭が最大一致するノードを返す
    // f: 探索しながら処理したい関数
    Node* search(const string& word, function<void(Node*)> f = [](Node* n){}) {
        Node* node = root;

        rep(i, word.size() + 1) {
            f(node);
            if (i == word.size()) break;

            char c = word[i];
            Node* next_node;
            if (node->ch.contains(c)) next_node = node->ch[c];
            else break;
            
            node = next_node;
        }

        return node;
    }

    bool contains(const string& word) {
        Node* node = search(word);
        return node->depth == word.size() and !node->accepts.empty();
    }

    // prefix を持つ単語が存在するかの検索
    bool contains_with_prefix(const string& prefix) {
        Node* node = search(prefix);
        return node->depth == prefix.size();
    }

    long long count(const string& word) {
        Node* node = search(word);
        return (node->depth == word.size() ? node->accepts.size() : 0);
    }

    long long count_with_prefix(const string& prefix) {
        Node* node= search(prefix);
        return (node->depth == prefix.size() ? node->common : 0);
    }

    // 挿入した単語の数
    long long count() const {
        return root->common;
    }

    // Trie木のノード数
    long long size() const {
        return A.size() - erased_nodes.size();
    }
};
