#include "scheduling.h"
#include <iostream>
#include <limits.h>

void initschedule(char _schedule [7][1440] = nullptr)
{
    if (_schedule)
    {
        int d,m;
        for(d = 0; d < 7;d++)
        {
            for (m = 0; m < 1440;m++)
            {
                if (m < 360)
                {
                    SCHEDULE[d][m] = 0;
                }
                else
                {
                    SCHEDULE[d][m] = 128;
                }
            }
        }
    }
    else
    {
        memcpy(_schedule,SCHEDULE,7*1440*sizeof(char));
    }

}

void change_period(bool daymask [8], char hour, char minute,char hourend,char minuteend,char value)
{
    int m,d;
    int end = minuteend + hourend * 60;
    for(d = 0; d < 7;d++)
    {
        if(daymask[d])
        {
            for (m = minute + hour * 60; m < end; m++)
            {
                SCHEDULE[d][m] = value;
            }
        }
    }    
}

char get_value(char day, char hour, char minute)
{
    return SCHEDULE[day][hour*60 + minute];
}