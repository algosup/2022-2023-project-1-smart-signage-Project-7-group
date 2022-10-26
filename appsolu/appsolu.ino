#include "appsolu.h"

// HardwareSerial DEBUG(A3, A2); // Debug: connection with computer

void setup(){
  delay(5000);

  initschedule();
  long testTimestamp = 1666666666;

  error.type = INTERNAL;
  error.time = testTimestamp;
  error.value = 0x01;
  
  Serial.begin(9600);
  while (!Serial) {}

  connectLora();
  char* message = generateMessage();
  for (int i=0; i<6; i++) {
    char c = message[i];
    Serial.print((int)c);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println("=====");
  free(message); // IMPORTANT
}

void loop(){
}