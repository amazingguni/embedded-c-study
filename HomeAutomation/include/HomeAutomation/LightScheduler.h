#ifndef D_LightScheduler_H
#define D_LightScheduler_H

#include "TimeService.h"
#include "LightController.h"

/**********************************************************
 *
 * LightScheduler is responsible for ...
 *
 **********************************************************/

enum 
{
    UNUSED = -1,
    MAX_EVENTS = 128,
};

enum
{
    LS_OK = 0,
    LS_TOO_MANY_EVENTS = 1,
    LS_ID_OUT_OF_BOUNDS = 2
};

typedef enum Event {
    TURN_ON=1, TURN_OFF=2
} Event;

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);

void LightScheduler_Wakeup(void);
int LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay);
int LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay);
void LightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay);
#endif  /* D_FakeLightScheduler_H */
