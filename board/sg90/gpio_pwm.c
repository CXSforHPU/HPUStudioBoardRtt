#include <beep.h>
#include <ports_pin.h>


/* 比如可以在main.c中使用，此为无源蜂鸣器使用，有源的一样，就发声频率不能控制 */
void sg90_thread(void)
{
    /* 先初始化 beep */
    /* 第一个参数为蜂鸣器驱动引脚号，可查看drv_gpio.c，或使用GET_PIN()宏得到，如下面为PA1010脚 */
    /* 第二个参数为蜂鸣器关断时引脚电平，PIN_LOW或PIN_HIGH */
    /* 对无源蜂鸣器来说，这2个参数在初始化函数内部都没有使用到 */
    beep_init(SG90_PWM, PIN_HIGH);

    /* 鸣叫3声，周期20ms，鸣叫占空比50%，默认发声频率 */
    beep(10, 20, 95, 0);

    rt_thread_mdelay(8000);

    /* 鸣叫3声，周期20ms，鸣叫占空比70%，2500Hz */
    beep(10, 20, 93, 0);

    rt_thread_mdelay(8000);

    /* 鸣叫10声，周期800ms，鸣叫占空比10%，上一次的发声频率，即2500Hz */
    beep(10, 20,90,0);

    rt_thread_mdelay(5000);

    /* 鸣叫20声，周期20ms，鸣叫占空比50%，2000Hz */
    beep(10, 20, 88, 0);

    rt_thread_mdelay(5000);

    /* 中途打断，停止鸣叫 */
    beep_stop();
    
    beep_deinit();
}

void sg90_thread_entry(void *parameter)
{
    rt_thread_t thread = rt_thread_create("beep", sg90_thread, RT_NULL, PKG_BEEP_THREAD_STACK_SIZE, PKG_BEEP_THREAD_PRIORITY, PKG_BEEP_THREAD_TIMESLICE);
    if (thread != RT_NULL)
    {
        rt_thread_startup(thread);
    }
}

MSH_CMD_EXPORT(sg90_thread_entry, sg90_thread_entry)