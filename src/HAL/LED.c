/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/

#include "LED.h"
#include "LED_cfg.h"
#include "GPIO.h"

/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/

#define IS_LED_NAME_VALID(LED) (LED < _NUM_OF_LEDS)

#define IS_LED_STATE_VALID(STATE) ((STATE == LED_SET_ON) || (STATE == LED_SET_OFF))


/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/



/********************************************************************************************************/
/************************************************Variables***********************************************/
/********************************************************************************************************/

extern const LED_ledconfig_t LEDs[(u8)_NUM_OF_LEDS];

/********************************************************************************************************/
/*****************************************Static Functions Prototype*************************************/
/********************************************************************************************************/



/********************************************************************************************************/
/*********************************************APIs Implementation****************************************/
/********************************************************************************************************/


void LED_init(void)
{
    GPIO_pinConfig_t led;
    led.mode = GPIO_MODE_OUTPUT_PUSHPULL_NOPULL;
    led.speed = GPIO_VERY_HIGH_SPEED;

    for(int i = 0; i < (u8)_NUM_OF_LEDS; i++)
    {
        led.pin = LEDs[i].pin;
        led.port = LEDs[i].port;

        GPIO_initPin(&led);
        
        GPIO_setPin(LEDs[i].port, LEDs[i].pin, LEDs[i].connection ^ LEDs[i].defaultState);
    }
}

LED_errorState_t LED_setStatus(u8 ledName, u32 state)
{
    LED_errorState_t errorState = LED_Nok;
    if(!IS_LED_NAME_VALID(ledName))
    {
        errorState = LED_InvalidLEDName;
    }
    else if(!IS_LED_STATE_VALID(state))
    {
        errorState = LED_InvalidLEDState;
    }
    else
    {
        errorState = LED_Ok;
        GPIO_setPin(LEDs[ledName].port, LEDs[ledName].pin, LEDs[ledName].connection ^ state);
    }

    return errorState;
}

LED_errorState_t LED_getState(u8 ledName, u32 *state)
{
    LED_errorState_t errorState = LED_Nok;
    if(state == NULLPTR)
    {
        errorState = LED_NullPtr;
    }
    else if(!IS_LED_NAME_VALID(ledName))
    {
        errorState = LED_InvalidLEDName;
    }
    else
    {
        errorState = LED_Ok;
        GPIO_getPin(LEDs[ledName].port, LEDs[ledName].pin, state);
    }

    return errorState;
}