#include "appsolu.h"

#define Debug Serial
HardwareSerial Lora(A3, A2);

void setup(){
  initschedule();
  error.type = NONE;
  
  Debug.begin(9600);
  while (!Debug) {}
  Lora.begin(9600);
  while (!Lora) {}

  Debug.println("Connecting...");
  connectLora();

  Debug.println("Ready!");
}

void loop(){
  unsigned long now = getTime();
  Date* date = timeToDate(now);
  
  getError();
  int brightness = get_schedule_value(date);
  int ambientLight = getPhotoresistor();
  setIntensity(brightness, ambientLight);
  
  if (now >= nextUplinkTime) {
    nextUplinkTime = getNextUplink(now, MESSAGING_PERIOD);
    char* message = generateMessage();
    sendHexMessage(message);
  }  
}