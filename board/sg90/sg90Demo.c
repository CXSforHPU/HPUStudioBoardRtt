#include "sg90.h"


/* 初始化结构体 */
static sg90_cfg my_sg90_config = {
    .period = 20000000, // 20ms 周期
    .dir = SG90_CLOCKWISE,
    .pulse = MAX_ANGLE, // 1.5ms 脉冲宽度
    .name = RT_NULL,
    .channel = PWM_DEV_CHANNEL,
};

static int set_angle(int argc,char **argv)
{
    
    sg90_cfg_t cfg =&my_sg90_config;
    
    
    if (cfg->name==RT_NULL)
    {
        /* code */
        sg90_init(cfg);
    }
        

    if(argc==2)
    {
        sg90_set_angle(cfg,atoi(argv[1]));
        sg90_get(cfg);
    }
    
    return 0;
}

MSH_CMD_EXPORT(set_angle,set angle);
