#ifndef KEY_READER_H
#define KEY_READER_H

#include <Arduino.h>

class KeyReader {
private:
  int rowNum = 4;
  int colNum = 4;
  int passBufferLong = 20;
  int buzzPin = 10;
  unsigned int buzzSoundFreq = 1000;
  
  int rowPins[8] = {9, 8, 7, 6, 0, 0, 0, 0}; 
  int colPins[8] = {5, 4, 3, 2, 0, 0, 0, 0};
  
  int enterPin = 11;
  int clearPin = 12;
  
  char KeyMap[8][8] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'F','0','E','D'}
  };

  char lastKey = '\0';
  char currentKey = '\0';
  unsigned long lastTime = 0;
  const unsigned long debounceTime = 30; 

  unsigned long buzzerStartTime = 0;
  bool buzzerOn = false;
  const unsigned long buzzerDuration = 50; 

  unsigned long lastButtonTime = 0;
  unsigned long lastClearButtonTime = 0;
  const unsigned long buttonDebounceTime = 200; 

  char buffer[65] = ""; 
  int bufferIndex = 0;

  bool lastButtonState = HIGH;
  bool lastClearButtonState = HIGH;

public:
  void row(int num) { rowNum = num; }
  void col(int num) { colNum = num; }
  void passLong(int len) { passBufferLong = len; }
  void buzzSound(int pin, unsigned int freq) { buzzPin = pin; buzzSoundFreq = freq; }
  
  void enterButton(int pin) { enterPin = pin; }
  void deleteButton(int pin) { clearPin = pin; }

  void setRowPins(const int pins[]) { for(int i=0; i<rowNum; i++) rowPins[i] = pins[i]; }
  void setColPins(const int pins[]) { for(int i=0; i<colNum; i++) colPins[i] = pins[i]; }
  
  template <size_t R, size_t C>
  void arrange(const char (&map)[R][C]) {
    for(size_t r=0; r<R && r<8; r++) {
      for(size_t c=0; c<C && c<8; c++) {
        KeyMap[r][c] = map[r][c];
      }
    }
  }

  void begin() {
    pinMode(buzzPin, OUTPUT);
    pinMode(enterPin, INPUT_PULLUP);
    pinMode(clearPin, INPUT_PULLUP);
    for(int i = 0; i < rowNum; i++) pinMode(rowPins[i], INPUT_PULLUP);
    for(int i = 0; i < colNum; i++) {
      pinMode(colPins[i], OUTPUT);
      digitalWrite(colPins[i], HIGH);
    }
  }

  bool read(String &outputTarget) {
    currentKey = '\0';

    for(int c = 0; c < colNum; c++) {
      digitalWrite(colPins[c], LOW);
      for(int r = 0; r < rowNum; r++) {
        if(digitalRead(rowPins[r]) == LOW) {
          currentKey = KeyMap[r][c];
        }
      }
      digitalWrite(colPins[c], HIGH);
    }

    if(currentKey != lastKey) {
      if(millis() - lastTime > debounceTime) {
        lastTime = millis();
        if(currentKey != '\0') {
          if(bufferIndex < passBufferLong) {
            buffer[bufferIndex] = currentKey;
            bufferIndex++;
            buffer[bufferIndex] = '\0';
          }
          Serial.print(F("*"));
          tone(buzzPin, buzzSoundFreq);
          buzzerStartTime = millis();
          buzzerOn = true;
        }
        lastKey = currentKey;
      }
    }

    bool isConfirmed = false;

    bool buttonState = digitalRead(enterPin);
    if(buttonState == LOW && lastButtonState == HIGH) {
      if(millis() - lastButtonTime > buttonDebounceTime) {
        lastButtonTime = millis();
        if(bufferIndex > 0) {
          outputTarget = String(buffer); 
          bufferIndex = 0;
          buffer[0] = '\0';
          isConfirmed = true; 

          // 🌟追加：決定ボタンを押したときに2倍の周波数（高い音）で鳴らす
          tone(buzzPin, buzzSoundFreq * 2);
          buzzerStartTime = millis();
          buzzerOn = true;
        }
      }
    }
    lastButtonState = buttonState;

    bool clearButtonState = digitalRead(clearPin);
    if(clearButtonState == LOW && lastClearButtonState == HIGH) {
      if(millis() - lastClearButtonTime > buttonDebounceTime) {
        lastClearButtonTime = millis();
        if(bufferIndex > 0) {
          bufferIndex = 0;
          buffer[0] = '\0';
          Serial.println(F("\n[CLEAR]"));
          tone(buzzPin, buzzSoundFreq / 2);
          buzzerStartTime = millis();
          buzzerOn = true;
        }
      }
    }
    lastClearButtonState = clearButtonState;

    if(buzzerOn && millis() - buzzerStartTime > buzzerDuration) {
      noTone(buzzPin);
      buzzerOn = false;
    }

    return isConfirmed; 
  }
};

#endif
