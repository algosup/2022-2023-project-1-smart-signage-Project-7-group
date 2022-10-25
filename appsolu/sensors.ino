int SampleAcs = analogRead(A5);
int SampleZMCT = analogRead(A6);

int getACSCurrent(){
 int AcsValue=0;
  AcsValue = (2.5 - (analogRead(A5) * (5.0 / 1024.0)) )/0.185; //Reading Current
  Serial.println("ACS:");
  Serial.print(AcsValue);
  return AcsValue;
}
int getZMCTCurrent(){
  float ZMCTValue = analogRead(A6); //Number between 0 & 1023
  Serial.println("ZMCT:");
  Serial.print(ZMCTValue);
  return ZMCTValue;
  }

int getphotresistor(){
  float photoValue = analogRead(A8); //Number between 0 & 1023
  Serial.println("Light:");
  Serial.print(photoValue);
  return photoValue;
}
