void connectLora() {
  Lora.println("AT+JOIN");
  // receiveMessage(); // +JOIN: Start
  // receiveMessage(); // +JOIN: NORMAL
  // String message = reiceiveMessage();
  // if ()

  // TODO: Finish above code to parse incomming messages and remove below code
  delay(10000);
  flush();
}

void sendHexMessage(char* message) {
  Lora.print("AT+MSGHEX=\"");
  int size = message[0];
  for (int i = 1; i < size+1; i++) {
    int v = message[i];
    int d = v / 16;
    Lora.write('0'+d);
    int u = v % 16;
    Lora.write('0'+u);
  }
  Lora.println("\"");
  free(message);
}

String receiveMessage() {
  String message = "";
  while (true) {
    while (Lora.available() == 0) {}
    char c = Lora.read();
    if (c == '\n') break;
    message += c;
  }
  if (message[message.length()-1] != '\r') return ""; // Not CR+NL ending
  message[message.length()-1] = '\n';
  return message;
}

void flush() {
  while (Lora.available() > 0) Lora.read();
}