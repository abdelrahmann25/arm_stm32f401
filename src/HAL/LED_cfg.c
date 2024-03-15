
#include "GPIO.h"
#include "LED.h"
#include "LED_cfg.h"

const LED_ledconfig_t LEDs[(u32)_NUM_OF_LEDS] = 
{
    [LED_ALARM] =
    {
        .port = GPIO_A,
        .pin = GPIO_PIN0,
        .connection = LED_CONNECTION_FORWARD,
        .defaultState = LED_SET_OFF
    },
    [LED_MOTOR] =
    {
        .port = GPIO_A,
        .pin = GPIO_PIN1,
        .connection = LED_CONNECTION_FORWARD,
        .defaultState = LED_SET_OFF
    }
};

