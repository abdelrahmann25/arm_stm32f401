#include "StdTypes.h"
#include "LED.h"
#include "LED_cfg.h"
#include "Scheduler_cfg.h"
#include "SYSTICK_cfg.h"
#include "RCC.h"
#include "SWITCH.h"
#include "SWITCH_cfg.h"

void ToggleRedLED_250MS_runnable(void)
{
  static u8 ledState = LED_SET_ON;
  if (ledState == LED_SET_ON)
  {
    LED_setStatus(LED_Red, LED_SET_OFF);
    ledState = LED_SET_OFF;
  }
  else
  {
    LED_setStatus(LED_Red, LED_SET_ON);
    ledState = LED_SET_ON;
  }
}
void ToggleGreenLED_500MS_runnable(void)
{
  static u8 ledState = LED_SET_ON;
  if (ledState == LED_SET_ON)
  {
    LED_setStatus(LED_Green, LED_SET_OFF);
    ledState = LED_SET_OFF;
  }
  else
  {
    LED_setStatus(LED_Green, LED_SET_ON);
    ledState = LED_SET_ON;
  }
}
void ToggleYellowLED_1000MS_runnable(void)
{
  static u8 ledState = LED_SET_ON;
  if (ledState == LED_SET_ON)
  {
    LED_setStatus(LED_Yellow, LED_SET_OFF);
    ledState = LED_SET_OFF;
  }
  else
  {
    LED_setStatus(LED_Yellow, LED_SET_ON);
    ledState = LED_SET_ON;
  }
}