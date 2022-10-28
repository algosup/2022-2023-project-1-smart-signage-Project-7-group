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

String message = "";

void loop(){
  unsigned long now = getTime();
  Date* date = timeToDate(now);
  
  // getError();
  int brightness = get_schedule_value(date);
  int ambientLight = getPhotoresistor();
  setIntensity(brightness, ambientLight);
  
  // if (now >= nextUplinkTime) {
  //   nextUplinkTime = getNextUplink(now, MESSAGING_PERIOD);
  //   char* message = generateMessage();
  //   sendHexMessage(message);
  //   error.type = NONE;
  // }  



  while (Debug.available() > 0) {
    char c = (char)Debug.read();
    message += c;
    if (c == '#') {
      message = "";
      Debug.flush();
    }
  }
  while (Lora.available() > 0) Debug.write(Lora.read());



  if (message == "send\n") {
    // getError();
    char* message = generateMessage();
    Debug.println("Sending...");
    sendHexMessage(message);
    free(message);
    error.type = NONE;
  }

  if (message == "3am\n") {
    setTime(1666918800 +7200);
    Debug.println("It is now 3AM");
  }
  if (message == "11am\n") {
    setTime(1666947600 +7200);
    Debug.println("It is now 11AM");
  }

  if (message == "0%\n") {
    brightnessFactor = 0;
    Debug.println((int)(brightness * brightnessFactor / 256));
    Debug.println("Factor at 0%");
  }
  if (message == "50%\n") {
    brightnessFactor = 64;
    Debug.println("Factor at 50%");
  }
  if (message == "100%\n") {
    brightnessFactor = 127;
    Debug.println("Factor at 100%");
  }

  if (message == "auto\n") {
    currentState = AUTOMATIC;
    Debug.println("Automatic mode");
  }
  if (message == "m50\n") {
    currentState = MANUAL;
    manualBrightness = 63;
    Debug.println("Manual mode at 50%");
  }
  if (message == "m100\n") {
    currentState = MANUAL;
    manualBrightness = 127;
    Debug.println("Manual mode at 100%");
  }

  if (message == "error\n") {
    error.type = LED;
    error.time = getTime();
    error.value = 69;
  }



  if (message.indexOf('\n') != -1) message = "";
  // Debug.print(getACSCurrent());
  // Debug.print(" ");
  // Debug.println(getPhotoresistor());
  free(date);
  delay(100);
}