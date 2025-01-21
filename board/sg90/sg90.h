#include <rtthread.h>
#include <rtdevice.h>

/*
//于kconfig 进行了定义，可在menconfig中进行修改。若不想从menuconfig修改，则解除该注释即可

#define PWM_DEV_NAME                "pwm2"          //PWM设备名称
#define PWM_DEV_CHANNEL             1               //PWM通道
#define MAX_ANGLE                   2500000         //最大角度 250000 ns
#define MIN_ANGLE                   500000          // 最小角度 0 ns
#define SG90_MAX_ANGLE             180              // 舵机最大角度

*/


#define SG90_ANTICLOCKWISE          1       /* PWM顺时针 */
#define SG90_CLOCKWISE              0       /* PWM逆时针 */
#define ANGEL2PULSE(angle) (int)(angle*(MAX_ANGLE-MIN_ANGLE)/SG90_MAX_ANGLE+MIN_ANGLE) /*定义旋转角度对应的PWM脉冲宽度值*/
#define PULSE2ANGEL(pulse) (int)((pulse-MIN_ANGLE)*SG90_MAX_ANGLE/(MAX_ANGLE-MIN_ANGLE))

typedef struct sg90_cfg
{   
    int period; /* 周期,单位是纳秒 */
    int dir;    /* PWM脉冲宽度值的增减方向 @ SG90_CLOCKWISE,SG90_ANTICLOCKWISE */
    int pulse;  /* PWM脉冲宽度值，单位为纳秒ns */
    int channel; /* PWM通道 */
    struct rt_device_pwm *name;
} sg90_cfg,*sg90_cfg_t;

/* 初始化结构体 */
extern  sg90_cfg my_sg90_config;


rt_err_t sg90_init(sg90_cfg_t cfg);
rt_err_t sg90_deinit(sg90_cfg_t cfg);
rt_err_t sg90_set_angle(sg90_cfg_t cfg,float angle);
rt_err_t sg90_control(sg90_cfg_t cfg,int angle,int dir);
rt_err_t sg90_get(sg90_cfg_t cfg);
int sg90_get_angle(sg90_cfg_t cfg);
int sg90_get_pulse(sg90_cfg_t cfg);
