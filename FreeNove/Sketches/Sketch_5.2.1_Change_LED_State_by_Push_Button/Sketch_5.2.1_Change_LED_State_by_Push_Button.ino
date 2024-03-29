/*
  Sketch 5.2.1
  Change LED State by Push Button

  modified 2016/5/13
  by http://www.freenove.com
*/

int buttonPin = 7;//6; // the number of the push button pin
int ledPin = 9;//8;     // the number of the LED pin
boolean isLighting = false; // define a variable to save the state of LED

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);  // set push button pin into input mode
  pinMode(ledPin, OUTPUT);    // set LED pin into output mode
//  for(int cnt = 10; cnt; )
//  {
//    reverseLED();
//    delay(5000);
//  }
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {        // if the button is pressed
    delay(10);    // delay for a certain time to skip the bounce
    if (digitalRead(buttonPin) == LOW) {      // confirm again if the button is pressed
      reverseLED();                           // reverse LED
      while (digitalRead(buttonPin) == LOW);  // wait for releasing
      delay(10);  // delay for a certain time to skip bounce when the button is released
    }
  }
}

void reverseLED() {
  if (isLighting) {             // if LED is lighting,
    digitalWrite(ledPin, LOW);  // switch off LED
    isLighting = false;         // store the state of LED
    Serial.println("LOW");
  }
  else {                        // if LED is off,
    digitalWrite(ledPin, HIGH); // switch LED
    isLighting = true;          // store the state of LED
    Serial.println("HIGH");
  }
}
