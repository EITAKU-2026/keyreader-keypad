# Usage Example

```cpp
#include <KeyReader.h> // Include the library using angled brackets.

KeyReader reader;    // Create an instance (object) of the library.
String keyPassword;  // User-defined variable to receive the entered string. You can name it freely.

// Define the keypad layout.
char myMap[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'F','0','E','D'}
};

void setup() {
  Serial.begin(9600);

  // 1. Custom settings configurations
  reader.row(4);
  reader.col(4);
  reader.passLong(20);
  reader.buzzSound(10, 1000); // Pin 10, 1000Hz
  
  int rPins[] = {9, 8, 7, 6};
  reader.setRowPins(rPins);
  
  int cPins[] = {5, 4, 3, 2};
  reader.setColPins(cPins);
  
  reader.enterButton(11);
  reader.deleteButton(12);
  reader.arrange(myMap);

  // 2. Must call the initialization at the end of setup(). 
  //    This automatically executes pinMode settings and initial outputs.
  reader.begin();
  
  Serial.println(F("KeyReader Ready."));
}

void loop() {
  // 3. Continuously call inside the loop.
  //    The inside of the if statement executes ONLY at the exact moment the Enter button is pressed to "confirm".
  if (reader.read(keyPassword)) {
    Serial.println();
    Serial.print(F("Confirmed Password: "));
    Serial.println(keyPassword); // Assigns the entered text to the user-defined variable and prints it.
  }
}
```
