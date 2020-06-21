/*
  Sketch 21.1.1
  Infrared Remote Control

  modified 2016/8/17
  by http://www.freenove.com
*/

#include <IRremote.h>

int RECV_PIN = 2;        // Infrared receiving pin
IRrecv irrecv(RECV_PIN); // Create a class object used to receive class
decode_results results; // Create a decoding results class object

void setup()
{
  Serial.begin(9600); // Initialize the serial port and set the baud rate to 9600
  Serial.println("UNO is ready!!!");  // Print the string "UNO is ready!"
  irrecv.enableIRIn(); // Start the receiver
}

#define PRINT_RESULT(fld, hex)  \
  Serial.print(#fld "=");\
  Serial.print(results.fld, (hex) ? HEX : DEC);\
  Serial.print("; ")
  
void loop() {
  //Serial.print("->");
  if (irrecv.decode(&results)) {  // Waiting for decoding
    if(results.value != 0xFFFFFFFF)
    {
      //Serial.println();
      PRINT_RESULT(decode_type, false);
      //PRINT_RESULT(address,     false);
      PRINT_RESULT(value,       false);
      //PRINT_RESULT(bits,        false);
      //PRINT_RESULT(overflow,    false);
      Serial.println();
    }
    irrecv.resume(); // Receive the next value
  }
  delay(500);
}
