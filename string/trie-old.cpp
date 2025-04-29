#pragma once
#include "../base.cpp"

struct Node {
    long long id;
    int c;               // base からの間隔をint型で表現したもの
    long long common;          // いくつの単語がこの頂点を共有しているか
    long long depth;           // この頂点の深さ
    long long min_l, max_l;      // この頂点を根とする部分木に含まれる単語の最小長と最大長

    Node(long long i, long long c_, long long d): id(i), c(c_), common(0), depth(d), min_l(inf64), max_l(-1) {}
};

struct Trie {
    vector<Node> nodes;  // trie 木本体
    vector<unordered_map<int, long long>> children;     // 子の頂点番号を格納。存在しなければ-1
    vector<vector<long long>> accept;   // 末端がこの頂点になる単語の word_id を保存
    long long root;
    long long word_id;

    Trie() : root(0), word_id(0) {
        nodes.push_back(Node(0, root, 0));
        children.push_back(unordered_map<int, long long>());
        accept.push_back(vector<long long>());
    }

    // 単語の挿入
    void insert(const string &word) {
        long long node_id = 0;
        rep(i, word.size()){
            ++nodes[node_id].common;
            chmax(nodes[node_id].max_l, (long long)word.size());
            chmin(nodes[node_id].min_l, (long long)word.size());

            char c = word[i];
            long long next_id = children[node_id].contains(c) ? children[node_id][c] : -1;

            if (next_id == -1) {  // 次の頂点が存在しなければ追加
                next_id = nodes.size();
                nodes.push_back(Node(next_id, c, i + 1));
                children.push_back(unordered_map<int, long long>());
                accept.push_back(vector<long long>());
                children[node_id][c] = next_id;
            }
            
            node_id = next_id;
        }
        ++nodes[node_id].common;
        chmax(nodes[node_id].max_l, (long long)word.size());
        chmin(nodes[node_id].min_l, (long long)word.size());
        accept[node_id].push_back(word_id++);
    }

    // erase_with_prefix:= 部分一致する単語も全て消す
    void erase(const string &word, bool erase_all, bool with_prefix) {
        vector<long long> node_ids;
        long long node_id = 0;
        node_ids.push_back(node_id);

        rep(i, word.size()) {
            int c = word[i];
            long long next_id = children[node_id][c];
            if (next_id == -1) return;
            node_id = next_id;
            node_ids.push_back(node_id);
        }

        if (!with_prefix and accept[node_id].size() == 0) return;

        ll cnt = 1;
        if (erase_all) cnt = accept[node_id].size();
        if (with_prefix) cnt = nodes[node_id].common;

        if (erase_all or with_prefix) accept[node_id].clear();
        else accept[node_id].pop_back();

        repd(i, node_ids.size()) {
            node_id = node_ids[i];
            nodes[node_id].common -= cnt;

            if (nodes[node_id].common == 0) {
                if (i > 0) {
                    if (i == node_ids.size() - 1) children[node_id].clear();
                    children[node_ids[i - 1]].erase(nodes[node_id].c);
                }
                else {
                    nodes[node_id].max_l = -1;
                    nodes[node_id].min_l = inf64;
                }
                continue;
            }

            nodes[node_id].max_l = -1;
            nodes[node_id].min_l = inf64;

            if (!accept[node_id].empty()) {
                nodes[node_id].max_l = 0;
                nodes[node_id].min_l = 0;
            }

            fore(c, children[node_id]) {
                chmax(nodes[node_id].max_l, nodes[c.second].max_l);
                chmin(nodes[node_id].min_l, nodes[c.second].min_l);
            }
        }
    }

    void erase(const string& word) {
        erase(word, false, false);
    }

    void erase_all(const string& word) {
        erase(word, true, false);
    }

    void erase_with_prefix(const string& word) {
        erase(word, true, true);
    }

    // 単語 word の検索
    // ある単語が Trie 木に含まれるかどうかを判定する
    // wordと先頭が最大一致するノードを返す
    // f: 探索しながら処理したい関数
    Node search(const string &word, function<void(Node)> f = [](Node n) {}) {
        long long node_id = 0;
        rep(i, word.size()) {
            char c = word[i];
            long long next_id = children[node_id].contains(c) ? children[node_id][c] : -1;

            f(nodes[node_id]);

            if (next_id == -1) return nodes[node_id];   // 次の頂点が存在しなければ終了
            node_id = next_id;
        }

        f(nodes[node_id]);
        return nodes[node_id];
    }

    bool contains(const string &word) {
        Node node = search(word);
        return node.depth == word.size() and !accept[node.id].empty();
    }

    // prefix を持つ単語が存在するかの検索
    bool contains_with_prefix(const string &prefix) {
        return search(prefix).depth == prefix.size();
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