#include "sg90.h"


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
