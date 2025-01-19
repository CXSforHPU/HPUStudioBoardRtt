
#include <sg90.h>


/* 初始化 */
rt_err_t sg90_init(sg90_cfg_t cfg)
{
       /* 查找设备 */
    cfg->name = (struct rt_device_pwm *)rt_device_find(PWM_DEV_NAME);
    if (cfg->name == RT_NULL)
    {
        rt_kprintf("pwm sample run failed! can't find %s device!\n", cfg->name);
        return RT_ERROR;
    }
        /* 设置PWM周期和脉冲宽度默认值 */
    rt_pwm_set(cfg->name, cfg->channel, cfg->period, cfg->pulse);
    /* 使能设备 */
    rt_pwm_enable(cfg->name, cfg->channel);
    
    return RT_EOK;

}

rt_err_t sg90_deinit(sg90_cfg_t cfg)
{
    if (cfg->name != RT_NULL)
    {
        /* code */
        rt_pwm_disable(cfg->name, cfg->channel);
        
        return RT_EOK;
    }
    
    return RT_ERROR;

}

rt_err_t sg90_set_angle(sg90_cfg_t cfg,float angle)
{

    if (cfg->name == RT_NULL)
    {
        rt_kprintf("not find the sg90 device\n");

        return RT_ERROR;
    }
    else{
        
        cfg->pulse = ANGEL2PULSE(angle);
        rt_pwm_set(cfg->name, cfg->channel,cfg->period, cfg->pulse);

        return RT_EOK;

    }

}

rt_err_t sg90_control(sg90_cfg_t cfg,int angle,int dir)
{

    if (cfg->dir == SG90_CLOCKWISE)
    {
        cfg->pulse += ANGEL2PULSE(angle);
        if (cfg->pulse > MAX_ANGLE)
        {
            cfg->pulse = MAX_ANGLE;
        }
        return RT_EOK;
    }
    else if (cfg->dir == SG90_ANTICLOCKWISE)
    {
        cfg->pulse -= ANGEL2PULSE(angle);
        if (cfg->pulse < MIN_ANGLE)
        {
            cfg->pulse = MIN_ANGLE;
        }
        return RT_EOK;
    }

    return RT_ERROR;
}

rt_err_t sg90_get(sg90_cfg_t cfg)
{
    if (cfg->name == RT_NULL)
    {
        rt_kprintf("not find the sg90 device\n");

        return RT_ERROR;
    }
    
    rt_kprintf("sg90 get device is %s\n",PWM_DEV_NAME);
    rt_kprintf("sg90 get channel is %d\n",cfg->channel);
    switch (cfg->dir)
    {
    case SG90_ANTICLOCKWISE:
        rt_kprintf("sg90 get angle is %s\n","ANTICLOCKWISE");
        break;
        
    case SG90_CLOCKWISE:
        rt_kprintf("sg90 get angle is %s\n","CLOCKWISE");
        break;
    
    default:
        break;
    }
    
    rt_kprintf("sg90 get pulse is %d\n",cfg->pulse);
    rt_kprintf("sg90 get period is %d\n",cfg->period);
    rt_kprintf("sg90 get angle is %d\n",PULSE2ANGEL(cfg->pulse));
    

    return RT_EOK;

}

// 
/* 导出到 msh 命令列表中 */
// INIT_DEVICE_EXPORT(init_sg90);