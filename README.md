
# cairo_picker

Cairoのコンテキストをウインドウ上に描画してアプリケーションを作成するための、最小限の機能を提供するライブラリ。
Gtkmmベース。

### ビルド

Gtkmmを使うため、`pkg-config`を使ってパッケージを読み込む必要がある。

例

```
g++ -o test test.cpp `pkg-config --libs --cflags gtkmm-3.0`
```

___

## サポート機能

 - キー入力
 - PNG入出力
 - マウス入力
