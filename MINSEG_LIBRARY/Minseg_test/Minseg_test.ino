#include <MINSEG.h>

// create object for it
Minseg robot; 


void setup() {
  // initialize the serial port for communications
  Serial.begin(115200);
  robot.setupHardware(); // sets up all of the stock hardware on the MinSeg 

  // temp - for debugging
  pinMode(8,OUTPUT);
}

void loop() {

  // temp - for debugging
  delay(500);
  Serial.println(robot.encCnt);
  //minseg.toggleLED();
  digitalWrite(8,HIGH);
  delay(500);
  Serial.println(robot.encCnt);
  digitalWrite(8,LOW);
}
