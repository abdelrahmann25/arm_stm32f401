#include "StdTypes.h"
#include "LED.h"
#include "LED_cfg.h"
#include "Scheduler_cfg.h"
#include "SYSTICK_cfg.h"
#include "RCC.h"
#include "SWITCH.h"
#include "SWITCH_cfg.h"

typedef enum{
  SM_Red,
  SM_Yellow,
  SM_Green
}StateMachine_trafficLeds_t;

void TrafficLights_1000MS_runnable(void)
{
  static StateMachine_trafficLeds_t TrafficState = SM_Red;
  static StateMachine_trafficLeds_t PrevTrafficState = SM_Red;
  static u32 counter = 0;
  
  switch (TrafficState)
  {
  case SM_Red:
    LED_setStatus(LED_Red, LED_SET_ON);
    LED_setStatus(LED_Green, LED_SET_OFF);
    LED_setStatus(LED_Yellow, LED_SET_OFF);
    counter++;
    if(counter == 5)
    {
      TrafficState = SM_Yellow;
      PrevTrafficState = SM_Red;
      counter = 0;
    }
    break;

  case SM_Yellow:
    LED_setStatus(LED_Red, LED_SET_OFF);
    LED_setStatus(LED_Green, LED_SET_OFF);
    LED_setStatus(LED_Yellow, LED_SET_ON);
    counter++;
    if(counter == 2)
    {
      if(PrevTrafficState == SM_Red)
      {
        TrafficState = SM_Green;
      }
      else if(PrevTrafficState == SM_Green)
      {
        TrafficState = SM_Red;
      }
      PrevTrafficState = SM_Yellow;
      counter = 0;
    }
    break;

    case SM_Green:
    LED_setStatus(LED_Red, LED_SET_OFF);
    LED_setStatus(LED_Green, LED_SET_ON);
    LED_setStatus(LED_Yellow, LED_SET_OFF);
    counter++;
    if(counter == 5)
    {
      TrafficState = SM_Yellow;
      PrevTrafficState = SM_Green;
      counter = 0;
    }
    break;
  default:
    break;
  }
}