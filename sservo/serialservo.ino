//Eneter a number between 0-180 and hit Enter to set the angle of the Servo attached to pin 9

#include <Servo.h>// Importing the Servo lybrary


Servo myServo;//Variable refering to the servo lybrary. It has all the function that the lybrary has.


String inString = "";    // string to hold input


void setup() {
    myServo.attach(9);//Relating the servo to the pin 9
    Serial.begin(9600);//Initialting the serial port
    delay(1000);
    Serial.println("Staring IDE8 ServoSerial");
    Serial.println("Enter a number between 0-180 and hit Enter");
}

void loop() {
// Read serial input:
    while (Serial.available() > 0) {
        int inChar = Serial.read();
        if (isDigit(inChar)) {
        // convert the incoming byte to a char
        // and add it to the string:
        inString += (char)inChar;
        }
        // if you get a newline, print the string,
        // then the string's value:
        if (inChar == '\r') {
        Serial.print("Angle:");
        Serial.println(inString.toInt());
        myServo.write(inString.toInt());
        //Serial.print("String: ");
        //Serial.println(inString);
        // clear the string for new input:
        inString = "";
        }
    }
}
