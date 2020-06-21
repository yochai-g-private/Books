/*******
 
 All the resources for this project:
 http://randomnerdtutorials.com/

*******/


int smokeA0 = A0;
// Your threshold value
int sensorThres = 400;

void setup() {

  pinMode(smokeA0, INPUT);

  Serial.begin(9600);
}

void loop() {
 
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value

  delay(100);
 
}
