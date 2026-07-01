# 使用例

```cpp
#include <KeyReader.h> // <> で囲んで呼び出してください。

KeyReader reader;    // ライブラリの実体（オブジェクト）を作成します。
String keyPassword;  // 入力された文字列を受け取るためのユーザー変数です。名前は任意に決められます。

// キー配置の定義をしてください。
char myMap[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'F','0','E','D'}
};

void setup() {
  Serial.begin(9600);

  // 1. 各種カスタマイズ設定
  reader.row(4);
  reader.col(4);
  reader.passLong(20);
  reader.buzzSound(10, 1000); // 10番ピン、1000Hz
  
  int rPins[] = {9, 8, 7, 6};
  reader.setRowPins(rPins);
  
  int cPins[] = {5, 4, 3, 2};
  reader.setColPins(cPins);
  
  reader.enterButton(11);
  reader.deleteButton(12);
  reader.arrange(myMap);

  // 2. 最後に必ず初期化を呼んでください。pinMode設定などが自動実行されます。
  reader.begin();
  
  Serial.println(F("KeyReader Ready."));
}

void loop() {
  // 3. ループ内で常に呼び出す
  // 決定ボタンが押されて「確定」した瞬間だけ、if文の中身が実行されます。
  if (reader.read(keyPassword)) {
    Serial.println();
    Serial.print(F("確定パスワード: "));
    Serial.println(keyPassword); // ユーザーが定義した変数に入力した文字列を代入して表示します。
  }
}
