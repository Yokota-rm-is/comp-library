# TreeDP
## 概要
木DP，全方位木dpを行う．

## 使い方
* `TreeDP(N)`: サイズ`N`で初期化する．
* `id()`: 【要設定】単位元
* `merge(x, y)`: 【要設定】マージする関数
* `put_edge(x, edge)`: 【要設定】辺を追加する関数
* `put_vertex(x, v)`: 【要設定】頂点を追加する関数
* `connect(from, to, weight)`: ノード`from`からノード`to`へコスト`weight`の辺を張る．
* `build(root)`: ノード`root`を根とする木DPを行い，ノード`root`を根とした場合の値を返す．計算量$O(N)$ (`merge`, `put_edge`, `put_vertex`が$O(1)$である場合)
* `reroot()`: `build(root)`実行後に実行する．全方位木DPを行い，各ノードを根とした場合の値の配列を返す．計算量$O(N)$ (`merge`, `put_edge`, `put_vertex`が$O(1)$である場合)