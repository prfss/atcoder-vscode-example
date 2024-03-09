# 概要

AtCoder の問題の解答コードを VSCode で書く際の設定例です。言語は C++で AtCoder Library 対応です。また Language Server として[clangd](https://clangd.llvm.org/)を使います。

# 準備

## AtCoder Library

リポジトリのルートの直下に https://github.com/atcoder/ac-library をクローンします。

## clangd

1. [clangd 拡張](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd)を VSCode にインストールしてください。
2. clangd のバイナリは拡張が自動で取ってきてくれますが、`clangd.path`を設定することで自前で用意したバイナリを使うこともできます。
# コードを書く
1. リポジトリのルートディレクトリを VSCode で開きます。
2. コンテスト用のディレクトリを作成し、移動します。構成は`practice2`ディレクトリを参考にしてみてください。
3. コードを書きます。
4. コードを書き終わったら<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd>でビルドします。
    |                 ラベル                 | 意味                                        |  出力ファイル  |
    | :------------------------------------: | :------------------------------------------ | :------------: |
    |               g++ build                | ACL なしでビルド                            | `${filename}`  |
    |           g++ build (DEBUG)            | ACL なし + DEBUG シンボル                   |       〃       |
    |     g++ build with AtCoder Library     | ACL ありでビルド                            |       〃       |
    | g++ build with AtCoder Library (DEBUG) | ACL あり + DEBUG シンボル                   |       〃       |
    |     g++ build (ACL, optimization)      | ACL + O2 最適化                             |       〃       |
    |                 Expand                 | ACL を含めたソースコードを出力(expander.py) | `combined.cpp` |

# 参考になりそうなリンク

[Tasks in Visual Studio Code](https://code.visualstudio.com/docs/editor/tasks)
