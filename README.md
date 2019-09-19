# nettrs
ネットワーク対戦型テトリスを作りたい

## ユーザ向け
### 起動方法
`build/Tetris`を実行してください。

### 基本操作

|コマンド|動作          |
|:-------|:-------------|
|`A` `←`|移動          |
|`D` `→`|移動          |
|`S` `↓`|ソフトドロップ|
|`W` `↑`|ハードドロップ|
|`Z`     |左回転        |
|`X`     |右回転        |

## 開発者向け
### 必要パッケージ
- cmake
- SDL2
- SDL2_image

### ビルド方法(DEBUGモード)
DEBUGモードは、デバックシンボルやデバッグメッセージを出力させることができる。
1. `mkdir build`
2. `cd ./build`
3. `cmake -DCMAKE_BUILD_TYPE=Debug ../`
4. `make`

開発段階で多様するため、上記動作するスクリプト`scripts/setup.sh`を用意した。

### ビルド方法(RELEASEモード)
RELEASEモードは、製品を配布するときに使用する。
1. `mkdir build`
2. `cd ./build`
3. `cmake -DCMAKE_BUILD_TYPE=Release ../`
4. `make`

### 実行方法
`build`ディレクトリ以下に生成されたファイル`Tetris`を実行する。
