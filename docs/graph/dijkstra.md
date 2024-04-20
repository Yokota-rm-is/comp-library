# ダイクストラ法
## 概要
グラフ上でダイクストラ法を行う．

## 使い方
* `Dijkstra(N, directed)`: サイズ`N`で初期化する．有向辺，無向辺を`directed`で設定する．
* `connect(from, to, weight)`: ノード`from`からノード`to`へコスト`weight`の辺を張る．`directed = false`の時，逆向きの辺を同時に張る．
* `dijkstra(start)`: ノード`start`からダイクストラ法を実行する．計算量$O(E\log{V})$
* `reach(to)`: `dijkstra(start)`実行後に実行する．ノード`to`へ到達可能か判定する．
* `path_to(to)`: `dijkstra(start)`実行後に実行する．ノード`start`からノード`to`までの経路を格納した配列を返す．到達できない場合，空配列を返す．
