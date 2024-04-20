# TreeBFS
## 概要
木上でBFSを行う．

## 使い方
* `Tree(N)`: サイズ`N`で初期化する．
* `connect(from, to, weight)`: ノード`from`からノード`to`へコスト`weight`の辺を張る．
* `bfs(start)`: ノード`start`からbfsを実行する．計算量$O(|V|+|E|)$
* `find_diameter()`: 木の直径を返す．
* `lca_init(root)`: ノード`root`を根とするLCAの事前計算を行う．ダブリングを使用．計算量$O(N\log{N})$
* `lca(u, v)`: `lca_init(root)`実行後に実行する．ノード`u`とノード`v`の最小共通祖先を返す． 計算量$O(\log{N})$
* `get_dist(u, v)`: `lca_init(root)`実行後に実行する．ノード`u`とノード`v`の距離を返す．
* `is_on_path(u, v, a)`: `lca_init(root)`実行後に実行する．ノード`u`とノード`v`の経路上にノード`a`が存在するか判定する． 
* 