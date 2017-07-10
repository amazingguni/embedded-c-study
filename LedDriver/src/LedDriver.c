#include <stdint.h>
#include "LedDriver.h"
#include "RuntimeError.h"

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED = 16};

static uint16_t * ledsAddress;
static uint16_t ledsImage;

static int isLedOutOfBounds(int ledNumber){
	return (ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

static void updateHardware(void)
{
	*ledsAddress = ledsImage;
}

void LedDriver_Create(uint16_t * address)
{
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
	return 1 << (ledNumber - 1);
}

static void setLedImageBit(int ledNumber){
	ledsImage |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOn(int ledNumber)
{
	if(isLedOutOfBounds(ledNumber)){
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
		return;
	}
	setLedImageBit(ledNumber);
	updateHardware();
}

void LedDriver_TurnAllOn(void)
{
	ledsImage = ALL_LEDS_ON;
	updateHardware();
}

static void clearLedImageBit(int ledNumber)
{
	ledsImage &= ~(convertLedNumberToBit(ledNumber));
}

void LedDriver_TurnOff(int ledNumber)
{
	if(isLedOutOfBounds(ledNumber)){
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
		return;
	}
	clearLedImageBit(ledNumber);
	updateHardware();
}

void LedDriver_TurnAllOff(void){
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}

int LedDriver_IsOn(int ledNumber){
	if(isLedOutOfBounds(ledNumber))
		return 0;
	return ledsImage & (convertLedNumberToBit(ledNumber));
}

int LedDriver_IsOff(int ledNumber){
	return !LedDriver_IsOn(ledNumber);
}

void LedDriver_Destroy(void)
{
}
