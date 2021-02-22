# 概要

AtCoder の解答コードを VSCode で書く際の設定例です。言語は C++で AtCoder Library 対応です。また LS として[clangd](https://clangd.llvm.org/)を使います。

# 準備

## AtCoder Library

リポジトリのルートの直下に https://github.com/atcoder/ac-library をクローンします。

## clangd

1. [clangd 拡張](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd)を VSCode にインストールしてください。
2. clangd のバイナリは拡張が自動で取ってきてくれますが、`clangd.path`を設定することで自前で用意したバイナリを使うこともできます。

# コードを書く

ディレクトリ構成は`practice2`を参考にしてみてください。

1. リポジトリのルートディレクトリを VSCode で開きます。
2. コンテスト用のディレクトリを作成し、移動します。
3. ターミナルを開き`code solution.cpp`のようにしてコードを書きます。
4. 書き終わったら<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd>でビルドします。

    |             ラベル             | 意味                                        | 出力ファイル   |
    | :----------------------------: | :------------------------------------------ | -------------- |
    |           g++ build            | ACL なしでビルド                            | `${filename}`  |
    | g++ build with AtCoder Library | ACL ありでビルド                            | `${filename}`  |
    |             Expand             | ACL を含めたソースコードを出力(expander.py) | `combined.cpp` |

# 参考になりそうなリンク

[Tasks in Visual Studio Code](https://code.visualstudio.com/docs/editor/tasks)
