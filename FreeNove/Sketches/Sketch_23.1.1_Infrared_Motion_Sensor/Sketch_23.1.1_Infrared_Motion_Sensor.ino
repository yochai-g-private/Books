/*
  Sketch 23.1.1
  Infrared Motion Sensor

  modified 2016/8/17
  by http://www.freenove.com
*/

int sensorPin = 11; // the number of the infrared motion sensor pin
int ledPin = 12;    // the number of the LED pin

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT_PULLUP);  // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as output
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
