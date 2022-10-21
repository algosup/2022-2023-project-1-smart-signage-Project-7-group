#ifndef SCHEDULING
#define SCHEDULING

char SCHEDULE [7] [1440];

void initschedule(char _schedule [7][1440] = nullptr);

void change_period(bool daymask [8], char hour, char minute,char hourend,char minuteend,char value);

char get_value(char day, char hour, char minute);

#endif