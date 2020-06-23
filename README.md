
# cairo_picker

CairoのコンテキストをWindow上に描画するためだけの、ちょうどいいコンパクトさのGtkmmラッパーライブラリです。
___

## 機能リスト

#### C_canvas
 - void set_default_size(int, int)          : ウインドウの初期サイズの変更
 - void set_timeout(int)                    : ループの実装と更新頻度の設定
 - void run(void(*)(Cairo_cont))            : ループの実行