# BFS
## 概要
グラフ上でBFSを行う．

## 使い方
* `BFS(N, directed)`: サイズ`N`で初期化する．有向辺，無向辺を`directed`で設定する．
* `connect(from, to)`: ノード`from`からノード`to`へ辺を張る．`directed = false`の時，逆向きの辺を同時に張る．
* `bfs_all()`: 全てのノード`i`に対して`seen[i] = true`となるまで`bfs(i)`を実行する．
* `bfs(start)`: ノード`start`からbfsを実行する．計算量$O(|V|+|E|)$
* `count_cc()`: `bfs_all()`実行後に実行する．連結成分の個数を返す．  
* `find_diameter()`: 
* `reach(to)`: `bfs(start)`実行後に実行する．ノード`to`へ到達可能かを判定する．
* `path_to(to)`: `bfs(start)`実行後に実行する．ノード`start`からノード`to`までの経路を格納した配列を返す．到達できない場合，空配列を返す．
