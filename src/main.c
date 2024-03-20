#include "StdTypes.h"
#include "LED.h"
#include "LED_cfg.h"
#include "Scheduler_cfg.h"
#include "SYSTICK_cfg.h"
#include "RCC.h"
#include "SWITCH.h"
#include "SWITCH_cfg.h"




int main(void)
{
  RCC_enableAHB1_Peripheral(AHB1_GPIOA);
  LED_init();
  SWITCH_init();
  LED_setStatus(LED_Yellow, LED_SET_ON);
  LED_setStatus(LED_Green, LED_SET_ON);
  LED_setStatus(LED_Red, LED_SET_ON);
  LED_setStatus(LED_Yellow, LED_SET_OFF);
  LED_setStatus(LED_Green, LED_SET_OFF);
  LED_setStatus(LED_Red, LED_SET_OFF);

  Sched_init();
  Sched_start();

  // u32 switchState = SWITCH_RELEASED;
  //   u8 ledState = LED_SET_ON;
  //   u8 switchPressed = 1;
  // while (1)
  // {
    

  //   SWITCH_getState(SWITCH_ALARM, &switchState);
  //   while(switchState == SWITCH_PRESSED)
  //   {
  //     LED_setStatus(LED_Red, LED_SET_ON);
  //     SWITCH_getState(SWITCH_ALARM, &switchState);
  //     switchPressed = 1;
  //   }
  //    LED_setStatus(LED_Red, LED_SET_OFF);
  //   // if (ledState == LED_SET_ON && switchPressed == 1)
  //   // {
  //   //   LED_setStatus(LED_Red, LED_SET_OFF);
  //   //   ledState = LED_SET_OFF;
  //   //   switchPressed = 0;
  //   // }
  //   // else if(ledState == LED_SET_OFF && switchPressed == 1)
  //   // {
  //   //   LED_setStatus(LED_Red, LED_SET_ON);
  //   //   ledState = LED_SET_ON;
  //   // }
  // }
  return 0;
}
