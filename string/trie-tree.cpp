#pragma once
#include "../base.cpp"


/* Trie 木： 文字の種類(char_size)、int型で0に対応する文字(base)
    insert(word): 単語 word を Trie 木に挿入する
    search(word): 単語 word が Trie 木にあるか判定する
    start_with(prefix):  prefix が一致する単語が Trie 木にあるか判定する
    count(): 挿入した単語の数を返す
    size(): Trie 木の頂点数を返す
    計算量：insert, search ともに O(M)（Mは単語の長さ）
*/
template <int char_size = 26, int base = 'a'>
struct Trie {
    struct Node {            // 頂点を表す構造体
        vector<long long> next;    // 子の頂点番号を格納。存在しなければ-1
        vector<long long> accept;  // 末端がこの頂点になる単語の word_id を保存
        int c;               // base からの間隔をint型で表現したもの
        long long common;          // いくつの単語がこの頂点を共有しているか
        Node(long long c_) : c(c_), common(0) {
            next.assign(char_size, -1);
        }
    };

    vector<Node> nodes;  // trie 木本体
    long long root;

    Trie() : root(0) {
        nodes.push_back(Node(root));
    }

    // 単語の挿入
    void insert(const string &word, long long word_id) {
        ll node_id = 0;
        rep(i, word.size()){
            int c = (int)(word[i] - base);
            long long &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ追加
                next_id = nodes.size();
                nodes.push_back(Node(c));
            }
            ++nodes[node_id].common;
            node_id = next_id;
        }
        ++nodes[node_id].common;
        nodes[node_id].accept.push_back(word_id);
    }
    
    void insert(const string &word) {
        insert(word, nodes[0].common);
    }

    // 単語の検索
    // prefix = false　ならば、完全一致の検索
    // prefix = true ならば、prefix の検索
    bool search(const string &word, bool prefix = false) {
        long long node_id = 0;
        rep(i, word.size()) {
            int c = (int)(word[i] - base);
            long long &next_id = nodes[node_id].next[c];

            if (next_id == -1) return false;   // 次の頂点が存在しなければ終了
            node_id = next_id;
        }
        return (prefix) ? true : nodes[node_id].accept.size() > 0;
    }

    // prefix を持つ単語が存在するかの検索
    bool start_with(const string &prefix) {
        return search(prefix, true);
    }

    // 挿入した単語の数
    long long count() const {
        return (nodes[0].common);
    }

    // Trie木のノード数
    long long size() const {
        return nodes.size();
    }
};
