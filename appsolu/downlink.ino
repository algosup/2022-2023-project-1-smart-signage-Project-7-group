

void interpretdownlink(String message)
{
  String bin = stob(message);
  switch(message[1])
  {
    case '0': 
      break;
    case '1':
      currentState = MANUAL;
      break;
    case '2':
      currentState = AUTOMATIC;
      break;
    case '3':
      brightnessfactor = binstrtoc(bin.substring(8,15));
      break; 
    case '4':
      setTime(binstrtoul(bin.substring(8)));
      break;
    case '5':
    { 
      bool daymask[8];
      for (char i = 8; i < 16; i++)
      {
        daymask[i-8] = bin[i] != '0';
      }
      char hour = binstrtoc(bin.substring(16,20));
      char minute = binstrtoc(bin.substring(21,23));
      char endhour = binstrtoc(bin.substring(24,28));
      char endminute = binstrtoc(bin.substring(29,32));
      char brightness = binstrtoc(bin.substring(32,39));
      change_period(daymask,hour,minute*10,endhour,endminute*10,brightness);
      break;
    }
    case '6': break; //TODO: Groups
    default: break;
 }
}

char* hex_char_to_bin(char c)
{
  switch(c)
  {
    case '0': return "0000";
    case '1': return "0001";
    case '2': return "0010";
    case '3': return "0011";
    case '4': return "0100";
    case '5': return "0101";
    case '6': return "0110";
    case '7': return "0111";
    case '8': return "1000";
    case '9': return "1001";
    case 'A': return "1010";
    case 'B': return "1011";
    case 'C': return "1100";
    case 'D': return "1101";
    case 'E': return "1110";
    case 'F': return "1111";
  }
}

String stob(String hex)
{
  String bin;
  for(unsigned i = 0; i != hex.length(); ++i)
    bin += hex_char_to_bin(hex[i]);
  return bin;
}

char binstrtoc(String bins)
{
  char t = 0;
  for(char i = 0; i != bins.length(); i++)
  {
    if (bins[i]== '1') t++;
    t *=2;
  }
  return t;
}

char binstrtoul(String bins)
{
  unsigned long t = 0;
  for(char i = 0; i != bins.length(); i++)
  {
    if (bins[i]== '1') t++;
    t *=2;
  }
  return t;
}