#include "led.h"

static int init_LED(){
    rt_pin_mode(LED_LEFT_UP, PIN_MODE_OUTPUT);
    rt_pin_mode(LED_LEFT_DOWN, PIN_MODE_OUTPUT);
    rt_pin_mode(LED_RIGHT_UP, PIN_MODE_OUTPUT);
    rt_pin_mode(LED_RIGHT_DOWN, PIN_MODE_OUTPUT);

    return RT_EOK;
}
#ifndef BSP_USING_KEY_LED
INIT_DEVICE_EXPORT(init_LED);
#endif