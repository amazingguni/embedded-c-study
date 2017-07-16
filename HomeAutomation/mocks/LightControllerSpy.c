#include <memory.h>
#include "LightControllerSpy.h"

static int lastId;
static int lastState;
static int lights[MAX_LIGHTS];

void LightController_Create(void)
{
    lastId = LIGHT_ID_UNKNOWN;
    lastState = LIGHT_STATE_UNKNOWN;
    memset(lights, LIGHT_STATE_UNKNOWN, sizeof lights);
}

void LightController_Destroy(void){

}

void LightController_TurnOn(int id)
{
    lastId = id;
    lastState = LIGHT_ON;
    lights[id] = LIGHT_ON;
}

void LightController_TurnOff(int id)
{
    lastId = id;
    lastState = LIGHT_OFF;
    lights[id] = LIGHT_OFF;
}

int LightControllerSpy_GetLastId(void)
{
    return lastId;
}

int LightControllerSpy_GetLastState(void)
{
    return lastState;
}

int LightControllerSpy_GetLightState(int id){
    return lights[id];
}
