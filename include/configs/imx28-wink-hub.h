/* SPDX-License-Identifier: GPL-2.0+ */

#ifndef __CONFIGS_IMX28WINKHUB_H__
#define __CONFIGS_IMX28WINKHUB_H__

/* Memory configuration */
#define PHYS_SDRAM_1			0x40000000	/* Base address */
#define PHYS_SDRAM_1_SIZE		0x04000000	/* 64 MB of RAM */
#define CFG_SYS_SDRAM_BASE		PHYS_SDRAM_1

/* The rest of the configuration is shared */
#include <configs/mxs.h>

#endif /* __CONFIGS_IMX28WINKHUB_H__ */
