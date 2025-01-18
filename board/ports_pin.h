#include <drv_gpio.h>

/* BEEP蜂鸣器针脚 */
#define BEEP_PIN GET_PIN(B, 12)
#define BEEP_RING PIN_LOW            // 响
#define BEEP_NO_RING PIN_HIGH        // 不响

/* LED 四灯针脚 */
/*
    *       *
    *       *               HPU(LOG)

*/

#define LED_LEFT_UP GET_PIN(A, 1)
#define LED_LEFT_DOWN GET_PIN(A, 2)
#define LED_RIGHT_UP GET_PIN(A, 3)
#define LED_RIGHT_DOWN GET_PIN(A, 4)

/* 按键 */
#define KEY_UP GET_PIN(B, 1)
#define KEY_DOWN GET_PIN(B, 15)

/* 光敏 */
#define LIGHT_SENSOR GET_PIN(B, 13)

/* OLED */
#define SDA GET_PIN(B,9)
#define SCL GET_PIN(B,8)

/* SG90 */
#define SG90_PWM GET_PIN(A, 0)