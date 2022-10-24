char SCHEDULE [7] [144];

void initschedule()
{
    int d,m;
    for(d = 0; d < 7;d++)
    {
        for (m = 0; m < 144;m++)
        {
            if (m < 36)
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

void change_period(bool daymask [8], char hour, char minute,char hourend,char minuteend,char value)
{
    int m,d;
    minute = floor(minute/10);
    minuteend = floor(minuteend/10);
    int end = minuteend + hourend * 6;
    for(d = 0; d < 7;d++)
    {
        if(daymask[d])
        {
            for (m = minute + hour * 6; m < end; m++)
            {
                SCHEDULE[d][m] = value;
            }
        }
    }    
}

char get_value(char day, char hour, char minute)
{
    return SCHEDULE[day][char(hour*6 + floor(minute/10))];
}