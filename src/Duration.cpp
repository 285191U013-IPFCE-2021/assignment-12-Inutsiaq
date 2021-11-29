#include "../include/Duration.h"
#include <assert.h>

int Duration::getDuration()
{
    return time;
}

void Duration::setAlarm(int t)
{
    assert(t > time);
    alarmHasBeenSet = true;
    alarm = t;
}

Duration::Duration()
{
    time = 0;
}

Duration::Duration(int t)
{
    assert(t>=0);
    time = t;
}

bool Duration::tick()
{
    assert(time >= 0);
    time++;
    if (alarmHasBeenSet == true)
        checkAndUpdateAlarm();
    else 
    return false;
}

bool Duration::tick(int dt)
{
    assert(dt >= 0);
    time += dt;
    if (alarmHasBeenSet == true)
        checkAndUpdateAlarm();
    else 
    return false;
}

bool Duration::checkAndUpdateAlarm() 
// this function is made to check if the alarm has been set, 
{
    if (time >= alarm) // if time has surpassed alarms value it resets alarms value and returns true, meaning that alarm was reset
    {
        alarm = 1000000000;
        alarmHasBeenSet = false;
        return true;
    }
    else 
    return false; // it the alarm has been set, but alarms value is still greater than time it returns false 
}

bool Duration::CheckAlarm()
{
    return alarmHasBeenSet;
}



