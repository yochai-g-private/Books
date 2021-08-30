/*
  Sketch 23.1.1
  Infrared Motion Sensor

  modified 2016/8/17
  by http://www.freenove.com
*/

int sensorPin = A4; // the number of the infrared motion sensor pin
int ledPin = A1;    // the number of the LED pin

void setup() {
  pinMode(sensorPin, INPUT_PULLUP);  // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as output
  pinMode(A9,OUTPUT);
  digitalWrite(A9, HIGH);
  Serial.begin(115200);    // Open serial monitor at 9600 baud to see ping results.
}

int status = -1;

void loop() {
  // Turn on or off LED according to Infrared Motion Sensor
  int on = digitalRead(sensorPin);

  if(on == status)
      return;

  Serial.println(on);
  
  status = on;
  
  digitalWrite(ledPin, on);
  
  delay(1000);              // wait for a second
}
