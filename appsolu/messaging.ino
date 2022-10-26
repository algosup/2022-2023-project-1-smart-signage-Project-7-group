void connectLora() {
  Serial.println("AT+JOIN");
  delay(5000);
  Serial.flush();
}

void sendHexMessage(char message[]) {
  Serial.print("AT+MSGHEX=\"");
  int length = sizeof(message)/sizeof(message[0]);
  for (int i = 0; i < length; i++) {
    int v = message[i];
    int d = v / 16;
    Serial.write('0'+d);
    int u = v % 16;
    Serial.write('0'+u);
  }
  Serial.println("\"");
}

String receiveMessage() {
  if (Serial.available() == 0) return "";
  String message = Serial.readStringUntil('\n');
  if (message[message.length()-1] != '\r') return ""; // Not CR+NL ending
  message[message.length()-1] = '\n';
  return message;
}