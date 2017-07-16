#include "FakeTimeService.h"

static int theMinute;
static int theDay;
static WakeupCallback callback;
static int period;

void TimeService_Create(void)
{
    theMinute = TIME_UNKNOWN;
    theDay = TIME_UNKNOWN;
    callback = NULL;
    period = -1;
}

void TimeService_Destroy(void)
{
}

WakeupCallback FakeTimeService_GetAlarmCallback(void)
{
    return callback;
}

int FakeTimeService_GetAlarmPeriod(void)
{
    return period;
}

void TimeService_SetPeriodicAlarmInSeconds(int seconds, WakeupCallback cb)
{
    callback = cb;
    period = seconds;
}

void TimeService_CancelPeriodicAlarmInSeconds(int seconds, WakeupCallback cb)
{
    if(cb == callback && period == seconds){
        callback = NULL;
        period = 0;
    }

}

void TimeService_GetTime(Time* time)
{
    time->minuteOfDay = theMinute;
    time->dayOfWeek = theDay;
}



void FakeTimeService_SetMinute(int minute)
{
    theMinute = minute;
}

void FakeTimeService_SetDay(int day)
{
    theDay = day;
}


