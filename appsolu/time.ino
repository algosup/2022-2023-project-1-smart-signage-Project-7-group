void setTime(unsigned long receivedTime) {
  startTime = receivedTime - millis()/1000;
}

unsigned long getTime() {
  return startTime + millis()/1000;
}

// Due to the precision of millis(), the internal clock with reset after 50 days
// We call this function regularly to prevent that issue
void correctTimeOverflow() {
  if (millis() < lastTimeOverflowCheck) {
    // Overflow occured
    startTime += 4294967; // 2^32/1000
  }
  lastTimeOverflowCheck = millis();
}

Date* timeToDate(unsigned long time) {
  unsigned long remain = time; // in seconds
  int seconds = remain % 60;

  remain = (remain - seconds) / 60; // in minutes
  int minutes = remain % 60;

  remain = (remain - minutes) / 60; // in hours
  int hours = remain % 24;

  remain = (remain - hours) / 24; // in days
  int day = remain % 7;
  
  Date* date = (Date*) malloc(sizeof(Date));
  date->seconds = (char) seconds;
  date->minutes = (char) minutes;
  date->hours = (char) hours;
  date->day = (char) day;
  return date;
}