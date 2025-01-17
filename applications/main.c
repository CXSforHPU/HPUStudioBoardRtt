/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-03-08     obito0       first version
 * 2023-12-03     Meco Man     support nano version
 */

#include <board.h>
#include <rtthread.h>
#include <ports_pin.h>

#ifdef BSP_USING_LED
#include <led.h>
#endif

int main(void)
{
    /* 设置流水灯 */

  


    while (1)
    {
        #ifndef BSP_USING_KEY_LED
        rt_pin_write(LED_RIGHT_DOWN,PIN_LOW);
        rt_pin_write(LED_RIGHT_UP,PIN_LOW);
        rt_pin_write(LED_LEFT_DOWN,PIN_LOW);
        rt_pin_write(LED_LEFT_UP,PIN_LOW);
        
        rt_thread_mdelay(500);
        
        rt_pin_write(LED_RIGHT_DOWN,PIN_HIGH);
        rt_pin_write(LED_RIGHT_UP,PIN_HIGH);
        rt_pin_write(LED_LEFT_DOWN,PIN_HIGH);
        rt_pin_write(LED_LEFT_UP,PIN_HIGH);

        rt_thread_mdelay(500);
        #endif
    }
}
