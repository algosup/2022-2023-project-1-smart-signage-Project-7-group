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

void setIntensity(int brightness, int ambientLight) {
  // TODO: LERP values + brightnessCurve
  int value = brightness*4;
  // Debug.print("Set brightness to ");
  // Debug.println(value);
  analogWrite(PWMPin, value);
}