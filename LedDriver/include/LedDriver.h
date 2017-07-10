void LedDriver_Create(uint16_t* address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOff(void);
int LedDriver_IsOn(int ledNumber);
int LedDriver_IsOff(int ledNumber);
void LedDriver_Destroy(void);