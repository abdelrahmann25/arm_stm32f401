
#include "GPIO.h"
#include "LED.h"
#include "LED_cfg.h"

const LED_ledconfig_t LEDs[(u32)_NUM_OF_LEDS] = 
{
    [LED_Red] =
    {
        .port = GPIO_A,
        .pin = GPIO_PIN0,
        .connection = LED_CONNECTION_FORWARD,
        .defaultState = LED_SET_OFF
    },
    [LED_Green] =
    {
        .port = GPIO_A,
        .pin = GPIO_PIN2,
        .connection = LED_CONNECTION_FORWARD,
        .defaultState = LED_SET_OFF
    },
    [LED_Yellow] =
    {
        .port = GPIO_A,
        .pin = GPIO_PIN4,
        .connection = LED_CONNECTION_FORWARD,
        .defaultState = LED_SET_OFF
    }
};

