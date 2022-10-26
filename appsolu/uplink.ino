unsigned long getNextUplink(unsigned long now, unsigned long period) {
  unsigned long x = now / period;
  unsigned long n = roundl(x) + 1;
  unsigned long newUplink = n * period;
  return newUplink;
}

char* generateMessage() {
  if (error.type != 0) {
    Serial.println("Error");

    Serial.print(error.type);
    Serial.print(" ");
    Serial.print((error.time >> 24)%256);
    Serial.print(" ");
    Serial.print((error.time >> 16)%256);
    Serial.print(" ");
    Serial.print((error.time >> 8)%256);
    Serial.print(" ");
    Serial.print((error.time)%256);
    Serial.print(" ");
    Serial.println((int)error.value);

    char message[] {
      error.type,
      error.time >> 24,
      error.time >> 16,
      error.time >> 8,
      error.time,
      error.value,
    };
    return message;
  }

  Serial.println("OK");
  char photosensor = 0;//getphotresistor();
  char message[] = {
    currentState == AUTOMATIC ? 0x00 : 0x01,
    currentBrightness,
    photosensor    
  };
  return message;
}