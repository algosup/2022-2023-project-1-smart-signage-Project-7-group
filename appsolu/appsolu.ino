#include "appsolu.h"

#define Debug Serial
HardwareSerial Lora(A3, A2);

void setup(){
  delay(5000);

  initschedule();
  error.type = NONE;
  
  Debug.begin(9600);
  while (!Debug) {}
  Lora.begin(9600);
  while (!Lora) {}

  connectLora();

  Debug.println("start");
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