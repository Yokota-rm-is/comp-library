# ワーシャルフロイド法
## 概要
グラフ上でワーシャルフロイド法を行う．

## 使い方
* `WarshallFloyd(N, directed)`: サイズ`N`で初期化する．有向辺，無向辺を`directed`で設定する．
* `WarshallFloyd(A)`: 隣接行列`A`で初期化する．
* `connect(from, to, weight)`: ノード`from`からノード`to`へコスト`weight`の辺を張る．`directed = false`の時，逆向きの辺を同時に張る．
* `warshall_floyd()`: ワーシャルフロイド法を実行する．計算量$O(|V|^3)$
* `get_dist(from, to)`: `warshall_floyd()`実行後に実行する．ノード`from`からノード`to`へのコストを返す．到達不能な場合，`inf64`を返す．
* `dist_from(from)`: `warshall_floyd()`実行後に実行する．ノード`from`から全てのノードへのコストを格納した配列を返す．到達不能なノードのコストは`inf64`となる．
* `get_path(from, to)`: `warshall_floyd()`実行後に実行する．ノード`from`からノード`to`までの経路を格納した配列を返す．到達できない場合，空配列を返す．
* `has_negative_cycle()`: `warshall_floyd()`実行後に実行する．負の閉路の有無を判定する．
