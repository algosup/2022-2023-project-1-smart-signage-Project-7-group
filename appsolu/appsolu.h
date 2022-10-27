#ifndef APPSOLU
#define APPSOLU

enum State {
  AUTOMATIC,
  MANUAL,
};

enum ErrorType {
  NONE,
  POWER = 2,
  LED,
  INTERNAL,
  DESYNC,
};

struct Error {
  ErrorType type;
  long time;
  char value;
};

struct Date {
  char day;
  char hours;
  char minutes;
  char seconds;
};



/*
The time period is defined by how many messages we are allowed per day.
For a payload of 12 bytes on DR0 in Europe, this is 20 messages a day.

This can be calculated here:
https://avbentem.github.io/airtime-calculator/ttn/eu868

We allow ourselves to bypass the fair use policy by having
24 messages a day instead of only 22.
*/
const unsigned long PERIOD = 3600; // 1 hour => 24msg/day


char currentBrightness; // LED brightness in %
char brightnessfactor = 1;
State currentState = AUTOMATIC;
struct Error error;
long lastTimeOverflowCheck;
unsigned long nextUplinkTime;
unsigned long startTime; // Time at which the program started (unix timestamp) (time = millis() / 1000 + startTime)

#endif