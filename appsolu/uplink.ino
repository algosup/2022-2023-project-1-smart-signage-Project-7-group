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

    char *message = (char*) malloc(sizeof(char));
    message[0] = error.type;
    message[1] = (char) (error.time >> 24);
    message[2] = (char) ((error.time >> 16)%256);
    message[3] = (char) ((error.time >> 8)%256);
    message[4] = (char) (error.time%256);
    message[5] = error.value;
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