# かっこいいうんこキーボード

この文章は技術書典7で頒布した「かっこいいうんこキーボード」の取扱説明書です。

## この文章で知れること

- 「かっこいいうんこキーボード」の組み立て方
- 「かっこいいうんこキーボード」のファームウェアのカスタマイズ方法

## 組み立て方

(STAB)

## ファームウェアのカスタマイズ方法

### 必要なもの

- [PlatformIO](https://platformio.org/)
- Windowsの場合は[Digisparkのドライバー](https://github.com/digistump/DigistumpArduino/releases/download/1.6.7/Digistump.Drivers.zip)のインストールが必要です
  - また、`make`および`patch`が使える環境が必要です

### ファームウェアの書き込み手順

#### 1. このリポジトリのダウンロード

`git clone`やzipファイルのdownload linkからこのリポジトリのソースコードをダウンロードします。

#### 2. 書き込み環境のセットアップ

`make`コマンドを実行できるCLI環境で1でダウンロードし、展開したディレクトリに移動します。そして、そのディレクトリで以下のコマンドを実行します。

```console
$ make init
```

途中にコンパイルエラーが出ますが、その後にコンパイルエラーを解消するためのパッチが自動で適用されます。

#### 3. ファームウェアの書き込み

以下のコマンドで、「かっこいいうんこキーボード」へのファームウェアの書き込みが実行されます。

```console
$ make upload
```

`> Please plug in the device ...` というメッセージが表示された、「かっこいいうんこキーボード」をUSBケーブルで接続してください。もし、接続したまま実行した場合は、一度抜いてからもう一度挿してください。

`>> Micronucleus done. Thank you!` というメッセージが表示されたら成功です。

### キーのカスタマイズ

キー配置の情報は、`src/Keyboard.ino`に記述されています。

それぞれのキーを`A`, `B`, `C`, `D`に変更する場合は、

```diff
--- a/src/Keyboard.ino
+++ b/src/Keyboard.ino
@@ -8,7 +8,7 @@ WS2812 LED(NEOPIXELS_NUM);
 cRGB value;

 uint8_t keys[] = {9, 8, 7, 3};
-byte keymaps[] = {KEY_U, KEY_N, KEY_K, KEY_O};
+byte keymaps[] = {KEY_A, KEY_B, KEY_C, KEY_D};

 void setup() {
   LED.setOutput(NEOPIXEL_PIN);
```

というように変更し、保存した後に`make upload`を実行して書き込みます。
