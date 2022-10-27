unsigned long getNextUplink(unsigned long now, unsigned long period) {
  unsigned long x = now / period;
  unsigned long n = roundl(x) + 1;
  unsigned long nextUplink = n * period;
  return nextUplink;
}

char* generateMessage() {
  if (error.type != 0) {
    char *message = (char*) malloc(7 * sizeof(char));
    message[0] = (char) 6;
    message[1] = (char) error.type;
    message[2] = (char) (error.time >> 24);
    message[3] = (char) ((error.time >> 16)%256);
    message[4] = (char) ((error.time >> 8)%256);
    message[5] = (char) (error.time%256);
    message[6] = (char) error.value;
    return message;
  }

  char photosensor = 0;//getphotresistor();

  char *message = (char*) malloc(4 * sizeof(char));
  message[0] = (char) 3;
  message[1] = currentState == AUTOMATIC ? 0x00 : 0x01;
  message[2] = currentBrightness;
  message[3] = photosensor;
  return message;
}