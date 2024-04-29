# トポロジカルソート
## 概要
グラフ上でトポロジカルソートを行う．

## 使い方
* `TopologicalSort(N)`: サイズ`N`で初期化する．
* `connect(from, to, weight)`: ノード`from`からノード`to`へコスト`weight`の辺を張る．
* `topological_sort()`: トポロジカルソートを行う．計算量$O(|V|+|E|)$
* `get_path(to)`: `topological_sort()`実行後に実行する．ノード`u`までの経路を出力する．経路は`topological_sort()`内の`prev`の更新に基づく．
* `get_longest_path()`: グラフ内の最も経路の長い(コストが大きい)経路を返す．
