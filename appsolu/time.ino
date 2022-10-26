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
  int remain = time; // in seconds
  char seconds = remain % 60;

  remain = (remain - seconds) / 60; // in minutes
  char minutes = remain % 60;

  remain = (remain - minutes) / 24; // in hours
  char hours = remain % 24;

  remain = (remain - hours) / 7; // in days
  char days = remain;

  Date date = {days, hours, minutes, seconds};
  return &date;
}