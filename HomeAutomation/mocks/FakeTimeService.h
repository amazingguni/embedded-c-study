#ifndef D_FakeTimeService_H
#define D_FakeTimeService_H

#include "TimeService.h"

/**********************************************************
 *
 * FakeTimeService is responsible for ...
 *
 **********************************************************/

enum {TIME_UNKNOWN = -1};

void FakeTimeService_SetMinute(int minute);
void FakeTimeService_SetDay(int day);

WakeupCallback FakeTimeService_GetAlarmCallback(void);
int FakeTimeService_GetAlarmPeriod(void);
#endif  /* D_FakeFakeTimeService_H */
