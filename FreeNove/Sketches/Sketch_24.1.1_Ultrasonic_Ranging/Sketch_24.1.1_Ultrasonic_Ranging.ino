/*
  Sketch 24.1.1
  Ultrasonic Ranging
  
  modified 2016/6/5
  by http://www.freenove.com
*/

#define trigPin A5 //12 // define TrigPin
#define echoPin A6 //11 // define EchoPin.
#define MAX_DISTANCE 400 // Maximum sensor distance is rated at 400-500cm.
// define the timeOut according to the maximum range. timeOut= 2*MAX_DISTANCE /100 /340 *1000000 = MAX_DISTANCE*58.8
float timeOut = MAX_DISTANCE * 60; 
int soundVelocity = 340; // define sound speed=340m/s

void setup() {
  pinMode(trigPin,OUTPUT);// set trigPin to output mode
  pinMode(echoPin,INPUT); // set echoPin to input mode
  pinMode(A9,OUTPUT);
  digitalWrite(A9, HIGH);
  Serial.begin(115200);    // Open serial monitor at 9600 baud to see ping results.
  Serial.println("Started!");
}

void loop() {
  delay(500); // Wait 100ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
#if 1
  enum { MIND=130, MAXD=160, N_TIMES=4 };
  static int in_range = 0;

  int dist = getSonar();

  Serial.println(dist);
  if(dist >= MIND && dist <= MAXD)
  {
    in_range++;
    
    if(in_range < N_TIMES)
      return;

    Serial.println("*** BELL BELL BELL ***");
  }
  else
  {
    in_range = 0;
  }
#else
  Serial.print("Ping: ");
  Serial.print(getSonar()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
#endif
}

float getSonar() {
  unsigned long pingTime;
  float distance;
  digitalWrite(trigPin, HIGH); // make trigPin output high level lasting for 10μs to triger HC_SR04,
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTime = pulseIn(echoPin, HIGH, timeOut); // Wait HC-SR04 returning to the high level and measure out this waitting time
  distance = (float)pingTime * soundVelocity / 2 / 10000; // calculate the distance according to the time
  return distance; // return the distance value
}
