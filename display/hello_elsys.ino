/*

This example code is part of the public domain 

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  // set up the number of columns and rows on the LCD 
  lcd.begin(16, 2);
  
  // Print a message to the LCD.
  lcd.print("Hello ELSYS");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("Welcome to IDE8!!");
}

void loop() {
    // do nothing
}