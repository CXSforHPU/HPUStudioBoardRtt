/*
 * Copyright (c) 2006-2024 RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2024-08-16     zhujiale     first version
 */

#ifndef _DRIVERS_MMC_RT_SDHCI_PLTFM_H
#define _DRIVERS_MMC_RT_SDHCI_PLTFM_H
#include <rtthread.h>
#include <drivers/core/dm.h>
#include <drivers/ofw.h>
#include <drivers/platform.h>
#include <drivers/clk.h>
#include "sdhci.h"

struct rt_sdhci_pltfm_data
{
    const struct rt_sdhci_ops *ops;
    unsigned int            quirks;
    unsigned int            quirks2;
};

struct rt_sdhci_pltfm_host
{
    struct rt_clk *clk;
    unsigned int clock;
    rt_uint64_t  xfer_mode_shadow;

    unsigned long private[];
};
void            rt_sdhci_get_property(struct rt_platform_device *pdev);

static inline void sdhci_get_of_property(struct rt_platform_device *pdev)
{
    return rt_sdhci_get_property(pdev);
}
extern struct   rt_sdhci_host *rt_sdhci_pltfm_init(struct rt_platform_device     *pdev,
                                           const struct rt_sdhci_pltfm_data *pdata,
                                           size_t                         priv_size);
extern void               rt_sdhci_pltfm_free(struct rt_platform_device *pdev);

extern int      rt_sdhci_pltfm_init_and_add_host(struct rt_platform_device     *pdev,
                                          const struct rt_sdhci_pltfm_data *pdata,
                                          size_t                         priv_size);
extern void     rt_sdhci_pltfm_remove(struct rt_platform_device *pdev);

extern unsigned int rt_sdhci_pltfm_clk_get_max_clock(struct rt_sdhci_host *host);

static inline void *sdhci_pltfm_priv(struct rt_sdhci_pltfm_host *host)
{
    return host->private;
}

static inline int sdhci_pltfm_suspend(struct rt_device *dev)
{
    return 0;
}
static inline int sdhci_pltfm_resume(struct rt_device *dev)
{
    return 0;
}
#endif