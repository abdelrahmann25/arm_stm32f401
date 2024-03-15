/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/

#include "SWITCH.h"
#include "SWITCH_cfg.h"
#include "GPIO.h"

/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/

#define IS_SWITCH_NAME_VALID(SW) (SW < _NUM_OF_SWITCHES)


// Validation macro for switch modes
#define IS_VALID_SWITCH_MODE(mode) \
    (((mode) == SWITCH_MODE_NOPULL) || \
     ((mode) == SWITCH_MODE_PULLUP) || \
     ((mode) == SWITCH_MODE_PULLDOWN))

// Validation macro for switch active states
#define IS_VALID_SWITCH_STATE(state) \
    (((state) == SWITCH_ACTIVE_STATE_HIGH) || \
     ((state) == SWITCH_ACTIVE_STATE_LOW))


/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/



/********************************************************************************************************/
/************************************************Variables***********************************************/
/********************************************************************************************************/

extern const SWITCH_switchConfig_t Switches[(u32)_NUM_OF_SWITCHES];

/********************************************************************************************************/
/*****************************************Static Functions Prototype*************************************/
/********************************************************************************************************/



/********************************************************************************************************/
/*********************************************APIs Implementation****************************************/
/********************************************************************************************************/


void SWITCH_init(void)
{
    GPIO_pinConfig_t Loc_switch;

    Loc_switch.speed = GPIO_MEDIUM_SPEED;
    
    for(int i = 0; i < (u32)_NUM_OF_SWITCHES; i++)
    {
        Loc_switch.port = Switches[i].port;
        Loc_switch.pin = Switches[i].pin;
        Loc_switch.mode = Switches[i].mode;

        GPIO_initPin(&Loc_switch);
    }
}

SWITCH_errorState_t SWITCH_getState(u32 switchName, u32 *state)
{
    SWITCH_errorState_t errorState = SWITCH_Nok;
    u32 pinRead = 0;

    if(state == NULLPTR)
    {
        errorState = SWITCH_NullPtr;
    }
    else if(!IS_SWITCH_NAME_VALID(switchName))
    {
        errorState = SWITCH_InvalidSwitchName;
    }
    else
    {
        errorState = SWITCH_Ok;
        GPIO_getPin(Switches[switchName].port, Switches[switchName].pin, &pinRead);

        pinRead = pinRead ^ ((Switches[switchName].mode & SWITCH_MODE_PULLUP) >> 5);
        *state = pinRead;
    }

    return errorState;
}