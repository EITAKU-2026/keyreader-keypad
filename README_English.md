# KeyReader

**4x4 to 8x8 Key Matrix & Multi-Button Input Control Library**

`KeyReader` is a utility library for Arduino that simplifies key matrix (keypad) input, independent physical buttons (Enter/Clear), and buzzer audio feedback all within a few lines of setup code.

---

## Basic Information
* **Library Name** : KeyReader
* **Description** : 4x4 to 8x8 Key Matrix & Multi-Button Input Control Library
* **Version** : 1.0.0
* **Release Date** : 2026-07-01
* **Author** : EITAKU-2026
* **Verified Hardware** : Arduino Uno R3 (ATmega328P)

> **Development Note**
> This library was designed and conceptualized by the author, and co-developed/brushed up in collaboration with AI.

---

## Features

1. **All-in-One Keypad Management**
   Handles everything from key scanning and automatic input buffering up to the specified digit limit, to full buffer overflow protection automatically on the library side.
2. **Independent Physical Button Support**
   Supports external, independent buttons (Enter/Clear) outside the keypad. It features non-blocking debouncing to completely eliminate accidental multi-clicks or noise.
3. **Automatic 3-Tone Sound Distinction**
   By simply specifying a base frequency in a single line, the library automatically calculates and plays distinct audio feedback: Normal input (user-specified tone), Clear (half the frequency / low tone), and Enter (twice the frequency / high tone).
4. **Full Non-Blocking Design**
   No `delay()` functions are used. Everything is managed via `millis()` timing, achieving ultra-fast scanning thousands of times per second. It will not interrupt other background processes (like motors or LCDs) and ensures no missed keypresses.

---

## Hardware Connection Example

```text
・RowPins (Row)   : Arduino D9, D8, D7, D6  -> To Keypad Rows
・ColPins (Col)   : Arduino D5, D4, D3, D2  -> To Keypad Columns
・EnterButton     : Arduino D11 ------------> Enter Button (Tactile Switch) -> GND
・ClearButton     : Arduino D12 ------------> Clear Button (Tactile Switch) -> GND
・Buzzer          : Arduino D10 ------------> Piezo Buzzer -> GND
```

---

## Package Contents
* **KeyReader.h** : Main library header file
* **README.md** : This documentation file
* **FUNCTION.md** : List of functions provided by this library (Please use this as a reference when using the library).
* **Example of useing.md** : Sample sketch demonstrating usage (Please paste this into the Arduino IDE  to test and verify operations).

---

## Terms of Use / License
* Free to use for personal, educational, and hobby electronic projects.
* **Commercial use is strictly prohibited.**
* **Modification/Modification of the source code is prohibited.**

---
**Created by EITAKU-2026 (2026)**
