# Grid BFS
## 概要
グリッド上でBFSを行う．

## 使い方
* `GridBFS(n)`: サイズ`n`$\times$`n`で初期化する．
* `GridBFS(h, w)`: サイズ`h`$\times$`w`で初期化する．
* `GridBFS(vs)`: 二次元配列`vs`をもとに初期化する．
* `input()`: `h`行の文字列を標準入力から受け取り`field`を設定する．"s"または"S"がある位置を`start`，"g", "G", "t", "T"のいずれかがある位置を`goal`に格納する．
* `bfs_all()`: 全ての座標$(i, j)$に対して`seen(i, j) = true`となるまで`bfs({i, j})`を実行する．
* `count_cc()`: `bfs_all()`実行後に実行する．連結成分の個数を返す． 
* `bfs(now)`: 座標`now`からbfsを実行する．計算量$O(HW)$
* `bfs01(now)`: 座標`now`から01bfsを実行する．計算量$O(HW)$
* `can_reach_goal()`: `bfs(start)`実行後に実行する．座標`goal`へ到達可能かを判定する．
* `can_reach(to)`: `bfs(start)`実行後に実行する．座標`to`へ到達可能かを判定する．
* `get_dist(to)`: `bfs(start)`実行後に実行する．座標`to`までの距離を返す．
* `get_path(from, to)`: 座標`from`から座標`to`までの経路を格納した配列を返す．到達できない場合，空配列を返す．
* `get_path_to_goal(to)`: `bfs(start)`実行後に実行する．座標`start`から座標`goal`までの経路を格納した配列を返す．到達できない場合，空配列を返す．
* `get_path(to)`: `bfs(start)`実行後に実行する．座標`start`から座標`to`までの経路を格納した配列を返す．到達できない場合，空配列を返す．
* `get_char_path_to_goal()`: `bfs(start)`実行後に実行する．座標`start`から座標`goal`までの経路を`UDRL`で格納した配列を返す．到達できない場合，空配列を返す．
* `get_char_path(to)`: `bfs(start)`実行後に実行する．座標`start`から座標`to`までの経路を`UDRL`で格納した配列を返す．到達できない場合，空配列を返す．