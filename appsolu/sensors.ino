int getACSCurrent(){
  // float AcsValue = (2.5 - (analogRead(A5) * (5.0 / 1024.0)) )/0.185; //Reading Current
  int AcsValue = analogRead(currentSensorPin);
  return AcsValue;
}

int getZMCTCurrent(){
  int ZMCTValue = analogRead(currentTransformerPin); //Number between 0 & 1023
  return ZMCTValue;
}

int getPhotoresistor(){
  int photoValue = analogRead(photoresistorPin); //Number between 0 & 1023
  return photoValue;
}

int curve(int ambientLight) {
  return ambientLight;
}

void setIntensity(int brightness, int ambientLight) {
  // int value = brightness*4;
  int value;
  if (currentState == AUTOMATIC) {
    // value = (brightness * brightnessFactor * curve(ambientLight) / 128/128/128) * 512;
    value = brightness * brightnessFactor;
    if (value >= 1024) value = 1023;
  } else {
    manualBrightness = brightness;
    value = brightness;
  }
  // Debug.print("Set brightness to ");
  // Debug.println(value);
  analogWrite(PWMPin, value);
}