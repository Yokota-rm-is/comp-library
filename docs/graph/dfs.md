# DFS
## 概要
グラフ上でDFSを行う．

## 使い方
* `DFS(N, directed)`: サイズ`N`で初期化する．有向辺，無向辺を`directed`で設定する．
* `connect(from, to)`: ノード`from`からノード`to`へ辺を張る．`directed = false`の時，逆向きの辺を同時に張る．
* `dfs_all()`: 全てのノード`i`に対して`seen[i] = true`となるまで`dfs(i)`を実行する．
* `dfs(start)`: ノード`start`からdfsを実行する．計算量$O(|V|+|E|)$
* `can_reach(to)`: `dfs(start)`実行後に実行する．ノード`to`へ到達可能かを判定する．
* `is_bipartite()`: 二部グラフかどうかを判定する．