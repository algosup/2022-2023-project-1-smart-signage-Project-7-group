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
  // }  

  while (Debug.available() > 0) {
    char c += (char)Debug.read();
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
  }

  if (message == "off\n") {
    Debug.println("LEDs turned OFF");
    analogWrite(PWMPin, 0);
  }
  // if (message == String("on\n")) {
  //   Debug.println("LEDs turned ON");
  //   analogWrite(PWMPin, 127);
  // }

  if (message == "3am\n") {
    setTime(1666918800 +7200);
    // Date* date = timeToDate(1666918800 +7200); // Fri Oct 28 2022 03:00:00 GMT+0200
    // int brightness = get_schedule_value(date);
    // int ambientLight = getPhotoresistor();
    Debug.println("It is now 3AM");
    // setIntensity(brightness, ambientLight);
  }
  if (message == "11am\n") {
    setTime(1666947600 +7200);
    // Date* date = timeToDate(1666947600 +7200); // Thu Oct 27 2022 11:00:00 GMT+0200
    // TODO: Fix date conversion (hours)
    // int brightness = 0;//get_schedule_value(date);
    // int ambientLight = getPhotoresistor();
    Debug.println("It is now 11AM");
    // setIntensity(brightness, ambientLight);
  }

  if (message == "0%\n") {
    brightnessFactor = 0;
    Debug.print("Factor at 0%");
  }
  if (message == "100%\n") {
    brightnessFactor = 127;
  Debug.print("Factor at 100%");
  }
  if (message == "200%\n") {
    brightnessFactor = 255;
    Debug.print("Factor at 200%");
  }

  if (message == "auto\n") {
    currentState = AUTOMATIC;
    Debug.print("Automatic mode");
  }
  if (message == "manual50\n") {
    currentState = MANUAL;
    Debug.print("Manual mode at 50%");
  }
  if (message == "manual150\n") {
    currentState = MANUAL;
    Debug.print("Manual mode at 150%");
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
  delay(100);
}