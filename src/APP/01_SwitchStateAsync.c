#include "StdTypes.h"
#include "LED.h"
#include "LED_cfg.h"
#include "Scheduler_cfg.h"
#include "SYSTICK_cfg.h"
#include "RCC.h"
#include "SWITCH.h"
#include "SWITCH_cfg.h"


void GetSwitchState_50MS_runnable(void)
{
  if(SWITCH_getStateAsync(SWITCH_ALARM) == SWITCH_PRESSED)
  {
    LED_setStatus(LED_Green, LED_SET_ON);
  }
  if(SWITCH_getStateAsync(SWITCH_ALARM) == SWITCH_RELEASED)
  {
    LED_setStatus(LED_Green, LED_SET_OFF);
  }
}
