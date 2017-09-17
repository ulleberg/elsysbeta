String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.println("8888888 8888888b.  8888888888 .d8888b. "); 
  Serial.println("  888   888   Y88b 888       d88P  Y88b"); 
  Serial.println("  888   888    888 888       Y88b. d88P"); 
  Serial.println("  888   888    888 8888888    'Y88888' "); 
  Serial.println("  888   888    888 888       .d8P  Y8b."); 
  Serial.println("  888   888    888 888       888    888"); 
  Serial.println("  888   888  .d88P 888       Y88b  d88P"); 
  Serial.println("8888888 8888888P'  8888888888 'Y8888P' "); 
  Serial.println("");
  Serial.println("");
  Serial.println(" .d8888b.                   d8b          888      8888888888         888              "); 
  Serial.println("d88P  Y88b                  Y8P          888      888                888              "); 
  Serial.println("Y88b.                                    888      888                888              "); 
  Serial.println("  Y888b.    .d88b.  888d888 888  8888b.  888      8888888    .d8888b 88888b.   .d88b. "); 
  Serial.println("     Y88b. d8P  Y8b 888P    888      88b 888      888       d88P     888  88b d88  88b"); 
  Serial.println("       888 88888888 888     888 .d888888 888      888       888      888  888 888  888"); 
  Serial.println("Y88b  d88P Y8b.     888     888 888  888 888      888       Y88b.    888  888 Y88..88P");
  Serial.println(" 'Y8888P'   'Y8888  888     888  Y888888 888      8888888888 'Y8888P 888  888  'Y88P' "); 
  Serial.println("");
  Serial.println("Start Typing");
  Serial.println("");


    inputString.reserve(10);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    //Serial.println(inputString);
    Serial.print(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    if (inChar == '\r') {
        Serial.println("");
    }
    stringComplete = true;
  }
}