#define PIN A0

HardwareSerial DEBUG(A3, A2); // Debug: connection with computer
const long PERIOD = 30000; // 30 sec

long nextUpdate;

long getNextUpdate(long now, long period) {
  long x = now / period;
  long n = roundl(x) + 1;
  long newUpdate = n * period;
  return newUpdate;
}



// TODO: Implement correctly
char* generateMessage() {
  return NULL;
}

void processMessage(String message) {
  DEBUG.print(message);
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