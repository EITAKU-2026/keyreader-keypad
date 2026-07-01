================================================================================
■ KeyReader Library Function List (Reference)
================================================================================

[1. Setup Functions (Call inside setup() before begin())]

● reader.row(num);
  - Argument: int (Number of rows)
  - Description: Sets the number of rows for the keypad (Default is 4).

● reader.col(num);
  - Argument: int (Number of columns)
  - Description: Sets the number of columns for the keypad (Default is 4).

● reader.passLong(len);
  - Argument: int (Maximum length)
  - Description: Specifies the maximum number of digits allowed for input. 
                 Any input exceeding this limit will be ignored.

● reader.buzzSound(pin, freq);
  - Arguments: int (Pin number), unsigned int (Frequency [Hz])
  - Description: Sets the connected pin for the buzzer and the tone pitch for normal input.
                 *The frequency automatically becomes half (lower tone) when clearing the input.

● reader.setRowPins(pins);
  - Argument: int array[]
  - Description: Passes the Arduino pin numbers connected to the keypad rows as an array.

● reader.setColPins(pins);
  - Argument: int array[]
  - Description: Passes the Arduino pin numbers connected to the keypad columns as an array.

● reader.enterButton(pin);
  - Argument: int (Pin number)
  - Description: Sets the pin number for the Enter (confirm) button.

● reader.deleteButton(pin);
  - Argument: int (Pin number)
  - Description: Sets the pin number for the Clear (all-delete) button.

● reader.arrange(map);
  - Argument: char 2D array [4][4]
  - Description: Registers the character map of the physical keypad layout into the library.


[2. Initialization Function (Must call exactly once at the end of setup())]

● reader.begin();
  - Argument: None
  - Description: Automatically executes pinMode configurations and initial HIGH outputs at once based on the setup information.


[3. Execution Function (Always call inside loop())]

● reader.read(targetVariable);
  - Argument: String variable (A user-defined variable to store the output)
  - Description: Continuously scans the keypad at high speed in the background.
                 Returns 'true' only at the exact moment the Enter button is pressed to confirm input,
                 and writes the entered string into the passed String variable.

================================================================================
